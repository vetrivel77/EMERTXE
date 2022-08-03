<<doc
name: vetrivel.p
date: 21/02/2022
description: Shell script to convert string lower to upper and upper to lower
sample i/p:
        1. ./upper_lower.sh file.txt
        2. ./upper_lower.sh file.txt
        3. ./upper_lower.sh file1.txt
        4. ./upper_lower.sh
sample o/p:
1. 
1 – Lower to upper
2 – Upper to lower
Please select option : 1
WHAT IS OS?
WHAT ARE THE DIFFERENT OS?
WHEN IS OS USED?
WHAT IS PARTITION AND ITS USE?
HOW MANY PARTITIONS CAN BE DONE?
2. 
1 – Lower to Upper
2 – Upper to Lower
Please select option : 2

what is os?
what are the different os?
when is os used?
what is partition and its use?
how many partitions can be done?

3. 
Error: No contents inside the file.
4. 
Error : Please pass the file name through command line.

doc

#!/bin/bash


if [ $# -gt 0 ]                                          # check the arguments passed or not
then
    if [ -f $1 ]                                         # checking file inside
  then

    if [ -s $1 ]                                         # checking  emety file or not

   then

       echo "1 – Lower to upper"

       echo "2 – Upper to lower"
    
   read -p "please select option:" n                     # reading n value from arguments
 
   case $n in

      1)  cat $1 | tr '[:lower:]' '[:upper:]'            # lower case to upper case
          ;;
  
      2)  cat $1 | tr '[:upper:]' '[:lower:]'            # upper case to lower case
          ;; 
  esac

 else  
     echo "Error: No contents inside the file."         # different file passing print the error
 
 fi
  fi  
   else  
   echo  "Error : Please pass the file name through command line."  # aruments not passing print the error
   fi
