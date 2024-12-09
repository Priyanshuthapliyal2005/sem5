#!/bin/bash

echo what is your name?
read name 

echo hi $name , welcome to election of india 

echo enter your age to check your eligibility
read age 

if [ $age -ge 18 ] 
then
	echo you are eligible to vote 
else 
	echo you are not eligible to vote
fi 
