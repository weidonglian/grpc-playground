sudo apt-get update
sudo apt-get install -y build-essential autoconf libtool git pkg-config curl automake libtool curl make g++ unzip
sudo apt-get clean

GRPC_RELEASE_TAG=v1.10.x
GRPC_DIR=$(pwd)
cd ${GRPC_DIR}
git clone -b ${GRPC_RELEASE_TAG} https://github.com/grpc/grpc ${GRPC_DIR} && \
cd ${GRPC_DIR} && \
    git submodule update --init && \
    echo "--- installing protobuf ---" && \
    cd third_party/protobuf && \
    ./autogen.sh && ./configure --enable-shared && \
    make -j$(nproc) && make -j$(nproc) check && sudo make install && sudo ldconfig && \
    echo "--- installing grpc ---" && \
    cd ${GRPC_DIR} && \
    make -j$(nproc) && sudo make install && sudo ldconfig
