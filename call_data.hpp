//
// Created by lian on 4/8/18.
//

#ifndef GRPC_CMAKE_EXAMPLE_CALL_DATA_HPP
#define GRPC_CMAKE_EXAMPLE_CALL_DATA_HPP

#include <grpcpp/grpcpp.h>

class CallData {
 public:
  virtual void Proceed() = 0;
};

// Class encompasing the state and logic needed to serve a request.
template <typename TAsyncService, typename TAsyncCall>
class CallDataImpl : public CallData {
 public:
  // Take in the "service" instance (in this case representing an asynchronous
  // server) and the completion queue "cq" used for asynchronous communication
  // with the gRPC runtime.
  CallDataImpl(TAsyncService *service, grpc::ServerCompletionQueue *cq)
      : service_(service), callImpl_(service_, cq, this), cq_(cq), status_(PROCESS) {
  }

  void Proceed() final {
    if (status_ == PROCESS) {
      // Spawn a new CallData instance to serve new clients while we process
      // the one for this CallData. The instance will deallocate itself as
      // part of its FINISH state.
      status_ = FINISH;
      new CallDataImpl<TAsyncService, TAsyncCall>(service_, cq_);
      // Invoke the actual process function.
      callImpl_.Process();
    } else {
      GPR_ASSERT(status_ == FINISH);
      // Once in the FINISH state, deallocate ourselves (CallData).
      delete this;
    }
  }

 private:
  // Should only be deleted internally.
  ~CallDataImpl() = default;
  // Let's implement a tiny state machine with the following states.
  enum CallStatus { PROCESS, FINISH };
  // The means of communication with the gRPC runtime for an asynchronous
  // server.
  TAsyncService *service_;
  // The producer-consumer queue where for asynchronous server notifications.
  grpc::ServerCompletionQueue *cq_;
  // Actual implementation
  TAsyncCall callImpl_;
  // The current serving state.
  CallStatus status_;
};

template <typename TAsyncService, typename TAsyncCall>
CallData* make_call(TAsyncService *service, grpc::ServerCompletionQueue *cq) {
  return new CallDataImpl<TAsyncService, TAsyncCall>(service, cq);
}

#endif //GRPC_CMAKE_EXAMPLE_CALL_DATA_HPP
