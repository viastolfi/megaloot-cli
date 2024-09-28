#!/bin/bash

echo "Make necessary dir"
mkdir bin obj

echo "Compile"
make clean
make

clear
./bin/exe
