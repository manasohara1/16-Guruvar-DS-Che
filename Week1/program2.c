/////////////////////////////////////////////////////////////////////////////////
//				Jay Ganesh
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////
// WAP to create dynmaic array and display the array elements
///////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
////////////////////////////////////////////////////////
//Function Name:    Accept
//Description:      Accept dynamic array elements 
//Input:            int *,int 
//Output:           ---
//Date:             03/11/2022
//Author:           Manas Ohara
////////////////////////////////////////////////////////
void Accept(int *arr,int iSize)
{
	register int iCnt = 0;
	for(iCnt = 0 ; iCnt < iSize ; iCnt++ )
	{
		printf("Enter element %d : ",iCnt+1);
		scanf("%d",&arr[iCnt]);
	}
}
////////////////////////////////////////////////////////
//Function Name:    Display
//Description:      Display dynamic array elements 
//Input:            int *,int 
//Output:           ---
//Date:             03/11/2022
//Author:           Manas Ohara
////////////////////////////////////////////////////////
void Display(int *arr,int n)
{
	register int iCnt = 0;
	printf("Array elements are : \t");
	for(iCnt = 0 ; iCnt < n ; iCnt++)
	{
		printf("%d\t",arr[iCnt]);
	}
	printf("\n");
}
/////////////////////////////////////////////////////////
int main()
{
	int *arr;
	int iSize = 0;
	
	printf("Enter the size of an array : ");
	scanf("%d",&iSize);
	arr =(int *) malloc(sizeof(int)*iSize);
	if(arr == NULL )
	{
		printf("Unable to allocate the memory\n");
	}
	else
	{
		Accept(arr,iSize);
		Display(arr,iSize);
	}
	return 0;
}	
