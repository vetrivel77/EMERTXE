/*
name: vetrivel.p
date: 7/02/2022
description: A21 - WAP to implement Circular right shift
sample i/p and o/p:
Sample execution: -
Test Case 1:
user@emertxe] ./bit_ops

Enter num: 12
Enter n : 3
Result : 10000000 00000000 00000000 00000001

Test Case 2: 
Enter num: -12
Enter n : 3
Result : 10011111 11111111 11111111 11111110
*/

#include <stdio.h>

int circular_right(int, int);                                                                         // function and parameters
int print_bits(int);

int main()
{
    int num, n, ret;                                                                                  // variable declaration 
    
    printf("Enter the num:");                                                                         // read num from user
    scanf("%d", &num);
    
    printf("Enter n:");                                                                               // read n from user
    scanf("%d", &n);
    
    ret = circular_right(num, n);                                                                     // function call
    
    printf("Result:");                                                                                // display the result
    
    print_bits(ret);                                                                                  // return val ret
    
}

int circular_right(int num, int n)                                                                    // function prototype

{ 
    unsigned a=num;
  
    return(num >> n) & (~(((1 << n)-1) << (31 - n + 1))) | (a & ((1 << n)-1)) << (31 - n + 1);        // right shifted value return to ret
  
}     

int print_bits(int ret)      

{     
     for( int i = 0  ; i < 32; i++)                                                                   // loop printiong binary value msb to lsb    
     {
         if( (ret >> 31 - i) & 1 )
 
             printf(" 1");
  
         else
  
             printf(" 0");
   
      }


}
