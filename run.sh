#! /usr/bin/env bash

INIT_DIR=$PWD

echo "******* Using the very basic CMake setup *******"
mkdir build
cd build
cmake ..
make 
./basic_visitor_pattern 
cd $INIT_DIR 
rm -rf build

echo
echo "******* Using thevery basic Make setup *******"
make
./basic_visitor_pattern 
make clean