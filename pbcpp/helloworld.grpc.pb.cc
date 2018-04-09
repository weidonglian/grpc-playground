// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: helloworld.proto

#include "helloworld.pb.h"
#include "helloworld.grpc.pb.h"

#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace helloworld {

static const char* Greeter_method_names[] = {
  "/helloworld.Greeter/SayHello",
  "/helloworld.Greeter/SayGoodBye",
  "/helloworld.Greeter/KissCheek",
};

std::unique_ptr< Greeter::Stub> Greeter::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Greeter::Stub> stub(new Greeter::Stub(channel));
  return stub;
}

Greeter::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_SayHello_(Greeter_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SayGoodBye_(Greeter_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_KissCheek_(Greeter_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Greeter::Stub::SayHello(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::helloworld::HelloReply* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_SayHello_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::helloworld::HelloReply>* Greeter::Stub::AsyncSayHelloRaw(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::helloworld::HelloReply>::Create(channel_.get(), cq, rpcmethod_SayHello_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::helloworld::HelloReply>* Greeter::Stub::PrepareAsyncSayHelloRaw(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::helloworld::HelloReply>::Create(channel_.get(), cq, rpcmethod_SayHello_, context, request, false);
}

::grpc::Status Greeter::Stub::SayGoodBye(::grpc::ClientContext* context, const ::helloworld::GoodByeRequest& request, ::helloworld::GoodByeReply* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_SayGoodBye_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::helloworld::GoodByeReply>* Greeter::Stub::AsyncSayGoodByeRaw(::grpc::ClientContext* context, const ::helloworld::GoodByeRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::helloworld::GoodByeReply>::Create(channel_.get(), cq, rpcmethod_SayGoodBye_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::helloworld::GoodByeReply>* Greeter::Stub::PrepareAsyncSayGoodByeRaw(::grpc::ClientContext* context, const ::helloworld::GoodByeRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::helloworld::GoodByeReply>::Create(channel_.get(), cq, rpcmethod_SayGoodBye_, context, request, false);
}

::grpc::Status Greeter::Stub::KissCheek(::grpc::ClientContext* context, const ::helloworld::CheekRequest& request, ::helloworld::CheekReply* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_KissCheek_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::helloworld::CheekReply>* Greeter::Stub::AsyncKissCheekRaw(::grpc::ClientContext* context, const ::helloworld::CheekRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::helloworld::CheekReply>::Create(channel_.get(), cq, rpcmethod_KissCheek_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::helloworld::CheekReply>* Greeter::Stub::PrepareAsyncKissCheekRaw(::grpc::ClientContext* context, const ::helloworld::CheekRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::helloworld::CheekReply>::Create(channel_.get(), cq, rpcmethod_KissCheek_, context, request, false);
}

Greeter::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Greeter_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Greeter::Service, ::helloworld::HelloRequest, ::helloworld::HelloReply>(
          std::mem_fn(&Greeter::Service::SayHello), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Greeter_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Greeter::Service, ::helloworld::GoodByeRequest, ::helloworld::GoodByeReply>(
          std::mem_fn(&Greeter::Service::SayGoodBye), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Greeter_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Greeter::Service, ::helloworld::CheekRequest, ::helloworld::CheekReply>(
          std::mem_fn(&Greeter::Service::KissCheek), this)));
}

Greeter::Service::~Service() {
}

::grpc::Status Greeter::Service::SayHello(::grpc::ServerContext* context, const ::helloworld::HelloRequest* request, ::helloworld::HelloReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Greeter::Service::SayGoodBye(::grpc::ServerContext* context, const ::helloworld::GoodByeRequest* request, ::helloworld::GoodByeReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Greeter::Service::KissCheek(::grpc::ServerContext* context, const ::helloworld::CheekRequest* request, ::helloworld::CheekReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace helloworld

