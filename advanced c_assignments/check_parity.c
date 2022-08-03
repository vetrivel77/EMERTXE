/*
name: vetrivel.p
date: 17/06/2022
description:A10 - WAP to count number of set bits in a given number and print parity
sample i/p and o/p:

Test Case 1:

Enter the number : 7

Number of set bits = 3

Bit parity is Odd

Test Case 2:

Enter the number : 15

Number of set bits = 4

Bit parity is Even

Test Case 3:

Enter the number : 6

Number of set bits = 2

Bit parity is Even
*/

#include<stdio.h>

int main()

{
 // varable declaration      
    int num,i,mask,count=0;

 // read num from the user
   printf("Enter the number :");
   scanf("%d",&num);
 
 // using loop get set bit size based on user value

for(i = 0 ;i < sizeof(num) * 8; i++)
{
 // using left shifting with mask value to get value 
    
    mask=(1 << i);
//using set bit opration to get value
    
    if(( num & (mask)) == (mask)) 

     count++;                      // count the value
}
  // to print the size of number

   printf("Number of set bits = %d\n",count);
{   
  // to check parity even or odd to print the output

   if(count%2)

{
    printf("Bit parity is Odd\n");
}
    else

        printf("Bit parity is even\n");
   }    

return 0;
}
