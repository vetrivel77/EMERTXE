<<doc
name: vetrivel.p
date: 18/05/2022
description: Write a script for arithmetic calculator using command line argumentsVirtual programming lab                                                                                                                                                                                                                                                                     
sample i/p:
 1. ./arithmatic_calc.sh 25 + 41
2. ./arithmatic_calc.sh 10 x 5
3. ./arithmatic_calc.sh 25 / 5
4. ./arithmatic_calc.sh 10.2 – 5.6
5. ./arithmatic_calc.sh
6. ./arithmatic_calc.sh 3.4
sample o/p:
1../arithmatic_calc.sh 25 + 41
25 + 41 = 66
2. ./arithmatic_calc.sh 10 x 5
10 x 5 = 50
3. ./arithmatic_calc.sh 25 / 5
25 / 5 = 5.00
4. ./arithmatic_calc.sh 10.2 – 5.6
10.2 – 5.6 = 4.6
5. ./arithmatic_calc.sh
Error : Please pass the arguments through command line.
Usage:./arithmatic_calc.sh 2.3 + 6.7
6. ./arithmatic_calc.sh 3.4
Error:Please pass 3 arguments.
Usage:./arithmatic_calc.sh 2.3 + 6.7
doc

#!bin/bash  

if [ $# -eq 0 ]                                                                 # condition for checking pass the cla
then
    echo  "Error: Please pass the arguments through command line.Usage:./arithmatic_calc.sh 2.3 + 6.7" # file with no cla whether print the error
          
elif [ $# -lt 3 ]                                                               # checking the less than cla $1,$2,$3
then  
    echo  "Error:Please pass 3 arguments.Usage:./arithmatic_calc.sh 2.3 + 6.7"  # file and one single arithematic value whether print the error
    fi

case $2 in                                                                      

     +)                                                                         # addition

   echo "$1 + $3" = `echo "$1 + $3" |bc`                                        # integer addition with cla valuve piping method to bc 
         ;;
     -)                                                                         # subtraction 

    echo "$1 - $3" = `echo "$1 - $3" |bc`                                       # integer subtraction with cla values piping method to bc
         ;;
     x)                                                                         # mulitiplication  

    echo "$1 x $3" = `echo "$1 * $3" |bc`                                       # integer muliplication with cla values piping method to bc
         ;;
    /)                                                                          # devision 

    echo "$1 / $3" = `echo "scale=2; $1/$3" |bc`                                # for devision quatient and decimal valuve with piping bc
         ;;         

esac


   

