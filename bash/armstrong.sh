#!/bin/bash

armstrong(){
    local num=$1
    local sum=0 ; 

    local temp=$num

    while [ $temp -gt 0 ];
    do 
        local remainder=$(($temp%10))
        sum=$((sum + remainder*remainder*remainder))
        temp=$(($temp/10))
    done

    if [ $num -eq $sum ];then 
        echo "Armstrong number"
    else
        echo "Not an armstrong number"
    fi
}

echo "Enter a number"
read num

armstrong $num