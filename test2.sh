#!/bin/bash

dir=$1

if [ -w ~/Desktop/output.txt ];then
	cat /dev/null > ~/Desktop/output.txt
fi
for i in $dir/*.txt
do
	head -3 $i >> ~/Desktop/output.txt
done

cat ~/Desktop/output.txt
