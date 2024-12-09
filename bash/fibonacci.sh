#!/bin/bash

helper(){
    n=$1
    size=$n

    if [ $size -le 0 ]; then 
        echo 0
    elif [ $size -eq 1 ]; then 
        echo 1
    else
        # Fixed the missing parenthesis in the recursive call
        echo $(( $(helper $((size-1))) + $(helper $((size-2))) ))
    fi
}

echo "Enter the n up to which you want to generate the Fibonacci sequence:"
read n 

helper $n
