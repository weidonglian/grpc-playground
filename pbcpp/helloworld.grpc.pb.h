// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: helloworld.proto
// Original file comments:
// Copyright 2015 gRPC authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef GRPC_helloworld_2eproto__INCLUDED
#define GRPC_helloworld_2eproto__INCLUDED

#include "helloworld.pb.h"

#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace helloworld {

// The greeting service definition.
class Greeter final {
 public:
  static constexpr char const* service_full_name() {
    return "helloworld.Greeter";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // Sends a greeting
    virtual ::grpc::Status SayHello(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::helloworld::HelloReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::HelloReply>> AsyncSayHello(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::HelloReply>>(AsyncSayHelloRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::HelloReply>> PrepareAsyncSayHello(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::HelloReply>>(PrepareAsyncSayHelloRaw(context, request, cq));
    }
    virtual ::grpc::Status SayGoodBye(::grpc::ClientContext* context, const ::helloworld::GoodByeRequest& request, ::helloworld::GoodByeReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::GoodByeReply>> AsyncSayGoodBye(::grpc::ClientContext* context, const ::helloworld::GoodByeRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::GoodByeReply>>(AsyncSayGoodByeRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::GoodByeReply>> PrepareAsyncSayGoodBye(::grpc::ClientContext* context, const ::helloworld::GoodByeRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::GoodByeReply>>(PrepareAsyncSayGoodByeRaw(context, request, cq));
    }
    virtual ::grpc::Status KissCheek(::grpc::ClientContext* context, const ::helloworld::CheekRequest& request, ::helloworld::CheekReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::CheekReply>> AsyncKissCheek(::grpc::ClientContext* context, const ::helloworld::CheekRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::CheekReply>>(AsyncKissCheekRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::CheekReply>> PrepareAsyncKissCheek(::grpc::ClientContext* context, const ::helloworld::CheekRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::CheekReply>>(PrepareAsyncKissCheekRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::helloworld::FileChunk, ::helloworld::FileChunk>> ConvertFile(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::helloworld::FileChunk, ::helloworld::FileChunk>>(ConvertFileRaw(context));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::helloworld::FileChunk, ::helloworld::FileChunk>> AsyncConvertFile(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::helloworld::FileChunk, ::helloworld::FileChunk>>(AsyncConvertFileRaw(context, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::helloworld::FileChunk, ::helloworld::FileChunk>> PrepareAsyncConvertFile(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::helloworld::FileChunk, ::helloworld::FileChunk>>(PrepareAsyncConvertFileRaw(context, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::HelloReply>* AsyncSayHelloRaw(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::HelloReply>* PrepareAsyncSayHelloRaw(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::GoodByeReply>* AsyncSayGoodByeRaw(::grpc::ClientContext* context, const ::helloworld::GoodByeRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::GoodByeReply>* PrepareAsyncSayGoodByeRaw(::grpc::ClientContext* context, const ::helloworld::GoodByeRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::CheekReply>* AsyncKissCheekRaw(::grpc::ClientContext* context, const ::helloworld::CheekRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::CheekReply>* PrepareAsyncKissCheekRaw(::grpc::ClientContext* context, const ::helloworld::CheekRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientReaderWriterInterface< ::helloworld::FileChunk, ::helloworld::FileChunk>* ConvertFileRaw(::grpc::ClientContext* context) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::helloworld::FileChunk, ::helloworld::FileChunk>* AsyncConvertFileRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::helloworld::FileChunk, ::helloworld::FileChunk>* PrepareAsyncConvertFileRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status SayHello(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::helloworld::HelloReply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloworld::HelloReply>> AsyncSayHello(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloworld::HelloReply>>(AsyncSayHelloRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloworld::HelloReply>> PrepareAsyncSayHello(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloworld::HelloReply>>(PrepareAsyncSayHelloRaw(context, request, cq));
    }
    ::grpc::Status SayGoodBye(::grpc::ClientContext* context, const ::helloworld::GoodByeRequest& request, ::helloworld::GoodByeReply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloworld::GoodByeReply>> AsyncSayGoodBye(::grpc::ClientContext* context, const ::helloworld::GoodByeRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloworld::GoodByeReply>>(AsyncSayGoodByeRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloworld::GoodByeReply>> PrepareAsyncSayGoodBye(::grpc::ClientContext* context, const ::helloworld::GoodByeRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloworld::GoodByeReply>>(PrepareAsyncSayGoodByeRaw(context, request, cq));
    }
    ::grpc::Status KissCheek(::grpc::ClientContext* context, const ::helloworld::CheekRequest& request, ::helloworld::CheekReply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloworld::CheekReply>> AsyncKissCheek(::grpc::ClientContext* context, const ::helloworld::CheekRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloworld::CheekReply>>(AsyncKissCheekRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloworld::CheekReply>> PrepareAsyncKissCheek(::grpc::ClientContext* context, const ::helloworld::CheekRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloworld::CheekReply>>(PrepareAsyncKissCheekRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReaderWriter< ::helloworld::FileChunk, ::helloworld::FileChunk>> ConvertFile(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriter< ::helloworld::FileChunk, ::helloworld::FileChunk>>(ConvertFileRaw(context));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::helloworld::FileChunk, ::helloworld::FileChunk>> AsyncConvertFile(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::helloworld::FileChunk, ::helloworld::FileChunk>>(AsyncConvertFileRaw(context, cq, tag));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::helloworld::FileChunk, ::helloworld::FileChunk>> PrepareAsyncConvertFile(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::helloworld::FileChunk, ::helloworld::FileChunk>>(PrepareAsyncConvertFileRaw(context, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< ::helloworld::HelloReply>* AsyncSayHelloRaw(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::helloworld::HelloReply>* PrepareAsyncSayHelloRaw(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::helloworld::GoodByeReply>* AsyncSayGoodByeRaw(::grpc::ClientContext* context, const ::helloworld::GoodByeRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::helloworld::GoodByeReply>* PrepareAsyncSayGoodByeRaw(::grpc::ClientContext* context, const ::helloworld::GoodByeRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::helloworld::CheekReply>* AsyncKissCheekRaw(::grpc::ClientContext* context, const ::helloworld::CheekRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::helloworld::CheekReply>* PrepareAsyncKissCheekRaw(::grpc::ClientContext* context, const ::helloworld::CheekRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientReaderWriter< ::helloworld::FileChunk, ::helloworld::FileChunk>* ConvertFileRaw(::grpc::ClientContext* context) override;
    ::grpc::ClientAsyncReaderWriter< ::helloworld::FileChunk, ::helloworld::FileChunk>* AsyncConvertFileRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReaderWriter< ::helloworld::FileChunk, ::helloworld::FileChunk>* PrepareAsyncConvertFileRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_SayHello_;
    const ::grpc::internal::RpcMethod rpcmethod_SayGoodBye_;
    const ::grpc::internal::RpcMethod rpcmethod_KissCheek_;
    const ::grpc::internal::RpcMethod rpcmethod_ConvertFile_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // Sends a greeting
    virtual ::grpc::Status SayHello(::grpc::ServerContext* context, const ::helloworld::HelloRequest* request, ::helloworld::HelloReply* response);
    virtual ::grpc::Status SayGoodBye(::grpc::ServerContext* context, const ::helloworld::GoodByeRequest* request, ::helloworld::GoodByeReply* response);
    virtual ::grpc::Status KissCheek(::grpc::ServerContext* context, const ::helloworld::CheekRequest* request, ::helloworld::CheekReply* response);
    virtual ::grpc::Status ConvertFile(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::helloworld::FileChunk, ::helloworld::FileChunk>* stream);
  };
  template <class BaseClass>
  class WithAsyncMethod_SayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_SayHello() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_SayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayHello(::grpc::ServerContext* context, const ::helloworld::HelloRequest* request, ::helloworld::HelloReply* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSayHello(::grpc::ServerContext* context, ::helloworld::HelloRequest* request, ::grpc::ServerAsyncResponseWriter< ::helloworld::HelloReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_SayGoodBye : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_SayGoodBye() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_SayGoodBye() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayGoodBye(::grpc::ServerContext* context, const ::helloworld::GoodByeRequest* request, ::helloworld::GoodByeReply* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSayGoodBye(::grpc::ServerContext* context, ::helloworld::GoodByeRequest* request, ::grpc::ServerAsyncResponseWriter< ::helloworld::GoodByeReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_KissCheek : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_KissCheek() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_KissCheek() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status KissCheek(::grpc::ServerContext* context, const ::helloworld::CheekRequest* request, ::helloworld::CheekReply* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestKissCheek(::grpc::ServerContext* context, ::helloworld::CheekRequest* request, ::grpc::ServerAsyncResponseWriter< ::helloworld::CheekReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_ConvertFile : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_ConvertFile() {
      ::grpc::Service::MarkMethodAsync(3);
    }
    ~WithAsyncMethod_ConvertFile() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ConvertFile(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::helloworld::FileChunk, ::helloworld::FileChunk>* stream) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestConvertFile(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::helloworld::FileChunk, ::helloworld::FileChunk>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(3, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_SayHello<WithAsyncMethod_SayGoodBye<WithAsyncMethod_KissCheek<WithAsyncMethod_ConvertFile<Service > > > > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_SayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_SayHello() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_SayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayHello(::grpc::ServerContext* context, const ::helloworld::HelloRequest* request, ::helloworld::HelloReply* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_SayGoodBye : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_SayGoodBye() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_SayGoodBye() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SayGoodBye(::grpc::ServerContext* context, const ::helloworld::GoodByeRequest* request, ::helloworld::GoodByeReply* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_KissCheek : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_KissCheek() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_KissCheek() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status KissCheek(::grpc::ServerContext* context, const ::helloworld::CheekRequest* request, ::helloworld::CheekReply* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_ConvertFile : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_ConvertFile() {
      ::grpc::Service::MarkMethodGeneric(3);
    }
    ~WithGenericMethod_ConvertFile() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ConvertFile(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::helloworld::FileChunk, ::helloworld::FileChunk>* stream) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_SayHello : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_SayHello() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::helloworld::HelloRequest, ::helloworld::HelloReply>(std::bind(&WithStreamedUnaryMethod_SayHello<BaseClass>::StreamedSayHello, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_SayHello() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status SayHello(::grpc::ServerContext* context, const ::helloworld::HelloRequest* request, ::helloworld::HelloReply* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSayHello(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::helloworld::HelloRequest,::helloworld::HelloReply>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_SayGoodBye : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_SayGoodBye() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler< ::helloworld::GoodByeRequest, ::helloworld::GoodByeReply>(std::bind(&WithStreamedUnaryMethod_SayGoodBye<BaseClass>::StreamedSayGoodBye, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_SayGoodBye() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status SayGoodBye(::grpc::ServerContext* context, const ::helloworld::GoodByeRequest* request, ::helloworld::GoodByeReply* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSayGoodBye(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::helloworld::GoodByeRequest,::helloworld::GoodByeReply>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_KissCheek : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_KissCheek() {
      ::grpc::Service::MarkMethodStreamed(2,
        new ::grpc::internal::StreamedUnaryHandler< ::helloworld::CheekRequest, ::helloworld::CheekReply>(std::bind(&WithStreamedUnaryMethod_KissCheek<BaseClass>::StreamedKissCheek, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_KissCheek() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status KissCheek(::grpc::ServerContext* context, const ::helloworld::CheekRequest* request, ::helloworld::CheekReply* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedKissCheek(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::helloworld::CheekRequest,::helloworld::CheekReply>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_SayHello<WithStreamedUnaryMethod_SayGoodBye<WithStreamedUnaryMethod_KissCheek<Service > > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_SayHello<WithStreamedUnaryMethod_SayGoodBye<WithStreamedUnaryMethod_KissCheek<Service > > > StreamedService;
};

}  // namespace helloworld


#endif  // GRPC_helloworld_2eproto__INCLUDED
