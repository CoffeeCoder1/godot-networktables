#!/bin/bash

set -e
set -o pipefail

mkdir -p build
cd build

cmake -G Ninja .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=install/lib $1
cmake --build . -j10 --config Release --target install

unameOut="$(uname -s)"
case "${unameOut}" in
    Linux*)     machine=linux;;
    Darwin*)    machine=macos;;
    CYGWIN*)    machine=windows;;
    MINGW*)     machine=windows;;
    *)          machine="${unameOut}"
esac
echo ${machine}

if [ "${machine}" = "linux" ]; then
  strip install/lib/*
fi
