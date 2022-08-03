/*
name: vetrivel.p
date:20/06/2022
description:
sample i/p and o/p:

*/

#include<stdio.h>

int main()

{
  //varaiable declaration
  int num,N,M,mask=1;

  // read from the user
  printf("Enter the number: ");
  scanf("%d",&num);

  printf("Enter 'N': ");
  scanf("%d",&N);

  printf("Enter 'M': ");
  scanf("%d",&M);
  // to get bit opration with mask value,mask number genarate nth value
  if(num & mask << N) 
  {
  // condition is true then clear mth postion bit
    num=num & ~(1 << M);
  // to print the updated number
    { 
      printf("Updated value of num is %d\n",num);
    } 
  }        
    else
    {
       printf("Display the number as it is\n");
    }
  
  return 0;


}
