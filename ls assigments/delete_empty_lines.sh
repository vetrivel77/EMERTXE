<<doc
name: vetrivel.p
date: 23/05/2022
description: Write a script to delete empty lines from a file
sample i/p:
1. ./delete_empty_lines.sh file.txt
2. ./delete_empty_lines.sh
sample o/p:
1. 
Empty lines are deleted
Hello
How
are
you?

2. 
Error: Please pass the file name through command line.

doc


#!/bin/bash

if [ $# -gt 0 ]                                                   # to check the aruments passing or not       

then
    
    echo "Empty lines are deleted"                                # output contents


  sed  '/^[[:blank:]]*$/d' $1                                     # using sed command to delecting the empty lines

else

    echo "Error: Please pass the file name through command line." # aruments not passing print the error message 
fi

            # sed- commands usage
            # /^-represented in between space line are delecting
            # [:blank:]*-represented  all blank lines
            # d-particular line delected
            # $-end of the line





