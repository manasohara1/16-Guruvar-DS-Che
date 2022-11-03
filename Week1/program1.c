/////////////////////////////////////////////////////////////////////////////////
//				Jay Ganesh
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////
// WAP to accept 5 no.s from user and store it into array and display.
///////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
////////////////////////////////////////////////////////
//Function Name:    Display
//Description:      Display array elements 
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
	int arr[10];
	register int iCnt = 0;
	for(iCnt = 0 ; iCnt < 10; iCnt++ )
	{
		printf("Enter %d element",iCnt+1);
		scanf("%d",&arr[iCnt]);
	}
	Display(arr,10);
	return 0;
}	
