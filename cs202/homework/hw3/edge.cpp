//EDGE.CPP
#include "edge.h"
using namespace std;


//default constructor
edge::edge()
{
	adjacent = NULL;
	next = NULL;
}


//copy constructor
edge::edge(const edge &)
{


}


//deconstructor
edge::~edge()
{
	next = NULL;
	adjacent = NULL;
}

//getter of the next
edge *& edge::go_next()
{
	return next;		
}


//return adjacent ptr
vertex *& edge::go_adjacent()
{
	return adjacent;
}

//setter of next ptr
void edge::set_next(edge * source)
{
	next = source;
}

