/////////////////////////////////////////////////////////
//		Jay Ganesh 
////////////////////////////////////////////////////////
#include<iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////
// Implementation of Generic Singly Linear Linked List
/////////////////////////////////////////////////////////////////////////////
template <class T>
struct node
{
	T data;
	struct node<T> *next;
};

//typedef struct node<T> NODE;

template <class T>
class GSLL
{
	private : struct node<T> * Head;
	
	public :
			GSLL();
			void InsertFirst(T);
			void InsertLast(T);
			void InsertAtPos(T,int);
			void DeleteFirst();
			void DeleteLast();
			void DeleteAtPos(int);
			void Display();
			int CountNodes();
			~GSLL();
};

template <class T>
GSLL<T>::GSLL()
{
	Head = NULL;
}

template <class T>
GSLL<T>::~GSLL()
{
	delete Head;
	Head = NULL;
}

template <class T>
void GSLL<T>::InsertFirst(T value)
{
	//Fill the data into new node
	struct node<T> * newn = new struct node<T>;
	newn->data = value;
	newn->next = NULL;
	
	//check whether Linked List is empty or not
	if( Head == NULL )
	{
		Head = newn;
	}
	else //Linked List is not empty
	{
		newn->next = Head;
		Head = newn;
	}
}

template <class T>
void GSLL<T>::InsertLast(T value)
{
	//fill the data into new node
	struct node<T> *newn = new struct node<T>;
	newn->data = value;
	newn->next = NULL;
	
	//check whether Linked List is empty or not
	if( Head == NULL )
	{
		Head = newn;
	}
	else // Linked List is not empty
	{
		//create a travelling node
		struct node<T> *temp = Head;
		
		//travel till before last node
		while( temp->next != NULL )
		{
			temp = temp->next;
		}
		
		//below statement is for location tracing puropose
		//cout<<"Now at node : "<<temp->data<<"\n";
		newn->next = temp->next;
		temp->next = newn;
	}
}

template <class T>
void GSLL<T>::InsertAtPos(T value,int iPos)
{	
	//validate the input position
	if( iPos <= 0 || iPos > CountNodes()+1 )
	{
		cout<<"Invalid Insertion position!!\n";
		return;
	}
	else if( iPos == 1 )
	{
		InsertFirst(value);
	}
	else if( iPos == CountNodes()+1 )
	{
		InsertLast(value);
	}
	else
	{
		//fill the data into new node
		struct node<T> *newn = new struct node<T>;
		newn->data = value;
		newn->next = NULL;
		
		//create a travelling node and travel till iPos-1 location
		struct node<T> *temp = Head;
		
		for(int iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
		{
			temp = temp->next;
		}
		
		//below statement is for location tracing
		//cout<<"Now at : "<<temp->data<<"\n";
		newn->next = temp->next ;
		temp->next = newn;	
	}
	
}

template <class T>
void GSLL<T>::DeleteFirst()
{
	//first check whether Linked List is empty or not
	if( Head == NULL )
	{
		cout<<"Linked List is empty!!\n";
		return;
	}
	//Linked List is not empty then...
	//create delnode  & assign to Head( the first node of Linked List)
	struct node<T> * delnode = Head;
	Head = delnode->next;
	delete delnode;
}

template <class T>
void GSLL<T>::DeleteLast()
{
	//first check whether Linked List is empty or not
	if( Head == NULL )
	{
		cout<<"Linked List is empty!!\n";
		return;
	}
	//Linked List is not empty then...
	//create travelling node and travel till before 2nd last node
	struct node<T> *temp = Head;
	while(temp->next->next != NULL )
	{
		temp = temp->next;
	}
	
	//below statement is for location tracing of Linked List node
	//cout<<"Now at : "<<temp->data<<"\n";
	
	//create a delnode for deletion of last node
	struct node<T> * delnode = new struct node<T>;
	//assign the last node into delnode
	delnode = temp->next;
	temp->next = NULL;
	delete delnode;
}

template <class T>
void GSLL<T>::DeleteAtPos(int iPos)
{
	//first validate the position
	if( (iPos <= 0) || (iPos > CountNodes() ) )
	{
		cout<<"Invalid position for deletion!!!\n";
		return;
	}
	else if(iPos == 1)
	{	
		DeleteFirst();
	}
	else if( iPos = CountNodes() )
	{
		DeleteLast();
	}
	else
	{
		//create a travelling node & travel till before iPos-1
		struct node<T> *temp = Head;
		
		for(int iCnt = 1 ; iCnt <= iPos-1 ; iCnt++ )
		{
			temp = temp->next;
		}
		
		//below statement is for location tracing of Linked List node
		cout<<"Now at : "<<temp->data<<"\n";
		
		//create a delnode and assign the current's next node to it
		struct node<T> *delnode = temp->next;
		temp->next = delnode->next;
		delete delnode;
	}
}

template <class T>
void GSLL<T>::Display()
{
	//check whether Linked List is empty or not
	if( Head == NULL )
	{
		cout<<"Linked List is empty!!";
		return;
	}
	//Create a travelling node to traverse Linked List
	struct node<T> *temp = Head;
	while(temp != NULL)
	{
		cout<<temp->data<<"-->";
		temp = temp->next;
	}
	cout<<"NULL\n";
}



template <class T>
int GSLL<T>::CountNodes()
{
	//counter to count nodes;
	register int iCnt = 0;
	
	//check whether Linked List is empty or not
	if( Head == NULL )
	{
		cout<<"Linked List is empty!!";
		return 0;
	}
	//Create a travelling node to traverse Linked List
	struct node<T> *temp = Head;
	while(temp != NULL)
	{
		iCnt++;
		temp = temp->next;
	}
	return iCnt;
}
int main()
{
	GSLL <float>obj;
	obj.InsertFirst(121.11);
	obj.InsertFirst(101.11);
	obj.InsertFirst(51.21);
	obj.InsertLast(151.21);
	obj.InsertAtPos(111.51,3);
	obj.InsertAtPos(11.31,1);
	obj.InsertAtPos(201.31,7);
	cout<<"Genric Singly Linked List after insertion : \n";
	obj.Display();
	//obj.DeleteFirst();
	//obj.DeleteLast();
	obj.DeleteAtPos(3);
	cout<<"Genric Singly Linked List after deletion : \n";
	obj.Display();
	return 0;
}
