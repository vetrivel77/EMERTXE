<<doc
name: vetrivel.p
date: 25/05/2022
description: Write script called say_hello, which will print greetings based on time
sample i/p and o/p:
1. When we start shell (whenever you opening new tab or terminal)
Good Morning user, Have nice day!
This is Thursday 08 in June of 2017 (10:44:10 AM)
doc

#!/bin/bash

day=`date | cut -d" " -f1`                          # using cut command cut the day from date                                              
date=`date | cut -d" " -f3`                         # using cut command cut the date from date
month=`date | cut -d" " -f2`                        # using cut commant cut the month from date
year=`date | cut -d" "  -f6`                        # using cut command cut the year from  date
time1=`date | cut -d" " -f4`                        # using cut command cut the time from date
hour=`date | cut -d" " -f4| cut -d":" -f1`          # using cut command cut the hour from date

if [ $hour -ge 5 -a $hour -lt 12 ]                  # using if  condition time depent on greetings shown
then
    
   echo -e "good morning have a nice day!, $USER\n this is $day $date in $month of $year ($time1)" # show the greetings output from the whole opening

elif [ $hour -ge 12 -a $hour -lt 13 ]               # using elif contions from differnt timings

then 
    echo -e "good noon, $USER\n this is $day $date in $month of $year ($month)"
    
  
  elif [ $hour -ge 14 -a $hour -lt 17 ]
  then
      echo -e "good afternoon, $USER\n this is $day $date in $month of $year ($time1)" 

 elif [ $hour -ge 17 -a $hour -lt 21 ]
 then
    
     echo -e "good evening, $USER\n this is $day $date in $month of $year ($time1)"
 
 elif [ $hour -ge 21 -a $hour -le 5 ]
then
echo -e "gud night end of the day!,$USER\n this is $day $date in $month  of year ($time1)"

fi
 

 
























