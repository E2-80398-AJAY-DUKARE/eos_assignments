#!bin/bash

echo -n "enter num1: "
read num1
echo -n "enter num2: "
read num2
echo -n "enter num3: "
read num3

if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]
	then
	echo -n "greater $num1"
elif [ $num2 -gt $num3 ] && [ $num2 -gt $num1 ]
	then
	echo -n "greater $num2"
else
	echo "greater $num3"
fi

