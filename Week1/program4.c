/////////////////////////////////////////////////////////////////////////////////
//				Jay Ganesh
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////
// WAP to create dynmaic array and count only even elements from that Array
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
//Function Name:    CountEven
//Description:      Count dynamic array even elements 
//Input:            int *,int 
//Output:           int
//Date:             03/11/2022
//Author:           Manas Ohara
////////////////////////////////////////////////////////
int CountEven(int *arr,int n)
{
	register int iCnt = 0;
	int iEvenCount = 0;
	for(iCnt = 0 ; iCnt < n ; iCnt++)
	{
		if(arr[iCnt] % 2 == 0)
		{
			iEvenCount++;
		}
	}
	return iEvenCount;
}
////////////////////////////////////////////////////////
int main()
{
	int *arr;
	auto int iSize = 0;
	auto int count = 0;
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
		count = CountEven(arr,iSize);
		printf("Total no. of even elements from array are : %d\n",count);
	}
	return 0;
}	
