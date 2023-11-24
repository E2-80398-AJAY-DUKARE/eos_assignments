#!/bin/bash

echo -n "Enter a year: "
read year

#if [ `expr $(year % 4)` -eq 0 ] -a [ `expr $(year % 100)` -ne 0 ] -o [ `expr $(year % 400)` -eq 0]
#    then
 #   echo "$year" is a leap."
#else
 #   echo "year is not a leap."
#fi

 if [ `expr $year % 4` -eq 0 -a `expr $year % 100` -ne 0 -o `expr $year % 400` -eq 0 ]
 	then
		echo "Leap Year !"
 else
	        echo "Not Leap year !"
 fi      		
