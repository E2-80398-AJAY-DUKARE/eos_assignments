#!/bin/bash

echo "Enter a number: "
read num 

fact=1

if [ $num -lt 0 ]
    echo "Factorial is not defined for negative numbers."
elif [ $num -eq 0 ]
    then
    echo "The Factorial of 0 is 1."
else
    for ((i=1; i<=num; i++))
    do
    factorial=$((fact * i))
    done
    echo "the factorial of $num is $fact"
fi