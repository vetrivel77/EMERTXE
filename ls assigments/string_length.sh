<<doc
name: vetrivel.p
date: 19/05/2022
description: Write a script to print the length of each and every string using arraysVirtual programming lab
sample i/p:
Test Case 1:                                   
./string_length.sh hello hai how are you?
Test Case 2:
./string_length.sh
sample o/p:
test case 1                            test case 2
Length of string (hello) - 5           Error : Please pass the arguments through command-line.
Length of string (hai) - 3
Length of string (how) - 3
Length of string (are) - 3
Length of string (you?) - 4
doc

#!bin/bash
if [ $# -le 0 ]                                                  # loop lessten equal to zero
then
   echo "Error : please pass the arguments through command-line" # cla no valuve to print the error command
fi
    arr=($*)                                                     # cla all valuve
    i=0                                                          # i=0,1,2,3,4,5
for i in ${arr[@]}                                               # loop consider i and arr[@] value
do   
   echo  "length of string ($i)-${#i}"                           # To print the length of string valuve cla and length
    
done 
