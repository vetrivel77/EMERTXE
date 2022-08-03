<<doc
name: vetrivel.p
date:24/05/2022
description: Write a script to perform arithmetic operation on digits of a given number
sample i/p and o/p:
./operator_dependent.sh 1234+
Sum of digits = 10
Test Case 2: 
./operator_dependent.sh 8312-
Subtraction of digits = 2
Test Case 3:
./operator_dependent.sh 5487
Error: Operator missing or invalid operator, please pass operator as last digit (+,-,x,/)
Test Case 4: 
./operator_dependent.sh 1111x
Multiplication of digits = 1
Test case 5:
./operator_dependent.sh 12/
Division of digits = .50
Test Case 6: 
./operator_dependent.sh
Error : Please pass the arguments through CL.
Usage : ./operator_dependent.sh 2345+


doc

#!/bin/bash

if [ $# -eq 1 ]                                                               # to check the loop pasing are not 

then

var=$1                                                                        # to create common variable
oper=${var: -1}                                                                
sum=${var:0:1}
sub=${var:0:1}
mul=${var:0:1}
size=${#var}                                                                  # length of all varible length

  case $oper in                                                              # using case operter in i valuve 
           
      +)  for i  in `seq 1 $((size-2))`                                      # addition
              
      do

          sum=`echo "$sum + ${var:$i:1}" | bc`
     
      done
          echo "Sum of digits = $sum" 
          ;;
                      

      -)  for i in `seq 1 $((size-2))`                                       # subtraction
       do
          sub=`echo "sub - ${var:i:1}" | bc`
      done     

          echo "Subtraction of digits = $sub"
          ;;

          
       

      x)  for i in `seq 1 $((size-2))`                                       # mulitiplication
         
      do
          mul=`echo "$mul * ${var:$i:1}" | bc`
      done
          echo "Multiplication of digits = $mul"
         
          ;;                                     

       /)  div=`echo "scale=2; ${var:0:1} / ${var:1:1}" | bc`                # divition
      
          echo "Division of digits = $div"
      
          ;;
           
      *) echo "Error: Operator missing or invalid operator, please pass operator as last digit (+,-,x,/)" # invalid operater

      esac  
  else   

    echo "Error : Please pass the arguments through CL.                       
           Usage : ./operator_dependent.sh 2345+"

fi                                                                                        # valuve not passing print the error

