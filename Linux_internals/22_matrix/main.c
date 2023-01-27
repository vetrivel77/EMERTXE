/*
NAME		: VETRIVEL P
DATE		: 20/1/2023
DESCRIPTION	:WAP to multiply two matrices using multiple threads
SAMPLE I/O	:
 1. ./matrix_mul 
Enter M1 rows and columns 3  3 
Enter M2 rows and columns 3  3
Enter M1 values 1  2  3  1  1  1  2  2  2
Enter M2 values 1  2  3  1  2  3  1  2  3 
Result is 
14 14 14 
6 6 6 
12 12 12

*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
//pthread_mutex_t lock;
typedef struct       // structure for data storing
{
	int **m1;
	int **m2;
	int **r;
	int row;
	int col;
	int row2;
	int ch_now;
}st;
void creat_matrix(int **matrix,int row, int col)  // memory allocation for matrix
{
	int i ;
	for(i = 0; i < row; i++)
	{
	matrix[i] = calloc(col,sizeof(int));
	}
}
void read_elements(int **matrix, int row, int col) // read elements to matrix
{
	int i,j;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
}
void *mul(void *param)  // function for matrix multiplication
{
st *info = param;
	int *ptr = calloc(info->row2 , sizeof(int));
	int row = (info->ch_now)++;
int sum = 0;
int arr[info->row2];
	for(int j = 0 ; j < info ->col; j++ )
	{
		info->r[row][j]=0;
		for(int k = 0; k < info->row2; k++)
		{
		info->r[row][j] += info->m1[row][k] * info->m2[k][j];
		}
	//	printf("%d ",info->r[row][j]);
	}
	//printf("\n");
}
int main()
{
	int *ptr;
	int row1,row2,col1,col2;
	printf("Enter 1st matrixrow,column size\n"); // size of matrix read
	scanf("%d %d",&row1,&col1);
	int *matrix1[row1];
	creat_matrix(matrix1,row1,col1);

	printf("Enter 2st matrixrow,column size\n");
	scanf("%d %d",&row2,&col2);
	int *matrix2[row2];
	creat_matrix(matrix2,row2,col2);
	if(col1 != row2)  // check column of 1st matrix equal to row size of 2nd matrix
	{
		printf("Error\n");
		return 1;
	}

	printf("Read elemnets for matrix1:");
	read_elements(matrix1,row1,col1);
	printf("Read elemnets for matrix2:");
	read_elements(matrix2,row2,col2);

	int *result[row1];
	creat_matrix(result,row1,col2); // memory allocation for result

	st td;   // structure variable created
	td.m1 = matrix1; // assign value to structure
	td.m2 = matrix2;
	td.r = result;
	td.row2 = row2;
	td.col = col2;
	td.row = row1;
	pthread_t td1,td2,td3,td4,td5;  // thread id creation
	pthread_t *arr[5] = {&td1,&td2,&td3,&td4,&td5};
	td.ch_now = 0;
	for(int i = 0; i < row1; i++)   // thread created for equal to 1st matrix row size
	{
		pthread_create(arr[i],NULL,mul,&td);
	}
	for(int i = 0; i < row1; i++)  // thread join
	{
		pthread_join(*arr[i],(void**)&ptr);
	}
	printf("Output matrix \n");
	for(int i = 0; i < row1; i++)  // result printed to terminal
	{
		for(int j = 0; j < col2; j++)
		{
			printf("%d ",result[i][j]);
		}
		printf("\n");
	}
	return 0;
}
