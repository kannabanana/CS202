#include "edge.h"

//default construcotr
edge::edge()
{
	next = NULL;
	adjacent= NULL;
}


//copy construcor - IS THIS RIGHT?
edge::edge(const edge & edge_obj)
{
	this->next = edge_obj.next;
	this->adjacent = edge_obj.adjacent;
}


//destructor
edge::~edge()
{
	next = NULL;
	adjacent = NULL;
}


//getter of next
edge *& edge::go_next()
{
	return next;
}



//getter of adjacent
vertex *& edge::get_adjacent()
{
	return adjacent;
}


int edge::get_vertex1()
{
	return vertex1;
}


int edge::get_vertex2()
{
	return vertex2;
}
