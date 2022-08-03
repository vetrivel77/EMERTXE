/*
name: vetrivel.p
date: 26/06/2022
description: A17 - WAP to toggle 'n' bits from given position of a number
sample i/p and o/p:
Test Case 1:

Enter the number: 10

Enter number of bits: 3

Enter the pos: 5

Result = 50

Test Case 2:

Enter the number: 15

Enter number of bits: 2

Enter the pos: 2

Result =  9

*/

#include <stdio.h>
// function name and parameters
int toggle_nbits_from_pos(int, int, int);

int main()
{
    // caller function
    int num, n, pos, res = 0;
    // read num,n,pos from user
    printf("Enter num, n and val:");
    scanf("%d%d%d", &num, &n, &pos);
    // function call
    res = toggle_nbits_from_pos(num, n, pos);
    // display the results
    printf("Result = %d\n", res);
}
int toggle_nbits_from_pos(int num, int n, int pos) 
{
    // called function
    // using toggle bits
    // toggle n bits from pos to get the updated  value
    int res= num ^ ~(~0 << n) << (pos - n + 1);
    
  return res;
} 
