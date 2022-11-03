/////////////////////////////////////////////////////////////////////////////////
//				Jay Ganesh
////////////////////////////////////////////////////////////////////////////////
import java.lang.*;
import java.util.*;
//////////////////////////////////////////////////////////////////////////////
// Binary Search Algorithm
/////////////////////////////////////////////////////////////////////////////
class Array
{
	protected int arr[];
	protected Scanner sobj = new Scanner(System.in);
	
	//constructor
	Array(int iSize)
	{
		arr = new int[iSize];
	}
	/////////////////////////////////////////////////////////
	//Function Name:    Accept
	//Description:      accept array elements
	//Input:            ---
	//Output:           ---
	//Date:             03/11/2022
	//Author:           Manas Ohara
	////////////////////////////////////////////////////////
	protected void Accept()
	{
		System.out.println("--------------------------------------");
		System.out.println("Enter "+arr.length+" elements in array");
		System.out.println("--------------------------------------");
		for(int iCnt = 0 ; iCnt < arr.length ; iCnt++ )
		{
			System.out.println("Enter element "+(iCnt+1)+" : ");
			arr[iCnt] = sobj.nextInt();
		}
		System.out.println("--------------------------------------");
	}
	/////////////////////////////////////////////////////////
	//Function Name:    Display
	//Description:      display array elements
	//Input:            ---
	//Output:           ---
	//Date:             03/11/2022
	//Author:           Manas Ohara
	////////////////////////////////////////////////////////
	protected void Display()
	{
		System.out.println("Array elements are : ");
		for(int iCnt = 0 ; iCnt < arr.length ; iCnt++ )
		{
			System.out.print(arr[iCnt]+"\t");
		}
		System.out.println("\n--------------------------------------");
	}	
	
	protected void finalize()
	{
		arr = null;
		System.gc();
	}
}
class MyArray extends Array
{
	//constructor
	MyArray(int iSize)
	{
		//use of inheritance concept
		// calling parent class constructor using super()
		super(iSize);
	}
	
	/////////////////////////////////////////////////////////
	//Function Name:    LinearSearch
	//Description:      perform linear search algorithm
	//Input:            int
	//Output:           boolean
	//Date:             03/11/2022
	//Author:           Manas Ohara
	////////////////////////////////////////////////////////
	protected boolean LinearSearch(int iSearch)
	{
		boolean bRet = false;
		
		for(int iCnt = 0 ; iCnt < arr.length ; iCnt++)
		{
			if( arr[iCnt] == iSearch )
			{
				//set flag to true --> as element found
				bRet = true;
				break;
			}	
		}
		return bRet;
	}
	/////////////////////////////////////////////////////////
	//Function Name:    BinarySearch
	//Description:      perform binary search algorithm
	//Input:            int
	//Output:           boolean
	//Date:             03/11/2022
	//Author:           Manas Ohara
	//*Note:	    For binary search algorithm array should be sorted
	////////////////////////////////////////////////////////
	protected boolean BinarySearch(int iSearch)
	{
		//sorting array 
		Arrays.sort(arr);
		
		boolean bRet = false;
		int iStart = 0;
		int iMiddle = 0;
		int iEnd = arr.length-1;
		while( iStart <= iEnd)
		{
			iMiddle = (iStart+iEnd)/2;
			
			if( arr[iMiddle] == iSearch )
			{
				bRet = true;
				break;
			}
			else if( iSearch < arr[iMiddle] )
			{
				iEnd = iMiddle -1;
			}
			else if( iSearch > arr[iMiddle] )
			{
				iStart = iMiddle + 1;
			}
		}
		return bRet;
	}
	
	
	
}
class program16
{
	public static void main(String argmnts[])
	{	
		int iSize = 0;
		int iSearch = 0;
		Scanner sobj = new Scanner(System.in);
		System.out.println("Enter size of array : ");
		iSize = sobj.nextInt();
		
		//creation of object of MyArray class
		MyArray mobj = new MyArray(iSize);
		mobj.Accept();
		mobj.Display();
		
		System.out.println("Enter element to search : ");
		iSearch = sobj.nextInt();
		
		if(mobj.BinarySearch(iSearch))
		{
			System.out.println("Element found in an array");
		}	
		else
		{
			System.out.println("Elment not found in an array");
		}
	}
}
