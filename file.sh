#!/bin/bash

dir=$1
file=~/Desktop/output.txt

if [ -w $file ];then
	cat /dev/null > $file
fi

for i in $dir/*
do
	cat $i | grep -E "[a-z]*_[a-z]*_[a-z]*" >> $file
done
cat $file | wc -l >> $file
cat $file
