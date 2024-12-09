#!/bin/bash

# Function to check if a number is prime
is_prime(){
    num=$1
    if [ $num -le 1 ]; then
        return 1  # Not prime
    fi
    for ((i=2; i<=num/2; i++)); do
        if [ $((num % i)) -eq 0 ]; then
            return 1  # Not prime
        fi
    done
    return 0  # Prime
}

# Function to print prime numbers in the given range
print_primes_in_range(){
    start=$1
    end=$2
    echo "Prime numbers between $start and $end are:"
    for ((num=start; num<=end; num++)); do
        if is_prime $num; then
            echo $num
        fi
    done
}

# Read start and end range from user
echo "Enter the start of the range:"
read start
echo "Enter the end of the range:"
read end

# Call the function to print prime numbers in the range
print_primes_in_range $start $end
