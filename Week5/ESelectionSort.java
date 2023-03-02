////////////////////////////////////////
// Jay Ganesh
///////////////////////////////////////
import java.lang.*;
import java.util.*;
///////////////////////////////////////
// Implementation of Efficient Selection Sort
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
	
	public void selection_sort()
	{
		int iMin_index = 0;
		for( int iCnt = 0 ; iCnt < arr.length - 1 ; iCnt++ )
		{
			iMin_index = iCnt;
			for( int jCnt = iCnt+1 ; jCnt < arr.length ; jCnt++ )
			{
				if( arr[iMin_index] > arr[jCnt] )
				{
					iMin_index = jCnt;
				}
			}
			if( iMin_index != iCnt )
			{
				int iTemp = arr[iMin_index];
				arr[iMin_index] = arr[iCnt];
				arr[iCnt] = iTemp;
			}
			System.out.println("\nAfter pass"+(iCnt+1)+" : ");
			Display();
		}
	}
	
}
class ESelectionSort
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
		arr.selection_sort();
	}
}
