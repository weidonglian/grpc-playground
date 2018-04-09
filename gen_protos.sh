mkdir -p pbpy
python -m grpc_tools.protoc -I ./protos --python_out=./pbpy --grpc_python_out=./pbpy ./protos/helloworld.proto
