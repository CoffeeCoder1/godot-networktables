#!/bin/bash

mkdir -p build
cd build
cmake -G Ninja .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -j10 --config Release --target install
