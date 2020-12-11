#!/bin/sh

#delete the FILENAME.replace if existing.
if [ -f haystack.txt.replace ]
then
	rm haystack.txt.replace;
fi


make re

echo "BEFORE:"
cat haystack.txt
echo "\n\033[31m replacing xoxo by HAHA\033[0m"
echo "\nAFTER:"
./replace haystack.txt xoxo HAHA
cat haystack.txt.replace
