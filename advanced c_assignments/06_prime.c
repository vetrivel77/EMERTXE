/*
name: vetrivel.p
date: 18/06/2022
description: A12 - WAP to print all primes using Sieve of Eratosthenes method
sample i/p and o/p:
Test Case 1: A positive number
user@emertxe] ./prime_series
Enter the value of 'n' : 20
The primes less than or equal to 20 are : 2, 3, 5, 7, 11, 13, 17, 19
Test Case 2 :

Enter the value of 'n' : -20
Please enter a positive number which is > 1
*/

#include<stdio.h>

int main()
{
 
  int num,i;                                                       // variable declaration    
 printf("Enter the value of 'n': ");                               // read number from user
 scanf("%d",&num);                                                 // scan entered value store in &num

 if(num > 1)                                                       // to check enter number +ve or -ve 
 { 
   int prime[num+1];                                               // declare the int array varible
 
 for(int i = 1 ; i <= num ; i++)                                   // using loop i less than equal num its true is i value increment
 {
  if(prime[num+1]) 
      
   prime[i]=i;                                                     // prime array stored in index i=1,2,3,4....  
   
 }
 for(int i = 2; i*i <= num; i++)                                   // muliplication  lessthan equal to num and i value  increment                           
 {
    if(prime[i] != -1);                                            // prime array not equal to -1 print the value

    {
     for(int j = 2*i ; j <= num ; j += i )                         // i=2 to run another loop  to get j value  addition to i value j+=i 
      
         prime[j] = -1;                                              // to assume prime array j index value -1    
    }
 }
 printf("The primes less than or equal to %d are: ",num);          // to print the prime contents
 for (int i = 2; i<= num; i++)
 {
    if(prime[i] != -1)                                             // prime array index not equal to j=-1 value
    {        
     printf("%d, ",i);                                             // to print the prime numbers  
    }
 }
 
 }
 else
   {
    printf("Please enter a positive number which is > 1\n");      // enter number -ve to print the error message
   }
 return 0;
}
