/*
name: vetrivel.p
date: 13/07/2022
description: A27 - WAP to find 3rd largest element in an array
sample i/p and o/p:
Test Case 1:
Enter the size of the Array : 5
Enter the elements into the array: 5 1 4 2 8
Third largest element of the array is 4
Test Case 2:
Enter the size of the Array : 4
Enter the elements into the array: 66 22 11 3
Third largest element of the array is 11
*/

#include <stdio.h>

int third_largest(int [], int);

int main()
{
    // varible declaration
    int size, ret;

    // Read size from the user
    printf("Enter the size of the array :");
    scanf("%d", &size);
    
    // size stored in array
    int arr[size];

    //funtion call
    ret = third_largest(arr, size);
 
    // display the results
    printf("Third largest element of the array is %d\n", ret);
}

int third_largest(int arr[], int size)
{   
    // local variables       
    int first;        
    int second;
   
    // read element of the array from user    
    printf("Input %d elements in the array : ", size);
    
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    // find second largest element 
    for (int i = 0; i < size; ++i)
    {
        if (first < arr[i])
        {
            second = first;
            
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] != first)
        {            
            second = arr[i];        
        }
    }
    // find third largest elements
    int third = 0;
    
    for (int i = 0; i < size; i++)
        
        if (arr[i] > third && arr[i] < second)
            
            third = arr[i];

    return third;
    
}

