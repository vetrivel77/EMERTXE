#!/bin/bash
<<doc
name: vetrivel.p
date: 28/05/2022
description: Count the number of users with user IDs between given range.
sample i/p and o/p:
1. ./user_ids.sh
Total count of user ID between 500 to 10000 is: 2

2. ./user_ids.sh 0 100
Total count of user ID between 0 to 100 is : 3

3. ./user_ids.sh 100
Error : Please pass 2 arguments through CL.
Usage : ./user_ids.sh 100 200

4. ./user_ids.sh 200 100
Error : Invalid range. Please enter the valid range through CL.

doc

arr=(`cat /etc/passwd | cut -d ":" -f3`)                                  # using cut command cut the ids numbers 

count=0
count1=0

if [ $# -eq 0 ]                                                           # to check cla

then

for i  in ${arr[@]}                                                       # using for loop include i and full cla elements
do
    if [ $i -ge 500 -a $i -le 10000 ]                                     # using i valuve and ids numbers 500 to 10000
    then
        count=$(($count+1))                                               # using count the id valuves
    fi
done
echo "Total count of user ID between 500 to 10000 is: $count "            # to print the ids between 500 to 10000

elif [ $# -eq 2 ]                                                         # cla equal to 2
then
  if [ $1 -lt $2 ]                                                        # arr valuve $1 less than $2
then
      for i in ${arr[@]}                                                  # another for loop get the id numbers
      do
          if [ $i -gt $1 -a $i -lt $2 ]                                   # $i lessthan and greaterthan equal to $1 and $2
          then
              count1=$(($count1+1))                                       # to count the valuves
          fi 
      
  done 
  
       echo "Total count of user ID between $1 to $2 is :$count1"         # to shown the ids numbers
    
   else        
    echo "Error : Invalid range. Please enter the valid range through CL." # wronly cla passed to print the error

fi
else                                                                       # cla not passed to print the error
    echo "Error : Please pass 2 arguments through CL.                              
          Usage : ./user_ids.sh 100 200"
      fi
