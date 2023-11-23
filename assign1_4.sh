#!/bin/bash

# check number is prime or not

echo -n "Enter number: "
read num

i=2 
flag=0

while [ $i -lt $num ]
do
	if [ `expr $num % $i` -eq 0 ]
		then
			flag=1
			echo "$num not a prime number"
			break
	fi
	i=`expr $i + 1`
done

if [ $flag -eq 0 ]
	then
		echo "$num is prime number"
fi

