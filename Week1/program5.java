/////////////////////////////////////////////////////////////////////////////////
//				Jay Ganesh
////////////////////////////////////////////////////////////////////////////////
import java.lang.*;
import java.util.*;
/////////////////////////////////////////////////////////
//Function Name:    ---
//Description:      OOP manners Matrix code 
//Input:            ---
//Output:           ---
//Date:             03/11/2022
//Author:           Manas Ohara
////////////////////////////////////////////////////////
class Matrix
{
	protected int arr[][];
	protected int iRow = 0 , iCol = 0;
	protected Scanner sobj = new Scanner(System.in);
	Matrix(int iRow,int iCol)
	{
		this.iRow = iRow;
		this.iCol = iCol;
		arr = new int[iRow][iCol];
	}
	protected void Accept()
	{
		for(int iCnt = 0 ; iCnt < arr.length ; iCnt++ )
		{
			for(int jCnt = 0 ; jCnt < arr[iCnt].length ; jCnt++ )
			{
				System.out.println("Enter ["+iCnt+"]["+jCnt+"] element : ");
				arr[iCnt][jCnt] = sobj.nextInt();
			}
		}
	}
	protected void Display()
	{
		System.out.println("Matrix elements are : ");
		for( int iCnt = 0 ; iCnt < arr.length ;iCnt++ )
		{
			for( int jCnt = 0 ; jCnt < arr[iCnt].length ; jCnt++ )
			{
				System.out.print(arr[iCnt][jCnt]+"\t");
			}
			System.out.println();
		}
	}
	protected void finalize()
	{
		arr = null;
		System.gc();
	}
}
class program5
{
	public static void main(String argmnts[])
	{	
		int iRow = 0, iCol = 0;
		Scanner sobj = new Scanner(System.in);
		System.out.println("Enter number of rows & cols : ");
		iRow = sobj.nextInt();
		iCol = sobj.nextInt();
		
		//Craetion of matrix class object
		Matrix mobj = new Matrix(iRow,iCol);
		mobj.Accept();
		mobj.Display();
	}
}
