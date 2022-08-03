/*
name: vetrivel.p
date: 22/06/2022
description: A13 - WAP to find the median of two unsorted arrays
sample i/p and o/p:
Sample execution: -
Test Case 1: 

Enter the 'n' value for Array A: 5
Enter the 'n' value for Array B: 5

Enter the elements one by one for Array A: 3 2 8 5 4
Enter the elements one by one for Array B: 12 3 7 8 5

Median of array1 : 4
Median of array2 : 7
Median of both arrays : 5.5                         
Test Case 2:
Enter the 'n' value for Array A: 5
Enter the 'n' value for Array B: 4
Enter the elements one by one for Array A: 3 2 8 5 4
Enter the elements one by one for Array B: 12 13 7 5
Median of array1 : 4
Median of array2 : 9.5                                      
Median of both arrays : 6.75     

 */

#include<stdio.h>

int main()
{
  // variable and array declaration  
  int a,b,temp,x1,x2,index1,index2;
  int arr1[50];
  int arr2[50];
  float median1,median2,median;

  printf("Enter the 'n' value for Array A:");
  scanf("%d",&a);

  printf("Enter the 'n' value for Array B:");
  scanf("%d",&b);
  
  printf("Enter the elements one by one for Array A:");
   for(int i=0; i < a; i++)
   {
   scanf("%d",&arr1[i]);
   }
   
   printf("Enter the elements one by one for Array B:");   
   for(int i=0; i < b ; i++)
   {
   scanf("%d",&arr2[i]);
   }  
  // using bubble sorting method sorting arrays
   
   for(int i=0; i < a -1; i++)
   {
    
       for(int j=0; j < a - i -1; j++)
    
      {
          
         if(arr1[j] > arr1[j+1])       
          {
          temp = arr1[j];
          arr1[j] = arr1[j+1];
          arr1[j+1]= temp;
          }

       }
   
    }

    for(int i=0; i < b -1 ; i++)
    {
    
        for(int j=0; j < b - i -1; j++)

        {
        
           if(arr2[j] > arr2[j+1])
           {
            temp = arr2[j];
            arr2[j] = arr2[j+1];
            arr2[j+1] = temp;    
            }
                 
        }

    }
  // to find the median1 of sorted array
    
    if(a%2==0)
    {
    
        x1=(a-1)/2;
        x2=(a / 2);
        median1= (arr1[x1] + arr1[x2]) * 0.5;
    
    }
    else
    {     
        x1=(a/2);
        median1=arr1[x1];
    }
  // to find the median2 of sorted array
    
    if(b%2==0)
    {
        index1=(b-1)/2;
        index2=(b / 2);
        median2=(arr2[index1] + arr2[index2]) * 0.5;

    }
    else
    {    
        index1=(b/2);
        median2=arr2[index1];    
    }
  // to print the middle number of median1 and median2 arrays       
    printf("Median of array1: %g\n",median1);
    printf("Median of array2: %g\n",median2);
  // to find median1 and median2 both arrays   
    median= (median1 + median2) * 0.5;
    printf("median of both arrays: %g\n",median);

  return 0;  
}
