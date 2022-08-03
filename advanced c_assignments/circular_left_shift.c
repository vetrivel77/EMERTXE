/*
name: vetrivel.p
date: 01/07/2022
description: WAP to implement Circular left shift
sample i/p and o/p:

Test Case 1:
user@emertxe] ./bit_ops
Enter num: 12
Enter n : 3
Result in Binary: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0

Test Case 2:
Enter num: -2
Enter n : 3
Result in Binary: 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1
*/

#include <stdio.h>

int circular_left(int, int);                   // function name and parameters                  
int print_bits(int);

int main()
{
    int num, n, ret;                           // variable declaration
    
    printf("Enter the num:");                  // read num from the user
    scanf("%d", &num);
    
    printf("Enter n:");                        // read n from user                        
    scanf("%d", &n);
    
    ret = circular_left(num, n);               // function call     

    printf("Result in Binary:");

    print_bits(ret);
}

int circular_left(int num, int n)              // function prototype

{
    unsigned int a = num;                      // to declare unsigned int,num value stored in a 
 
    return(num << n) | a >> (32 - n) ;         // left shift to clear the n bit right shifted unsigned value both value divided into (or)--| option final value stored in ret    
} 

int print_bits(int ret)  

{    
     
    for( int i = 31  ; i >= 0; i--)            // loop printing each binary value msb to lsb
    { 
        if( ret & 1 << i)                      // mulitiple ret value & 1<<i value based on value print 1,0    
            
            printf("1 ");
         
        else

            printf("0 ");
           
    }

} 

