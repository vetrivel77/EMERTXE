/*
name: vrtrivel.p
date: 13/06/2022
description:A5 - WAP to generate AP, GP, HP series
sample i/p and o/p:

Enter the Common Difference / Ratio 'R': 3
Enter the number of terms 'N': 5
AP = 2, 5, 8, 11, 14
GP = 2, 6, 18, 54, 162
HP = 0.500000, 0.200000, 0.125000, 0.090909, 0.071428

Test Case 2:
Enter the First Number 'A': 2
Enter the Common Difference / Ratio 'R': 3
Enter the number of terms 'N': -5
Invalid input

*/

#include<stdio.h>

int main()

{
// varable declaration
    int a,r,n,i=0;   

// read from the user values

   printf("Enter the First Number 'A':");
   scanf("%d",&a);

   printf("Enter the Common Difference / Ratio 'R':");

   scanf("%d",&r);

   printf("Enter the number of terms 'N':");
       
      scanf("%d",&n);

// to check +ve or -ve value

if(n > 0)

{

printf("AP= ");

int d = a;

//loop for n times

while(i < n)
{

    printf("%d,",d);
    d= d + r;
    i++;
}

i=0;
d=a;

// print the gp valuve

    //if(num > 0 || num <= 365)
printf("\nGP= ");

//loop for n times

while(i < n)
{
    printf("%d,",d);
    d=d * r;
    i++;
}

i=0;
d=a;

//to print the hp value

printf("\nHP= ");

//loop for float value
while(i < n)
{

 //using type costing method   
    
    float res=(float)1/d;
    
    printf("%f,",res);
            d= d + r;
            i++;
            }

       }
       else
       {
       printf("invalid input\n");
       }

        

return 0;

    
}
   
   
   
   
            




