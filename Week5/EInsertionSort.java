////////////////////////////////////////
// Jay Ganesh
///////////////////////////////////////
import java.lang.*;
import java.util.*;
///////////////////////////////////////
// Implementation of Efficient Insertion Sort
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
	
	public void insertion_sort()
	{
		int iSelect = 0;
		int iCnt = 0;
		int jCnt = 0;
for( iCnt = 1 ; iCnt < arr.length ; iCnt++ )
{
	for( jCnt = iCnt-1 , iSelect = arr[iCnt] ; ( jCnt >= 0 ) && ( arr[jCnt] > iSelect ) ; jCnt-- )
	{
		arr[jCnt+1] = arr[jCnt];	
	}
	arr[jCnt+1] = iSelect;
	System.out.println("\nAfter pass"+iCnt+" : \n");
	Display();
}
	}
	
}
class EInsertionSort
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
		arr.insertion_sort();
	}
}
