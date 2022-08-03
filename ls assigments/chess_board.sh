<<doc
name: vetrivel.p
date: 22/05/2022
description: Write a script to print chess boardVirtual programming lab
sample i/p: 1. ./chess_board.sh
sample o/p: To print the chess board 8 rows and 8 coloms black and white combination

doc

#!bin/bash

for row in `seq 8`                            # loop is number of row seq8
do
    for col in `seq 8`                        # loop is number of col seq8
    do
        if  [[ $(((($row+$col))%2)) -eq 0 ]]  # using if condition to addition row and col
        then
            echo -e -n "\e[47m" " "           # to print the white box using colour code
        else
            echo -e -n "\e[40m" " "           # to print the block box using colour code
            
        fi          
       
    done
  echo -e -n "\e[0m" " "                      # whether 8 colomns to make a colour

    echo

 done 
   
