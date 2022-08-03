/*
name: vetrivel.p
date:25/06/2022
description: A16 - WAP to get 'n' bits from given position of a number
sample i/p and o/p:
Test Case 1:

Enter the number: 12

Enter number of bits: 3

Enter the pos: 4

Result = 3

Test Case 2:

Enter the number: 15

Enter number of bits: 2

Enter the pos: 2

Result =  3

*/

#include <stdio.h>

int get_nbits_from_pos(int, int, int);

int main()
{
    // caller fuction
    int num, n, pos, res = 0;
    
    printf("Enter num, n and val:");
    scanf("%d%d%d", &num, &n, &pos);
    
    res = get_nbits_from_pos(num, n, pos);
    
    printf("Result = %d\n", res);
 
}
int get_nbits_from_pos(int num, int n, int pos)
{
    // called function
    // to get the n bits 
    // to change the pos to get the value
    int res=(((1 << pos) - 1) & (num >> (pos - n + 1)));
    
 return res;
}
