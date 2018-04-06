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

### Simple greeter service

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

Observer the thread id and message id and username. Each request may be run in any thread of the available pool managed
by grpc itself, thus you have to protect your shared or global resources, e.g. message_id in greeter_server.cc. You can
protect by atomic variable or a mutex depending on your actual use case. That says, you can make multiple requests by the
same channel, but you have to make sure the thread-safety yourself for access the shared resources.
