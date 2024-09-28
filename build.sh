#!/bin/bash

echo "Make necessary dir"
mkdir bin obj

echo "Compile"
make

clear
./bin/exe
