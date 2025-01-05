#!/bin/bash

helper(){
    num=$1
    
    if [ $num -le 1 ];then
        echo $num is not prime
        exit
    fi

    for((i=2;i<=num/2;i++));do
        if [ $((num%i)) -eq 0 ];then 
            echo  $num is not prime
            exit
        fi
    done
    echo $num is a prime number
}

echo enter the number
read num

helper $num