#!/bin/bash


#read -p "Enter a file or directory name: " name
echo "Enter a file or directory name: "
read name

if [ -e "$name" ]; 
	then
    
    if [ -f "$name" ]; 
		then
        echo "$name is a file."
        
        
        size=$(du -h "$name" | cut -f1)
        echo "Size of $name: $size"
    elif [ -d "$name" ]; 
		then
        
        echo "$name is a directory."
        
        
        echo "Contents of $name:"
        ls "$name"
    else
        echo "$name is neither a file nor a directory."
    fi
else
    echo "$name does not exist."
fi


