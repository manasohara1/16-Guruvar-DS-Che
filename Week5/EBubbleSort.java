////////////////////////////////////////
// Jay Ganesh
///////////////////////////////////////
import java.lang.*;
import java.util.*;
///////////////////////////////////////
// Implementation of Efficient Bubble Sort
//////////////////////////////////////
class Array
{
	int arr[];
	Scanner sobj = new Scanner(System.in);
	Array(int iSize)
	{
		arr = new int[iSize];
	}
	public void Accept()
	{
		System.out.println("Enter "+arr.length+"elements : ");
		for(int iCnt = 0 ; iCnt < arr.length ; iCnt++ )
		{
			System.out.println("Enter element"+(iCnt+1)+" : ");
			arr[iCnt] = sobj.nextInt();
		}
	}
	public void Display()
	{
		System.out.println("\nArray elements are : ");
		for(int element : arr )
		{
			System.out.print(element+"\t");
		}
	}
	
	public void bubble_sort()
	{
		boolean swap = false;
		for(int iCnt = 0 ; iCnt < arr.length ; iCnt++ )
		{
			swap = false;
			for( int jCnt = 0; jCnt < arr.length-iCnt-1; jCnt++ )
			{
				if( arr[jCnt] > arr[jCnt+1] )
				{
					int iTemp = arr[jCnt];
					arr[jCnt] = arr[jCnt+1];
					arr[jCnt+1] = iTemp;
					swap = true;
				}
			}
			System.out.println("After pass"+(iCnt+1)+" : \n");
			Display();
			if( swap == false )
			{
				break;
			}
		}
	}
	
}
class EBubbleSort
{
	public static void main(String args[])
	{
		int iSize = 0;
		Scanner sobj = new Scanner(System.in);
		System.out.println("Enter size of array : ");
		iSize = sobj.nextInt();
		Array arr = new Array(iSize);
		arr.Accept();
		arr.Display();
		arr.bubble_sort();
	}
}
