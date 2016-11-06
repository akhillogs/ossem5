#!/bin/bash
# Shell program to read a number and find the sum of digits
# -----------------------------------------------
# Copyright (c) 2005 nixCraft project <http://cyberciti.biz/fb/>
# This script is licensed under GNU GPL version 2.0 or above
# -------------------------------------------------------------------------
# This script is part of nixCraft shell script collection (NSSC)
# Visit http://bash.cyberciti.biz/ for more information.
# -------------------------------------------------------------------------
 
echo -n "Enter number : "
read n
 
# store single digit
sd=0
 
# store number of digit 
sum=0
 
# use while loop to caclulate the sum of all digits
while [ $n -gt 0 ]
do
    sd=$(( $n % 10 )) # get Remainder 
    n=$(( $n / 10 ))  # get next digit
    sum=$(( $sum + $sd )) # calculate sum of digit
done
echo  "Sum of all digit  is $sum"
