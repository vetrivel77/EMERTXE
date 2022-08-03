/*
name: vetrivel.p
date: 23/06/2022
description:
sample i/p and o/p:
Test Case 1:

Enter the number: 10

Enter number of bits: 3

Result = 2

Test Case 2:

Enter the number: 15

Enter number of bits: 2

Result = 3

*/

#include<stdio.h>

int get_nbits(int num, int n);

int main()
{
   // variable declaration 
   // caller function
    int num, n, res = 0;
    
    printf("Enter the number: :");
    scanf("%d", &num);
    
    printf("Enter number of bits:");
    scanf("%d",&n);
   
   // function call    
    res = get_nbits(num, n);
   
   // print the results     
    printf("Result = %d\n", res);

 return 0;
}   
   // called function
    int get_nbits(int num, int n)  // name of the function and prameters
{   
    int res=((num & (1 << n) -1)); // to get the bits
   
 return res;
}

