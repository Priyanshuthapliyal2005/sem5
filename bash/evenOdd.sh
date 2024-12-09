#!/bin/bash

print(){
    local num=$1
    if [ $((num % 2)) -eq 0 ]; then
        echo even number
    else 
        echo odd number
    fi
}

echo enter the number 
read num 

print $num