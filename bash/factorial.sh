#!/bin/bash

factorial(){
    local num=$1
    local result=1
    for((i=1 ; i <= num ; i++)); do 
        result=$((result*i))
    done 
    echo $result
}

print(){
    local num=$1
    local fact=$(factorial $num)
    echo "Factorial of $num is : $fact"
}

echo "Enter the number for which factoral you want :"
read num

print $num
