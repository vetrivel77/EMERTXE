/*
name: vetrivel.p
date: 25/06/2022
description: A15 - WAP to replace 'n' bits of a given number
sample i/p and o/p;
Test Case 1:

Enter the number: 10

Enter number of bits: 3

Enter the value: 12

Result = 12

Test Case 2:

Enter the number: 15

Enter number of bits: 2

Enter the value: 1

Result =  13
*/

#include <stdio.h>

#include <stdio.h>

int replace_nbits(int, int, int);

int main()
{
    int num, n, val, res = 0;
    
    printf("Enter num, n and val:");
    scanf("%d%d%d", &num, &n, &val);
    
    res = replace_nbits(num, n, val);
    
    printf("Result = %d\n", res);
}
    int replace_nbits(int num, int n, int val)
{
   // temporary variables
   int x,y; 
   
   // to get the n bits from lsb of value   
   x = val & ((1 << n)-1); 
   
   // to clear the n bit from lsb
   y= num & ~((1 << n)-1);
   
   // replace y value in x value
   y= y + x;

  return y;
}




