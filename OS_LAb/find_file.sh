#!/bin/sh
echo "enter folder name"


find . -type f -name "*.txt" | while read file 
do 
	echo "file changed to text"
	mv "$file" "${file%.txt}.text"
done
