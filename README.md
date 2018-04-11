Tested on Ubuntu 16.04 LTS

## How to build

* Run grpc.sh to install protobuf and grpc on Ubuntu or Debian as below. See [Protocol Buffers](https://github.com/google/protobuf/blob/master/src/README.md) and [gRPC](https://github.com/grpc/grpc/blob/master/INSTALL.md) on how it works. 

```bash
mkdir grpc-build
cd grpc-build
../grpc.sh
```

* Build grpc-playground

```bash
mkdir build
cd build
cmake ..
make
```

## How to play

These greeter examples are copied from google offical examples folder. 
I have done all kinds of adaptions in order to test and understand how
it works. 

The best way to learn grpc is to play around.    

### Sync greeter service

Start a terminal
```bash
./greeter_server
```

Start a new terminal
```bash
./greeter_client foo
```

Start again a new terminal
```bash
./greeter_client bar
```

Observer the thread id and message id and username. Each request may be run in any thread of the available thread 
pool managed by grpc itself, thus you have to protect your shared or global resources, e.g. message_id in 
greeter_server.cc.

- *foo* and *bar* stands for the client identifier name
- The *thread id* inciates the running thread in server for current *SayHello* call.
- *Message id* is the global unique id for all the clients. It should be made thread-safe in the real application, 
since they are accssed by mutiple threads at the same time. 

You can protect by atomic variable or a mutex depending on your actual use-case. That says, you can make multiple 
requests by the same channel, but you have to make sure the thread-safety yourself for access the shared resources.


### Async greeter service

The official example greeter_async_server.cc is a real toy example, but enough to understand how it works. You need 
to write a CallData for every grpc method of your defined service. 

- Register your async methods to the CompletionQueue in server side.
- Process your async methods when receiving the actual client side request.
- Notify the responder the finished result 
- Delete the corresponding CallData when client side successfully handle the finished result.

In real applications, we need to simply the process and make a wrapper or templating the base implementation.
`call_data.hpp` and `call_data.cpp` are simple wrappers based on the templating to simplify the definition, see 
`greeter_async_server.cc` to check how it works. 

### Streaming data

The streaming is defined in grpc by adding a `stream` keyword before the normal request and reply. 

- Can only stream the same message type.
- Bidirectional.
- Server can not initiate sending something to client. We can make a long-lived streaming between client and server 
to send data to client, e.g. push notifications to client.

### Inheritance or Polymorphism Support in Proto3

ProtoBuf does not support inheritance. The following will list all the possible alternatives.
I do not like the `extention` solutions. I did not list them here. You can check 
[here](http://www.indelible.org/ink/protobuf-polymorphism/) for more details.
  
It is not so easy to stream or send different messages in grpc. In protos, we can use
 
- oneof 
- any

##### Oneof

We can `stream` or `repeat` Command.  
 
```
syntax = "proto3";

message CommandDataA {
    string a = 1;
}

message CommandDataB {
    string b = 1;
}

message Command {
  CommandType type = 1;
  CommandName name = 2;
  oneof data {
    CommandDataA a = 3;
    CommandDataB b = 4;
  }
}
```

##### Any

```
message Command {
  CommandType type = 1; // Enum of the actual command type.
  Any data; // The actual binary buffer of the command
}

message CommandDataA {
  int32 a;
  ...
}

message CommandDataB{
  string b;
  ... 
}
```

We can then pack and unpack different `CommandDataX` into `Command.data`. We can peek the type when receive the `Command`, 
then determine which `CommandData` is used to unpack the `Any data` field.

##### Composition

If we just want a hierarchy not sending them by a list or by a single method, then we can use composition as below.

```
message Header {
  string type = 1;
  string id = 2;
}

message Message1 {
  Header header = 1;
  ...
}

message Message2 {
  Header header = 1;
  ...
}
```   

### Streaming File   

For the small file, probably we can easily handle by define a `Any file;` field, but for the large files, it is 
preferred to use streaming. We will check the availability of `info` field to start handling a new file and cache it 
somewhere in disk or database identified with the `uuid`. Then we can reference it by uuid in other grpc methods.

```
service BlobTransfer {
    rpc PutBlob (stream PutBlobRequest) returns (PutBlobResponse);
}

message PutBlobRequest {
    message BlobInfo {
         string uuid = 1; // unique identifier to identify the file.
         int64 size = 2; // the blob size in bytes.
    }
    message BlobChunk {
          bytes data = 1;
          int64 offset = 2;
    }
    
    oneof value {
        BlobInfo info = 1;
        BlobChunk chunk = 2;
    }
}
```