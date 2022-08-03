/*
name: vetrivel.p
date: 15/06/2022
description: A9 - WAP to find which day of the year
sample i/p and o/p:
Test Case 1:
user@emertxe] ./day_of_the_year
Enter the value of 'n' : 9
Choose First Day :
1. Sunday
2. Monday
3. Tuesday
4. Wednesday
5. Thursday
6. Friday
7. Saturday
Enter the option to set the first day : 2
The day is Tuesday
Test Case 2:
Enter the value of 'n' : 9
Choose First Day :
1. Sunday
2. Monday
3. Tuesday
4. Wednesday
5. Thursday
6. Friday
7. Saturday
Enter the option to set the first day : 3
The day is Wednesday
Test Case 3: 
Enter the value of 'n' : 9

*/

#include<stdio.h>

int main()

{
  //declare the variables
    
    int n,day,res=0;

  // read from the user days

printf("Enter the value of 'n' :");
  scanf("%d",&n);
 
  // to check enter days within 365days 
  {      
    if( n > 0 && n <= 365)
  
  // within 365v days to print the menu      
    {
printf("Choose First Day :\n 1. sunday \n 2. monday \n 3. Tuesday \n 4. wednesday \n 5. Thursday\n 6. Friday\n 7. Saturday\n");
 
  // enter the week starting day

printf("Enter the option to set the first day :");
scanf("%d",&day);

  // to check enter days within week days 7 not print the error message

    if(day > 0 && day <= 7)
    
    {

    if((day + n -1)%7 == 0)   // count the days equal to %7
    
    day=7;
    
    else 
     day=((day + n -1)%7);   // count the week days to total days
   
  // using switch to print the days

switch(day)
{

case 1: 
    
       printf("The day is  Sunday\n");       
        
        break;

case 2: 
     
        printf("The day is Monday\n");

        break;

case 3: 
        
        printf("The day is Tuesday\n");

        break;

case 4:
       
        printf("The day is Wednesday\n");

        break;

case 5:
       
        printf("The day is Thursday\n");

        break;

case 6:
       
        printf("The day is Friday\n");

        break;

case 7:
       
        printf("The day is Saturday\n");      
}


}

else

    printf("Error: Invalid input, first day should be > 0 and <= 7\n");    
    
  }
// enter value not within 365days  to print the error message 

else   
{
printf("Error: Invalid Input, n value should be > 0 and <= 365\n");

}

}
return 0;
}




