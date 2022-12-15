////////////////////////////////////////////////
//	Jay Ganesh
///////////////////////////////////////////////
#include<iostream>
using namespace std;
///////////////////////////////////////////////
// Implementation of Doubly Circular Linked List
///////////////////////////////////////////////
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node NODE;
typedef struct node * PNODE;

class DCLL
{
	private : 
			PNODE Head;
			PNODE Tail;
	
	public :
			DCLL();
			void InsertFirst(int);
			void InsertLast(int);
			void InsertAtPos(int,int);
			void DeleteFirst();
			void DeleteLast();
			void DeleteAtPos(int);
			void Display();
			int CountNodes();
			~DCLL();
};

//constructor of Doubly Circular Linked List
DCLL::DCLL()
{
	Head = NULL;
	Tail = NULL;
}

//destructor of Doubly Circular Linked List
DCLL::~DCLL()
{
	delete Head;
	delete Tail;
}

void DCLL::InsertFirst(int iNum)
{
	//Assign the data into new node
	PNODE newn = new NODE;
	newn->data = iNum;
	newn->next = NULL;
	newn->prev = NULL;
	
	//Now check whether Linked List is empty or not
	if ( ( Head == NULL ) && ( Tail == NULL ) )
	{
		Head = newn;
		Tail = newn;
	}
	else 
	{
		//This means that there is  node in Linked List
		newn->next = Head;
		newn->prev = Tail;
		Head->prev = newn;
		Head = newn;
	} 
	Head->prev = Tail;
	Tail->next = Head;
	
}

void DCLL::InsertLast(int iNum)
{
	//Assign the data into new node
	PNODE newn = new NODE;
	newn->data = iNum;
	newn->next = NULL;
	newn->prev = NULL;
	
	//check whether Linked List is empty or not
	if( ( Head == NULL ) && ( Tail == NULL ) )
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		Tail->next = newn;
		newn->next = Head;
		newn->prev = Tail;
		Tail = newn;
	}
	Head->prev = Tail;
	Tail->next = Head;
}
void DCLL::Display()
{
	if( ( Head == NULL ) && ( Tail == NULL ) )
	{
		cout<<"Linked List is empty\n";
		return;
	}
	else
	{
		PNODE temp = Head;
		cout<<"<-->";
		do{
			cout<<temp->data<<"<-->";
			temp = temp->next;
		}while(temp != Head);
	}
}

int DCLL::CountNodes()
{
	int iCnt = 0;
	if( ( Head == NULL ) && ( Tail == NULL ) )
	{
		cout<<"Linked List is empty\n";
		return 0;
	}
	else
	{
		PNODE temp = Head;
		do{
			iCnt++;
			temp = temp->next;
		}while(temp != Head);
		return iCnt;
	}
}

void DCLL::InsertAtPos( int iNum , int iPos )
{
	//check position before insert operation
	if( ( iPos <= 0 ) || ( iPos > CountNodes()+1 ) )
	{
		cout<<"Invalid position to insert";
		return;
	}
	else if( iPos == 1 )
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
		//create the travelling node
		PNODE temp = Head;
		for(int iCnt = 1 ; iCnt < iPos-1; iCnt++ )
		{
			temp = temp->next;
		}
		//Now assign the data into new node
		PNODE newn = new NODE;
		newn->data = iNum;
		newn->next = NULL;
		newn->prev = NULL;
		
		//now linking into Linked List
		newn->next = temp->next;
		newn->prev = temp;
		temp->next = newn;
		newn->next->prev = newn;
	}
}

void DCLL::DeleteFirst()
{
	//check whether Linked List is empty or not
	if( ( Head == NULL ) && ( Tail == NULL ) )
	{
		cout<<"Linked List empty";
		return;
	}
	else
	{
		PNODE delnode = Head;
		Head = delnode->next;
		delete delnode;
	}
	Head->prev = Tail;
	Tail->next = Head;
}

void DCLL::DeleteLast()
{
	//check whether Linked List is empty or not
	if( ( Head == NULL ) && ( Tail == NULL ) )
	{
		cout<<"Linked List empty";
		return;
	}
	else
	{
		PNODE prevnode = Tail->prev;
		prevnode->next = Head;
		PNODE delnode = Tail;
		Tail = prevnode;
		delete delnode;
	}
	Head->prev = Tail;
	Tail->next = Head;
}

void DCLL::DeleteAtPos(int iPos)
{
	//check position before delete operation
	if( ( iPos <= 0 ) || ( iPos > CountNodes() ) )
	{
		cout<<"Invalid position to insert";
		return;
	}
	else if ( iPos == 1)
	{
		DeleteFirst();
	}
	else if ( iPos == CountNodes() )
	{
		DeleteLast();
	}
	else
	{
		//other position
		//create a travelling node
		PNODE temp = Head;
		for( int iCnt = 1 ; iCnt < iPos-1 ; iCnt++ )
		{
			temp = temp->next;
		}
		PNODE delnode = temp->next;
		temp->next = delnode->next;
		delnode->next->prev = temp;
	}	
}

int main()
{
	DCLL obj;
	obj.InsertFirst(121);
	obj.InsertFirst(101);
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.InsertLast(151);
	obj.InsertAtPos(111,5);
	obj.InsertAtPos(73,3);
	obj.DeleteFirst();
	obj.DeleteLast();
	obj.DeleteAtPos(2);
	obj.Display();
	cout<<"\nTotal nodes are : "<<obj.CountNodes()<<endl;
	return 0;
}
