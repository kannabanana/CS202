//VERTEX.CPP
#include "vertex.h"
#include "edge.h"
using namespace std;


//default constructor
vertex::vertex():song()
{	
	next = NULL;
	head = NULL;
}


//copy constructor for song
vertex::vertex(const song & copy):song(copy)
{

}


//copy constructor
vertex::vertex(const vertex & copy):song(copy)
{

}


//constructor
vertex::vertex(mystring a_genre)
{
	*(this->genre) = a_genre;
}

//deconstructor
vertex::~vertex()
{
	next = NULL;
	head = NULL;
}

/*
//+= operator
vertex & vertex::operator += (const vertex * s)
{
	insert(s);
}

///insert function
void vertex::insert(const vertex * to_add)
{
	head = new edge();
	head->set_vertex(to_add);		//setting the edge to to the next vertex in the edge list
}
*/


//insert an vertex into edge
void vertex::insert(vertex * to_add)
{
	head = new edge();
	head->go_adjacent() = to_add;
}


//go next
vertex *& vertex::go_next()
{
	return next;
}


//accessing the head ptr
edge *& vertex::go_head()
{
	return head;
}


//set next
void vertex::set_next(vertex * source)
{
	next = source;
}



/*
//set next
void *& vertex::set_vertex(vertex * source) const
{
	next = source;
}
*/
