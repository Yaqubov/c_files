#!/bin/bash

dir=$1
for i in $dir/*.c
do
	grep -E "[a-z]+_[a-z]+_[a-z]+" $i
	grep -E "[a-z]+_[a-z]+_[a-z]+" $i | cut -d "_" -f 2 >> ~/Desktop/output.txt
done

