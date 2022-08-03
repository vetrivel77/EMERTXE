/*
name: vetrivel.p
date: 13/02/2022
description: A26 - WAP to find 2nd largest element in an array
sample i/p and o/p:
Test Case 1:
Enter the size of the Array : 5
Enter the elements into the array: 5 1 4 2 8
Second largest element of the array is 5
Test Case 2:
Enter the size of the Array : 4
Enter the elements into the array: 66 22 11 3
Second largest element of the array is 22

*/

#include <stdio.h>

int sec_largest(int [], int);

int main()
{
    // varible declaration
    int size, ret, i;
    
    // Read size from the user
    printf("Enter the size of the array :");
    scanf("%d", &size);
    
    // size stored into the array
    int arr[size];
    
    // Read elements into the array
    printf("Enter the elements into te array:");        
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // funtion call
    ret = sec_largest(arr, size);
    // display the results
    printf("Second largest element of the array is %d\n", ret);
}

int sec_largest(int arr[], int size)

{
    // initilise array 
    int small = arr[0];
    int large = arr[0];   
    int  sec_large = arr[0], i, j;    
    
    // to find smallest and largest array
    for(i=1; i< size ; i++)
    {                                 
        if( arr[i] < small)            
        {
                
            small = arr[i];            
            
        }
                           
        if(arr[i] > large)
            
        {
                
            large = arr[i];
            
        }      
    
    }
    
    // loop for finding 2nd largest number
    for(i=0; i < size ; i++)
    {                
        if(sec_large == large)
        {
            sec_large = arr[i + 1];
        }
        if(small != arr[i] && arr[i] != large && sec_large < arr[i])
        {
            sec_large = arr[i];
            
        }
    
    }
    return sec_large;
}
