#!/bin/bash

echo "Compile"
make clean
make

clear
if [ ! -z $1 ];then
	if [ $1 == "dev" ];then
		./bin/exe dev
  elif [ $1 == "loop" ];then
    ./bin/exe loop
  fi
else 
	./bin/exe
fi
