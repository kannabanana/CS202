//VERTEX.H

#include "song.h"
using namespace std;

#ifndef _VERTEX_H
#define _VERTEX_H

class edge;	//forward declaration

class vertex: public song		//derived from song - is a song (is a node)
{
public:
	vertex();			//default constructor
	vertex(const song &);
	vertex(const vertex &);		//copy constructor
	vertex(mystring a_genre);
	~vertex();			//deconstructor

//	void insert(const vertex * to_add);
	void insert(vertex * to_add);
	vertex *& go_next();		//return vertext ptr

	void set_next(vertex * source);	//a setter
//	void *& set_vertex(vertex *); const

	edge *& go_head();		//getter

//OPERATORS:
//	vertex & operator += (const song &);
//	vertex & operator += (const vertex *);

protected:
	edge * head;			//ptr to edge list
	vertex * next;			//next ptr of vertex
};

#endif
