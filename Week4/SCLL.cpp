////////////////////////////////////////////////
//	Jay Ganesh
///////////////////////////////////////////////
#include<iostream>
using namespace std;
///////////////////////////////////////////////
// Implementation of Singly Circular Linked List
///////////////////////////////////////////////
struct node{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SCLL
{
	private : 
			PNODE Head;
			PNODE Tail;
	
	public :
			SCLL();
			void InsertFirst(int);
			void InsertLast(int);
			void InsertAtPos(int,int);
			void DeleteFirst();
			void DeleteLast();
			void DeleteAtPos(int);
			void Display();
			int CountNodes();
			~SCLL();
};

//constructor of Singly Circular Linked List
SCLL::SCLL()
{
	Head = NULL;
	Tail = NULL;
}

//destructor of Singly Circular Linked List
SCLL::~SCLL()
{
	delete Head;
	delete Tail;
	//Head = NULL;
	//Tail = NULL;
}

void SCLL::InsertFirst(int iNum)
{
	//Assign the data into new node
	PNODE newn = new NODE;
	newn->data = iNum;
	newn->next = NULL;
	
	//check if Linked List is empty or not
	if( ( Head == NULL ) && (Tail == NULL ) )
	{
		//This means that Linked List is empty
		Head = newn;
		Tail = newn;
	}
	else
	{
		//This means that Linked List is not empty
		newn->next = Head;
		Head = newn;
	}
	Tail->next = Head;
}

void SCLL::InsertLast(int iNum)
{
	//Assign the new data into new node
	PNODE newn = new NODE;
	newn->data = iNum;
	newn->next = NULL;
	
	//check whether Linked List is empty or not
	if( ( Head == NULL ) && ( Tail == NULL ) )
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		Tail->next = newn;
		Tail = newn;
	}
	Tail->next = Head;
}

void SCLL::Display()
{
	//check if Linked List is empty or not
	if( ( Head == NULL ) && (Tail == NULL ) )
	{
		//This means that Linked List is empty
		cout<<"Linked List is empty !!!";
		return;
	}
	
	//Now Linked List is checked so assign the Head to travelling node
	PNODE temp = Head;
	//if there is only one node , then while loop will not work
	// so to at least go once into traversing used do-while approach
	do
	{
		cout<<"-->"<<temp->data<<"-->";
		temp = temp->next;
	}while(temp != Head);	
}

int SCLL::CountNodes()
{
	int iCnt = 0;
	//check if Linked List is empty or not
	if( ( Head == NULL ) && (Tail == NULL ) )
	{
		//This means that Linked List is empty
		return 0;
	}
	
	//Now Linked List is checked so assign the Head to travelling node
	PNODE temp = Head;
	//cout<<"-->";
	do{
		iCnt++;
		temp = temp->next;
	}while(temp != Head);	
	
	return iCnt;
}

void SCLL::InsertAtPos( int iNum , int iPos )
{
	//check the iPos input
	if( (iPos <= 0 ) || ( iPos > CountNodes()+1 ) )
	{
		cout<<"Invalid position to insert";
		return;
	}
	else if( iPos == 1)
	{
		InsertFirst(iNum);
	}
	else if( iPos == CountNodes()+1 )
	{
		InsertLast(iNum);
	}
	else
	{
		//other positions
		PNODE temp = Head;
		for(int iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
		{
			temp = temp->next;
		}
		//Fill the data into new node
		PNODE newn = new NODE;
		newn->data = iNum;
		newn->next = NULL;
		//data is filled 
		
		newn->next = temp->next;
		temp->next = newn;
		
		
	}
}

void SCLL::DeleteFirst()
{
	//check Linked List is empty or not
	if( ( Head == NULL ) && (Tail == NULL ) )
	{
		cout<<"Linked List is empty";
		return;
	}
	//now Linked List is not empty
	else if( Head == Tail )
	{
		//This means there is only one node
		//delete Head;
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		Head = Head->next;
		delete Tail->next;
		Tail->next = Head;
	}
}

void SCLL::DeleteLast()
{
	if( ( Head == NULL ) && ( Tail == NULL ) )
	{
		cout<<"Linked List is empty";
		return;
	}
	//now Linked List is not empty
	else if( Head == Tail )
	{
		//This means there is only one node
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		
		PNODE temp = Head;
		while(temp->next != Tail )
		{
			temp = temp->next;
		}
		PNODE delnode = temp->next;
		delete delnode;
		Tail = temp;
		Tail->next = Head;
	}
}

void SCLL::DeleteAtPos(int iPos)
{
	//check the position first
	if( ( iPos <= 0 ) || ( iPos > CountNodes() ) )
	{
		cout<<"Invalid position for deletion operation";
		return;
	}
	else if( iPos == 1)
	{
		DeleteFirst();
	}
	else if( iPos == CountNodes() )
	{
		DeleteLast();
	}
	else
	{
		//other positions
		//create the travelling node
		PNODE temp = Head;
		for(int iCnt = 1 ; iCnt < iPos-1; iCnt++ )
		{
			temp = temp->next;
		}
		PNODE delnode = temp->next;
		temp->next = delnode->next;
		delete delnode;
	}
}

int main()
{
	SCLL obj;
	obj.InsertFirst(121);
	obj.InsertFirst(101);
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.InsertLast(151);
	obj.InsertAtPos(111,5);
	obj.InsertAtPos(73,2);
	obj.DeleteAtPos(2);
	//obj.DeleteFirst();
	//obj.DeleteLast();
	obj.Display();
	cout<<"\nTotal nodes are : "<<obj.CountNodes()<<endl;
	return 0;
}
