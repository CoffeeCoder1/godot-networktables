#!/bin/bash

cp LICENSE project/addons/networktables/

mkdir -p project/addons/networktables/bin
cp $1/*/lib/*.so    project/addons/networktables/bin/
cp $1/*/lib/*.dll   project/addons/networktables/bin/
cp $1/*/lib/*.dylib project/addons/networktables/bin/
