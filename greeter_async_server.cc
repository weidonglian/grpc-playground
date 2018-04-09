/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <memory>
#include <iostream>
#include <string>
#include <thread>

#include <grpcpp/grpcpp.h>
#include <grpc/support/log.h>
#include <sstream>

#include "helloworld.grpc.pb.h"
#include "call_data.hpp"

using grpc::Server;
using grpc::ServerAsyncResponseWriter;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerCompletionQueue;
using grpc::Status;
using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::Greeter;

// Is this thread-safe? You can create multiple clients to access the same server.
// Then the GreeterServiceImpl will be called in multiple pool threads. Thus we need
// to protect the resources. We can use atomic variable or a mutex to protect them.
int message_id = 0;

struct AsyncCallSayHello {
  AsyncCallSayHello(Greeter::AsyncService *service, ServerCompletionQueue *cq, void* tag) :
      ctx_(), request_(), reply_(), tag_(tag), responder_(&ctx_) {
    service->RequestSayHello(&ctx_, &request_, &responder_, cq, cq, tag);
  }

  void operator()() {
    // The actual processing.
    std::ostringstream oss;
    oss << "ThreadId:" << std::this_thread::get_id() << " and message id:" << message_id++ << " Hello "
        << request_.name();
    reply_.set_message(oss.str());
    std::this_thread::sleep_for(std::chrono::seconds(4));
    // And we are done! Let the gRPC runtime know we've finished, using the
    // memory address of this instance as the uniquely identifying tag for
    // the event.
    responder_.Finish(reply_, Status::OK, tag_);
  }

 private:
  ServerContext ctx_;
  HelloRequest request_;
  HelloReply reply_;
  void* tag_;
  ServerAsyncResponseWriter<HelloReply> responder_;
};

class ServerImpl final {
 public:
  ~ServerImpl() {
    server_->Shutdown();
    // Always shutdown the completion queue after the server.
    cq_->Shutdown();
  }

  // There is no shutdown handling in this code.
  void Run() {
    std::string server_address("0.0.0.0:50051");

    ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service_" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *asynchronous* service.
    builder.RegisterService(&service_);
    // Get hold of the completion queue used for the asynchronous communication
    // with the gRPC runtime.
    cq_ = builder.AddCompletionQueue();
    // Finally assemble the server.
    server_ = builder.BuildAndStart();
    std::cout << "Server listening on " << server_address << std::endl;
    // Proceed to the server's main loop.
    HandleRpcs();
  }

 private:

  // This can be run in multiple threads if needed.
  void HandleRpcs() {
    // Spawn a new CallData instance to serve new clients.
    make_call<Greeter::AsyncService, AsyncCallSayHello>(&service_, cq_.get());
    void *tag;  // uniquely identifies a request.
    bool ok;
    while (true) {
      // Block waiting to read the next event from the completion queue. The
      // event is uniquely identified by its tag, which in this case is the
      // memory address of a CallData instance.
      // The return value of Next should always be checked. This return value
      // tells us whether there is any kind of event or cq_ is shutting down.
      GPR_ASSERT(cq_->Next(&tag, &ok));
      GPR_ASSERT(ok);
      static_cast<CallData *>(tag)->Proceed();
    }
  }

  std::unique_ptr<ServerCompletionQueue> cq_;
  Greeter::AsyncService service_;
  std::unique_ptr<Server> server_;
};

int main(int argc, char **argv) {
  ServerImpl server;
  server.Run();

  return 0;
}
