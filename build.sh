#!/bin/bash

echo "Compile"
make clean
make

clear
if [ ! -z $1 ];then
	if [ $1 == "dev" ];then
		./bin/exe dev
	fi	
else 
	./bin/exe
fi
