/*
name: vetrivel.p
date: 13/07/2022
description: A32 - Print the values in sorted order without modifying or copying array
sample i/p and o/p:

Test Case 1:
user@emertxe] ./sort
Enter the size : 5
Enter 5 elements
10 1 3 8 -1
After sorting: -1 1 3 8 10
Original array values 10 1 3 8 -1

Test Case 2:
user@emertxe] ./sort
Enter the size : 7
Enter 7 elements
1 3 2 5 4 7 6
After sorting: 1 2 3 4 5 6 7
Original array values 1 3 2 5 4 7 6

Test Case 3:
user@emertxe] ./sort
Enter the size : 4
Enter 4 elements
-1 -2  4 3
After sorting: -2 -1 3 4
Original array values -1 -2  4 3
*/

#include<stdio.h>

void sorted_array(int *ptr,int size)
{
    // variable declaration
    int i,j,temp1,temp2= -99999999;
    
    // display the sorting 
    printf("After sorting:");
    for(i=0;i<size;i++)
    {
        temp1=999999999;
        for(j=0;j<size;j++)
        {
            if(*(ptr+j) < temp1 && *(ptr+j) > temp2)
            {
                temp1= *(ptr+j);
            }
        }
       // printing elements in sorted array
        printf(" %d",temp1);
        temp2=temp1; // small elements find
    }

}

int main()
{
    // variable declaration
    int size,i;
    
    // read size from user
    printf("Enter the array: ");
    scanf("%d",&size);
    
    // array into size
    int array[size];
    
    // enter the elements 
    printf("Enter %d elements\n",size);
    for(i=0;i<size;i++)
    {

        scanf("%d", &array[i]);
    } 
    
    // function call
    sorted_array(array,size);
    
    // display the results
    printf("\nOriginal array values");
    for(i=0;i<size;i++)
    {

        printf(" %d", array[i]);
    }

    printf("\n");
    
    return 0;
}


