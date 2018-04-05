Tested on Ubuntu 16.04 LTS

## How to build

* Install Protocol Buffers. [Here's instruction](https://github.com/google/protobuf/blob/master/src/README.md)

* Install gRPC. [Here's instruction](https://github.com/grpc/grpc/blob/master/INSTALL.md)

* Run grpc.sh to install protobuf and grpc on Ubuntu or Debian as below

```bash
mkdir grpc-build
cd grpc-build
../grpc.sh
```

* And build it

```bash
mkdir build
cd build
cmake ..
make
```
