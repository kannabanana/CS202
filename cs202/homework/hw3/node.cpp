/*
SR Kanna
NODE.CPP
*/
#include "node.h"
using namespace std;

//node default constructor
node::node():song()
{
	next = NULL;
}


//deconstructor
node::~node()
{
	next = NULL;
}


//calls song's copy constructor
node::node(const node & source):song(source)
{

}


//copy constructor of node ptr
node::node(const node * node_obj):song(node_obj)
{

}


//copy constructor - takes song object
node::node(const song & song_obj):song(song_obj)
{

}


//return next ptr
node *& node::get_next()
{
	return next;
}


//const object
const node * node::go_next() const
{
	return next;
}

//set next
void node::set_next(node * source)
{
	next = source;
}
