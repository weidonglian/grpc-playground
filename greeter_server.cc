/*
 *
 * Copyright 2015, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <thread>
#include <sstream>

#ifdef BAZEL_BUILD
#include "examples/protos/helloworld.grpc.pb.h"
#else

#include "helloworld.grpc.pb.h"
#include "cmake-build-debug/proto-src/helloworld.grpc.pb.h"

#endif

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::GoodByeRequest;
using helloworld::GoodByeReply;
using helloworld::CheekRequest;
using helloworld::CheekReply;
using helloworld::Greeter;

// Is this thread-safe? You can create multiple clients to access the same server.
// Then the GreeterServiceImpl will be called in multiple pool threads. Thus we need
// to protect the resources. We can use atomic variable or a mutex to protect them.
int message_id = 0;

// Logic and data behind the server's behavior.
class GreeterServiceImpl final : public Greeter::Service {
  Status SayHello(ServerContext *context, const HelloRequest *request, HelloReply *response) override {
    std::ostringstream oss;
    oss << "ThreadId:" << std::this_thread::get_id() << " and message id:" << message_id++ << " Hello "
        << request->name();
    response->set_message(oss.str());
    std::this_thread::sleep_for(std::chrono::seconds(4));
    return Status::OK;
  }

  Status SayGoodBye(ServerContext *context, const GoodByeRequest *request, GoodByeReply *response) override {
    std::ostringstream oss;
    oss << "ThreadId:" << std::this_thread::get_id() << " and message id:" << message_id++ << " GoodBye "
        << request->name();
    response->set_message(oss.str());
    std::this_thread::sleep_for(std::chrono::seconds(4));
    return Status::OK;
  }

  Status KissCheek(ServerContext *context, const CheekRequest *request, CheekReply *response) override {
    std::ostringstream oss;
    oss << "ThreadId:" << std::this_thread::get_id() << " and message id:" << message_id++ << " KissCheek "
        << request->name();
    response->set_message(oss.str());
    std::this_thread::sleep_for(std::chrono::seconds(4));
    return Status::OK;
  }
};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  GreeterServiceImpl service;

  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char **argv) {
  RunServer();

  return 0;
}
