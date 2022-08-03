<<doc
name: vetrivel.p
date: 29/03/2022
description: Write a script to replace 20% lines in a C file randomly and replace it with the pattern
sample i/p and o/p:
1. ./replace_DEL.sh main.c
Before replacing
#incude <stdio.h>
int main()
{
         printf(“Hello world\n”);
}
After replacing
#incude <stdio.h>
int main()
{
<-----------Deleted------------>
}
2. ./replace_DEL.sh main1.c
Error : No such a file.
3. ./replace_DEL.sh main2.c
Error : main2.c is empty file. So can’t replace the string.
4. ./replace_DEL.sh
Error : Please pass the file name through command line.

doc

#!/bin/bash

if [ $# -ne 0 ]                                                              # to check cla passed or not
then
    n=$@                                                                     # all arg to store in one var
    if [ -f $1 ]                                                             # to check file or not
       then
           if [ -s $1 ]                                                      # to check file inside content or not
           then                             
               con=`wc -l < $@`                                              # to count the file lines
               echo $con          
          if [ $con -ge 5 ]                                                  #  lines greater then to 5
          then
              d=$(($con/5))                                                  # lines div by 5             
             echo $d
              for i in `seq $d`                                              # usin g for loop get one by lines
              do
                  p=`shuf -i 1-$con -n1`                                     # using shuf findout random lines                
                echo $p 
                  sed -i "$p   s/.*/<-----------Deleted------------>/" $1    # using sed delete enter the line
              done              
              cat $1                                                          #display the 20% in a file                    

fi
   else

       echo "Error : No such a file."                                        # no contents to print the error
   fi
   else

   echo "Error : main2.c is empty file. So can’t replace the string."        # file file to print the error
      
   fi

   else   
       echo " Error : Please pass the file name through command line. "      # cla not passed to print the error
 
fi






