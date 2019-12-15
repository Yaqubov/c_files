#!/bin/bash

var=$1

- 'if [ $(($var%2)) -eq 0 ];then
	echo "eded cutdur"
else
	echo "eded tekdir"
fi'

:

add5(){

	res=$(($var+5))
	echo $res
}


