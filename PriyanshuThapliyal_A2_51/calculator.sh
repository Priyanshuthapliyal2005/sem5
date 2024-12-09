#!/bin/bash

calculator(){
    local a=$1
    local b=$2
    echo "Enter the operation you want to perform:"
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    read choice 

    case $choice in 
        1)
        result=$(($a +$b))
        echo "The sum of $a and $b is $result"
        ;;

        2)
        result=$((a - b)) 
        echo "The difference of $a and $b is $result"
        ;;

        3) 
        result=$(($a * $b))
        echo "The product of $a and $b is $result"
        ;;

        4)
        result=$(($a / $b))
        echo "The division of $a and $b is $result"
        ;;

        *)
        echo "Invalid choice"
        ;;

    esac
}
echo "Enter the number of iterations: "
read i 

echo "Enter the 2 numbers : "
read a
read b

for((j=0 ; j < i ; j++));do
    calculator $a $b
done