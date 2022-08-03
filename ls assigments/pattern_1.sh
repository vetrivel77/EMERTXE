<<doc
name : vetrivel.p
date : 17/05/2022
description: Read 'n' and generate given below (number incriments from left to right)
sample i/p: Enter the number:4
sample o/p:test case 1              test case 2
           1                           1
           1 2                         1 2
           1 2 3
           1 2 3 4
doc

#!bin/bash
read -p "enter the number:" n   #number read from the user
                            
for row in `seq $n`             #loop for number of row
    do                         
        for col in `seq $row`   #loop from number of colomns
        do
          echo -n "$col "       #to print the colomn value
    done
  echo                          #to get the new line
done
