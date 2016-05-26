#include "cll.h"
using namespace std;

//default constructor
cll::cll()
{
	rear = NULL;
}


//destructor
cll::~cll()
{
	remove_all(rear);	
}


//copy constructor
cll::cll(const cll & source)
{
	copy_wrapper(source.rear,rear);		//calling copy function
}

//cll copy wrapper
void cll::copy_wrapper(const node * source, node *& dest)
{
	copy(source,source,dest);
}


//cll copy
void cll::copy(const node * source,const node * source_temp,node *& dest)
{
	if(source == NULL)
	{
		dest = NULL;
		return;
	}

	if(source_temp->go_next() == source)
	{
		dest = new node(source);
		dest->set_next(rear);
		return;
	}
	dest = new node(source_temp);
	return copy(source,source_temp->go_next(),dest->get_next());
}


//PRACTICE CONST
/*
   cll::cll(const cll & source)
   {
   const node * temp = source.rear;
   temp = temp->go_next();

   }
 */

//attaching the lll back together
void cll::sew_cll(node *& rear,node *& rear2)
{
	if (rear == NULL)
		return;
	if (rear->get_next() != NULL)
		sew_cll(rear,rear2->get_next());
	else
		rear2->get_next() = rear;
}



//remove all
void cll::remove_all(node *& rear)
{
	if (rear == NULL)
		return;
	node * temp = rear;
	rear = rear->get_next();
	temp->get_next() = NULL;
	node * current = rear->get_next();
	remove_all_lll(rear);
	rear = NULL;
}



//remove all for lll
void cll::remove_all_lll(node *& head)
{
	if (head == NULL)
		return;
	
	remove_all_lll(head->get_next());
	delete head;
}


//equals operator
cll & cll::operator =(const cll & s)
{
	copy_wrapper(s.rear,rear);			//sending source and empty rear ptr to the copy function
}




//+= operator
cll & cll::operator +=(const song & s)
{
	insert(s);		//calling the function to insert, so know you can use the +=
}


//insert function
void cll::insert(const song & to_insert)
{
	if (rear == NULL)
	{
		rear = new node(to_insert);
		rear->get_next() = rear;
		return;
	}

	//turning into LLL
	node * temp = rear;
	rear = rear->get_next();
	temp->get_next() = NULL;

	node * current = new node(to_insert);
	current->set_next(rear);			//setting next to head
	rear = current;
	temp->get_next() = rear;
	rear = temp;
}


//displaying for cll
ostream & operator << (ostream & o, const cll & s)
{
	if (s.rear == NULL)
		return o;
	else
	{
		node * current = s.rear;
		do
		{
			o << *current; 
			current = current->get_next();
		}
		while (current != s.rear);
	}
	return o;
}

