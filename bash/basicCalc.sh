#!/bin/bash

echo "Enter the first number:"
read num1

echo "Enter the second number:"
read num2

echo "Enter the operation:"
echo "1 for addition, 2 for subtraction, 3 for multiplication, 4 for division"

read choice

case $choice in
    1)
        result=$((num1 + num2))
        echo "The result of addition is: $result"
        ;;
    2)
        result=$((num1 - num2))
        echo "The result of subtraction is: $result"
        ;;
    3)
        result=$((num1 * num2))
        echo "The result of multiplication is: $result"
        ;;
    4)
        if [ $num2 -ne 0 ]; then
            result=$((num1 / num2))
            echo "The result of division is: $result"
        else
            echo "Error: Division by zero is not allowed."
        fi
        ;;
    *)
        echo "Invalid Input"
        ;;
esac
