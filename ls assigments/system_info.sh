<<doc
name: vetrivel.p
date: 27/05/2022
description:Write a script to print system information using commands
sample i/p and o/p:
./system_info.sh
1. Currently logged users
2. Your shell directory
3. Home directory
4. OS name & version
5. Current working directory
6. Number of users logged in
7. Show all available shells in your system
8. Hard disk information
9. CPU information.
10. Memory Informations
11. File system information.
12. Currently running process.
Enter the choice : 2
Your shell directory is /bin/bash
Do you want to continue (y/n) ? y
1. Currently logged users
2. Your shell directory
3. Home directory
4. OS name & version
5. Current working directory
6. Number of users logged in
7. Show all available shells in your system
8. Hard disk information
9. CPU information.
10. Memory Informations
11. File system information.
12. Currently running process.
Enter the choice : 13
Error : Invalid option, please enter valid option
Do you want to continue(y/n) ? 
doc

#!/bin/bash                              

n="y"                                                    # to creat varible
 
while [ $n="y" ]                                         # using while loop $n equal to y

do                                                       # system information menu
 
echo " 1. Currently logged users                          
 2. Your shell directory 
 3. Home directory 
 4. OS name & version
 5. Current working directory
 6. Number of users logged in
 7. Show all available shells in your system
 8. Hard disk information
 9. CPU information.
 10. Memory Informations
 11. File system information.
 12. Currently running process."
 
 read -p "enter the choice:" n                           # read n valuve from menu 

case $n in 

    1) echo -n  "currently login users:" ;  whoami

        ;; 
       
    2) echo -n "your shell directory:" ; echo $SHELL

        ;;
   
    3) echo -n  "your home directory:" ; echo ~ 
      
      ;;

    4) echo -n  "os name version is:" ; uname -a
      
      ;;

    5) echo -n  "currently login users:" ; pwd

      ;;

    6) echo -n "num of users login:" ; who

      ;;

    7) echo -n "show all available shells in my syatem:" ; cat /etc/shells
     
      ;;

   8) echo -n "hard disk information:" ; hwinfo

     ;;

    9) echo -n "cpu information:" ; cat /proc/cpuinfo
    
    ;;

    10) echo "memory information:" ; cat /proc/meminfo

    ;;

    11) echo -n  "file system information:" ; df
    
    ;;
    
    
   12) echo -n "currently running process:" ; ps
    
    ;;

    *) echo "Error : Invalid option, please enter valid option"         # defalut option


esac

  read -p "Do you want to continue (y/n) ? " n                           #  another menu to print to press y otherwise not print menu using n key

 done





