#!/bin/bash

echo -n "Enter a number: "
read num

echo "Multiplication table for $num:"

for ((i=1; i<=10; i++));
do
    result=$((num * i))
    echo "$num x $i = $result"
done
