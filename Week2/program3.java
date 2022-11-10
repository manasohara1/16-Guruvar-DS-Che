/////////////////////////////////////////////////////////////////////////////////
//				Jay Ganesh
////////////////////////////////////////////////////////////////////////////////
import java.lang.*;
import java.util.*;
//////////////////////////////////////////////////////////////////////////////
// Selection Sort Algorithm
/////////////////////////////////////////////////////////////////////////////
class Array
{
	protected int arr[];	
	protected Scanner sobj = new Scanner(System.in);
	
	//Array Constructor
	Array(int iSize)
	{
		arr = new int[iSize];
	}
	
	/////////////////////////////////////////////////////////
	//Function Name:    Accept
	//Description:      accept array elements
	//Input:            ---
	//Output:           ---
	//Date:             10/11/2022
	//Author:           Manas Ohara
	////////////////////////////////////////////////////////
	protected void Accept()
	{
		System.out.println("Enter "+arr.length+" elements : ");
		for(int iCnt = 0 ; iCnt < arr.length ; iCnt++ )
		{
			arr[iCnt] = sobj.nextInt();
		}
	}
	
	/////////////////////////////////////////////////////////
	//Function Name:    Display
	//Description:      display array elements
	//Input:            ---
	//Output:           ---
	//Date:             10/11/2022
	//Author:           Manas Ohara
	////////////////////////////////////////////////////////
	protected void Display()
	{
		System.out.println("Arr : ");
		for(int iCnt = 0 ; iCnt < arr.length ; iCnt++ )
		{
			System.out.print(arr[iCnt]+" ");
		}
		System.out.println();
	}
}
class MyArray extends Array
{
	//constructor
	MyArray(int iSize)
	{
		//call to parent constructor
		super(iSize);
	}
	
	
	/////////////////////////////////////////////////////////
	//Function Name:    Sort
	//Description:      perform selection sort algorithm
	//Input:            ---
	//Output:           ---
	//Date:             10/11/2022
	//Author:           Manas Ohara
	////////////////////////////////////////////////////////
	protected void Sort()
	{
		for(int iCnt = 0 ; iCnt < arr.length ; iCnt++ )
		{
			int iMin_index = iCnt;
			for(int jCnt = iCnt+1 ; jCnt < arr.length ; jCnt++ )
			{
				if(arr[iMin_index] > arr[jCnt] )
				{
					iMin_index = jCnt;
				}
			}
			if(iMin_index != iCnt )
			{
				int temp = arr[iMin_index] ;
				arr[iMin_index] = arr[iCnt];
				arr[iCnt] = temp;
			}
		}
		System.out.println("After implementing selection sort arr : \n");
		super.Display();
	}

		
}
class program3
{
	public static void main(String argmnts[])
	{	
		System.out.println("Enter size of an array : ");
		Scanner sobj = new Scanner(System.in);
		int iSize = sobj.nextInt();
		MyArray obj = new MyArray(iSize);
		obj.Accept();
		obj.Display();
		obj.Sort();
	}
}
