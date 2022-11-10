/////////////////////////////////////////////////////////////////////////////////
//				Jay Ganesh
////////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////
// Implementation of Singly Linear Linked List
/////////////////////////////////////////////////////////////////////////////
//structure of node
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
typedef struct node * PNODE;

class SLL
{
	public : PNODE Head;
	
	public :
			SLL();
			void InsertFirst(int);
			void InsertLast(int);
			void InsertAtPos(int,int);
			void Display();
			void DeleteFirst();
			void DeleteLast();
			void DeleteAtPos(int);
			int Count();
			
			
};
SLL::SLL()
{
	Head = NULL;
}
void SLL::InsertFirst(int iNum)
{
	//creation of new node
	PNODE newn = new NODE;
	//filling the data in new node
	newn->data = iNum;
	newn->next = NULL;
	
	//check if LL is empty or not
	if( Head == NULL )
	{
		//Linked List is empty
		Head = newn;
	}
	else
	{
		//Linked List is not empty
		newn->next = Head;
		Head = newn;
	}
}
void SLL::InsertLast(int iNum)
{
	//filling data in new node
	PNODE newn = new NODE;
	newn->data = iNum;
	newn->next = NULL;
	
	//check Linked List is empty or not
	if( Head == NULL )
	{
		//Linked List is empty
		Head = newn;
	}
	else
	{
		//Linked List is not empty
		//travel till before last node
		//creating a travelling node
		PNODE temp = Head;
		while(temp->next != NULL )
		{
			temp = temp->next;
		}
		//now we are at before last node
		temp->next = newn;
	}
}
void SLL::InsertAtPos(int iNum, int iPos)
{
	//validating input position
	if( (iPos <= 0 ) || (iPos > Count()+1) )
	{
		cout<<"Invalid position to insert data";
		return;
	}
	
	//if position = 1 
	else if( iPos == 1)
	{
		InsertFirst(iNum);
	}
	//if position = last
	else if ( iPos == Count()+1 )
	{
		InsertLast(iNum);
	}
	//if position is other
	else
	{
		//fill the data in new node
		PNODE newn = new NODE;
		newn->data = iNum;
		newn->next = NULL;
		
		//create travelling node
		PNODE temp = Head;
		//travel till iPos-1
		register int iCnt = 0;
		for(iCnt = 1; iCnt < iPos-1 ; iCnt ++ )
		{
			temp = temp ->next;
		}
		//now at iPos-1 location
		newn->next = temp->next;
		temp->next = newn;
	}
}
void SLL::Display()
{
	if( Head == NULL )
	{
		cout<<"Linked list is empty!!\n";
	}
	else
	{
		PNODE temp = Head;
		while(temp != NULL )
		{
			cout<<temp->data<<"->";
			temp = temp->next;
		}
		cout<<"NULL";
	}
}
int SLL::Count()
{
	int iCnt = 0;
	if( Head == NULL )
	{
		cout<<"Linked list is empty!!\n";
		return 0;
	}
	else
	{
		PNODE temp = Head;
		while(temp != NULL )
		{
			iCnt++;
			temp = temp->next;
		}
		return iCnt;
	}
}
void SLL::DeleteFirst()
{
	//check Linked List is empty or not
	if( Head == NULL )
	{
		cout<<"Can not delete nodes because Linked List is empty";
		return;
	}
	//Linked List is not empty then...
	//create a delnode 
	PNODE delnode = Head;
	Head = delnode ->next;
	delete delnode;
}

void SLL::DeleteLast()
{
	//check Linked List is empty or not
	if( Head == NULL )
	{
		cout<<"Can not delete nodes because Linked List is empty";
		return;
	}
	//Linked List is not empty then...
	//create a travelling node
	//travel before last node
	PNODE temp = Head;
	while( temp->next->next != NULL )
	{
		temp = temp->next;
	}
	
	//now at before last node-1
	PNODE delnode = temp->next;
	temp->next = NULL ;
	delete delnode;
}
void SLL::DeleteAtPos(int iPos)
{
	//validating input position
	if( (iPos <= 0 ) || (iPos > Count()) )
	{
		cout<<"Invalid position to delete node";
		return;
	}
	
	//if position = 1 
	else if( iPos == 1)
	{
		DeleteFirst();
	}
	//if position = last
	else if ( iPos == Count()+1 )
	{
		DeleteLast();
	}
	//if position is other
	else
	{
		//create travelling node
		PNODE temp = Head;
		//travel till iPos-1 position
		register int iCnt = 0;
		for(iCnt = 1 ; iCnt < iPos-1; iCnt++ )
		{
			temp = temp->next;
		}
		//cout<<"Now at : "<<temp->data<<"\n";
		//create delnode
		PNODE delnode = temp->next;
		temp->next = delnode->next;
		delete delnode;
	}
}
int main()
{
	SLL obj;
	obj.InsertFirst(101);
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.InsertLast(121);
	obj.InsertLast(151);
	obj.InsertAtPos(91,4);
	obj.DeleteFirst();
	obj.DeleteLast();
	obj.DeleteAtPos(4);
	obj.Display();
}
