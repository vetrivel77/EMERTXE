<<doc
name: vetrivel.p
date: 28/05/2022
description: Use a recursive function to print each argument passed to the function
sample i/p and o/p :
Test Case 1:
./recursion.sh How are you? I am fine
How
are
you?
I
am
fine

Test Case 2:
./recursion.sh
Error : Pass the arguments through command line.

Test Case 3:
./recursion.sh 1 12 123 1234 12345 123456
1
12
123
1234
12345
123456

doc

#!/bin/bash

if [ $# -eq 0 ]                                                         # to check cla passed or not
then
        echo " Error : Pass the arguments through command line."        # cla not passed to print the error
       
    fi     
       
   function recursive()                                                 # using function recursive
   { 
       arr=( $@ )                                                       # cla store all into one array
    
       echo $1                                                          # to assume arr valuve $1
    
       {
              
    if [ $# -gt 0 ]                                                     # to check arr elements one by one

    then
        arr=${arr[@]:1}                                                 # all arr elements store one @
    
    else
        return                                                          # return the valuve
    fi        
}

recursive ${arr[@]:1}                                                   # display the all contents one by one

}

    recursive $@                                                        # to shown the all elements





