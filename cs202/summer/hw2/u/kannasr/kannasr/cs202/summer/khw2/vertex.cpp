/*
VERTEX.CPP
*/


#include "vertex.h"


vertex::vertex()
{
	head = NULL;
}


vertex::vertex(const vertex & vertex_obj):path(vertex_obj)
{


}


vertex::~vertex()
{


}



void vertex::display()
{

}


edge *& vertex::get_head()
{
	return head;
}
