#!/bin/bash

#Check if two arguments are provided
if ["$#" -ne 2]; then
	echo "usage: $0 <number1> <number2>"
	exit 1
fi

#Multipy the two numbers
result=$(($1 * $2))

#Print the result
echo "Result of multiplication: $result"
