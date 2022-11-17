////////////////////////////////////////////////
//	Jay Ganesh
///////////////////////////////////////////////
#include<iostream>
using namespace std;
///////////////////////////////////////////////
// Implementation of Generic Doubly Linear Linked List
///////////////////////////////////////////////

template <class T>
struct node
{
	T data;
	struct node *prev;
	struct node *next;
};

template <class T>
class GDLL
{
	private : struct node<T> *Head;
	
	public : 
		 GDLL();
		 void InsertFirst(T);
		 void InsertLast(T);
		 void InsertAtPos(T,int);
		 void DeleteFirst();
		 void DeleteLast();
		 void DeleteAtPos(int);
		 void Display();
		 int CountNodes();
		 ~GDLL();
};

template <class T>
GDLL<T>::GDLL()
{
	Head = NULL;
}

template <class T>
void GDLL<T>::InsertFirst(T value)
{
	//assign the data into new node
	struct node<T> * newn = new struct node<T>;
	newn->data = value;
	newn->prev = NULL;
	newn->next = NULL;
	
	//check whether Linked List is empty or not
	if( Head == NULL )
	{
		//Linked List empty
		//assign new node as Head
		Head = newn;
	}
	else //Linked List is not empty
	{
		Head->prev = newn;
		newn->next = Head;
		Head = newn;
	}
}

template <class T>
void GDLL<T>::InsertLast(T value)
{
	//fill the data into new node
	struct node<T> * newn = new struct node<T>;
	newn->prev = NULL;
	newn->data = value;
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
		// so travel till before 2nd last node
		struct node<T> *temp = Head;
		while( temp->next != NULL )
		{
			temp = temp->next;
		}
		temp->next = newn;
		newn->prev = temp;
	}
}

template <class T>
void GDLL<T>::InsertAtPos(T value,int iPos)
{
	//validate the position input
	if( ( iPos <= 0 ) || ( iPos > CountNodes()+1 ) )
	{
		cout<<"Invalid position to insert data!!!\n";
		return;
	}
	else if( iPos == 1)
	{
		InsertFirst(value);
	}
	else if( iPos == CountNodes()+1)
	{
		InsertLast(value);
	}
	else
	{
		//fill the data into new node
		struct node<T> * newn = new struct node<T>;
		newn->prev = NULL;
		newn->data = value;
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
			// so travel till before 2nd last node
			struct node<T> *temp = Head;
			for(int iCnt = 1 ; iCnt < iPos-1 ; iCnt++ )
			{
				temp = temp->next;
			}
			newn->next =temp->next;
			newn->prev = temp;
			temp->next = newn;
		}
		
	}	
}

template <class T>
void GDLL<T>::DeleteFirst()
{
	//check whether Linked List is empty or not
	if( Head == NULL )
	{
		cout<<"Linked List is empty!!!\n";
		return;
	}
	//Linked List is not empty then 
	//assign Head to delnode
	struct node<T> * delnode = Head;
	Head = Head->next;
	Head->prev = NULL;
	delete delnode;
}

template <class T>
void GDLL<T>::DeleteLast()
{
	
	//check whether Linked List is empty or not
	if( Head == NULL )
	{
		cout<<"Linked List is empty!!!\n";
		return;
	}
	//Linked List is not empty then 
	//travel till last node
	struct node<T> *temp = Head;
	while( temp->next->next != NULL )
	{
		temp = temp->next;
	}
	
	//now at 2nd last node
	//cout<<"Now at : "<<temp->data<<"\n";
	struct node<T> *delnode = temp->next;
	temp->next = NULL;
	delete delnode;
}

template <class T>
void GDLL<T>::DeleteAtPos(int iPos)
{
	//validate the position input
	if( ( iPos <= 0 ) || ( iPos > CountNodes() ) )
	{
		cout<<"Invalid position to delete data!!!\n";
		return;
	}
	else if( iPos == 1)
	{
		DeleteFirst();
	}
	else if( iPos == CountNodes())
	{
		DeleteLast();
	}
	else
	{
		//travel till before iPos-1 node
		struct node<T> *temp = Head;
		for( int iCnt = 1 ; iCnt < iPos-1 ; iCnt++ )
		{
			temp = temp->next;
		}
		//cout<<"Now at : "<<temp->data;
		struct node<T> *delnode = temp->next;
		temp->next = delnode->next;
		delnode->next->prev = temp;
		delete delnode;
	}
}


template <class T>
void GDLL<T>::Display()
{
	//check Linked List is empty or not
	if( Head == NULL )
	{
		cout<<"Linked List is empty!!!\n";
		return;
	}
	//Linked List is not empty then
	//create a travelling node
	struct node<T> * temp  = Head;
	//travel till temp != NULL
	cout<<"NULL<-->";
	while(temp != NULL )
	{
		cout<<temp->data<<"<-->";
		temp = temp->next;
	}
	cout<<"NULL\n";
}

template <class T>
int GDLL<T>::CountNodes()
{
	int iCnt = 0;
	//check Linked List is empty or not
	if( Head == NULL )
	{
		return 0;
	}
	//Linked List is not empty then
	//create a travelling node
	struct node<T> * temp  = Head;
	//travel till temp != NULL
	while(temp != NULL )
	{
		iCnt++;
		temp = temp->next;
	}
	return iCnt;
}

template <class T>
GDLL<T>::~GDLL()
{
	delete Head;
	Head = NULL;
}


int main()
{
	GDLL <char>obj;
	obj.InsertFirst('S');
	obj.InsertFirst('A');
	obj.InsertFirst('N');
	obj.InsertFirst('A');
	obj.InsertFirst('M');
	obj.InsertLast('1');
	obj.InsertAtPos('$',4);
	obj.InsertAtPos('#',1);
	obj.InsertAtPos('#',9);
	obj.DeleteFirst();
	obj.DeleteLast();
	obj.DeleteAtPos(4);
	obj.DeleteLast();
	obj.Display();
	return 0;
}
