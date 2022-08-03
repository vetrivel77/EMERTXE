<<doc
name: vetrivel.p
date: 20/05/2022
desciption: Write script to print contents of file from given line number to next given number of lines
sample i/p:
1. ./print_lines.sh 5 3 myfile.txt
2. ./print_lines.sh myfile.txt
3. ./print_lines.sh 5 10 myfile.txt
sample o/p:
1.
line number 5
line number 6
line number 7

2. 
Error: arguments missing!
Usage: ./file_filter.sh start_line upto_line filename
For eg. ./file_filter.sh 5 5 <file>

3. 
Error: data.txt is having only 10 lines. file should have atleast 14 lines

doc





#!/bin/bash

if [ $# -eq 3 ]                                                                        # if cla arguments equal to 3 

then
   var=` cat $3 | wc -l`                                                               # using wc total number of count using piping method
   
   a=$((($1+$2)-1))                                                                    # varaible $a using addition $1 $2 and subtraction-1

   if [ $var -ge $a ]                                                                  # if  greater than equal to $var and $a
then
     cat $3 | head  -$a | tail -$2                                                     # using head and tail with piping using print the line valuve
 
 else

    echo "Error: data.txt is having only 10 lines. file should have atleast 14 lines"  # cla arguments passing total valuve 10 above print the error
 
fi 
   else  
       
   echo  "Error: arguments missing!"
  echo " Usage: ./file_filter.sh start_line upto_line filename
    For eg. ./file_filter.sh 5 5 <file> "                                               # cla aruments not passing print the error
       
     fi

 


