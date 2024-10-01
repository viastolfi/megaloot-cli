#!/bin/bash

echo "Make necessary dir"
mkdir bin obj

echo "Compile"
make clean
make

clear
if [ ! -z $1 ];then
	if [ $1 == "dev" ];then
		echo "test"
		./bin/exe dev
	fi	
else 
	./bin/exe
fi
