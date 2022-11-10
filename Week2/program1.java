/////////////////////////////////////////////////////////////////////////////////
//				Jay Ganesh
////////////////////////////////////////////////////////////////////////////////
import java.lang.*;
import java.util.*;
//////////////////////////////////////////////////////////////////////////////
// Bi-directional Search Algorithm
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
	//Function Name:    Search
	//Description:      perform bi-directional search algorithm
	//Input:            int
	//Output:           boolean
	//Date:             10/11/2022
	//Author:           Manas Ohara
	////////////////////////////////////////////////////////
	protected boolean Search(int iSearch)
	{
		int iStart = 0;
		int iEnd = arr.length-1;
		boolean bRet = false;
		while(iStart <= iEnd)
		{
			if( arr[iStart] == iSearch )
			{
				bRet = true;
				break;
			}
			else if( arr[iEnd] == iSearch )
			{
				bRet = true;
				break;
			}
			else
			{
				iStart++;
				iEnd--;
			}
		}
		if( bRet == true )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

		
}
class program1
{
	public static void main(String argmnts[])
	{	
		System.out.println("Enter size of an array : ");
		Scanner sobj = new Scanner(System.in);
		int iSize = sobj.nextInt();
		MyArray obj = new MyArray(iSize);
		obj.Accept();
		obj.Display();
		System.out.println("Enter element to search : ");
		int iSearch = sobj.nextInt();
		if( obj.Search(iSearch) == true )
		{
			System.out.println("Element found in an array");
		}
		else
		{
			System.out.println("Element not found in an array");
		}
	}
}
