
/*
name: vetrivel.p
date: 12/06/2022
description: A8 - WAP to print pyramid pattern as shown below
sample i/p and o/p:
Test Case 1:
Enter the number: 4
4
3 4
2 3 4
1 2 3 4
2 3 4
3 4
4
Test Case 2:
Enter the number: 5
5
4 5
3 4 5
2 3 4 5
1 2 3 4 5
2 3 4 5
3 4 5
4 5
5
 
 */

#include<stdio.h>

int main()
{
   //variable declaration
   
    int i ,j,num;

   //read num from the user
   
    printf("enter the number:");
        
    scanf("%d",&num);

   // prints the upper case pattern depents on value     

    for (i=num ; i>=1 ; i--)
{

   for(j=i ; j<=num ; j++)

          
    //int numbers printing
   {   
       printf("%d ",j);

   }


   {

   printf("\n");

} 
   // prints the lower case pattern depents on value     
}
for(i=2 ; i<=num ; i++)

    {
        for(j=i ; j<=num ; j++)
        
        // int numbers printing
        
        {                    
            printf("%d ",j);

        }
      

{
        printf("\n");
    }

}
return 0;

}

