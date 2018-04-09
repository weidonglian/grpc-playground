# Copyright 2015 gRPC authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
"""The Python implementation of the GRPC helloworld.Greeter client."""

import os, sys
import grpc

sys.path.append(os.path.join(os.path.dirname(__file__), "pbpy"))

from pbpy import helloworld_pb2
from pbpy import helloworld_pb2_grpc


def run():
    channel = grpc.insecure_channel('localhost:50051')
    stub = helloworld_pb2_grpc.GreeterStub(channel)
    resp_futures = []
    for i in range(100):
        print("before request {0}".format(i))
        resp_futures.append(stub.SayHello.future(helloworld_pb2.HelloRequest(name="py_async_client{0}".format(i))))
        print("after request {0}".format(i))

    for future in resp_futures:
        response = future.result()
        print("Greeter client received: " + response.message)


if __name__ == '__main__':
    run()
