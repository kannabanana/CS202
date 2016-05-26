#include "vertex.h"
#ifndef _EDGE_H
#define _EDGE_H

class edge
{
	public:
		edge();
		edge(const edge & edge_obj);
		~edge();			//


		edge *& go_next();
		vertex *& get_adjacent();
		int get_vertex1();
		int get_vertex2();

	protected:
		edge * next;			//contains a next pointer
		vertex * adjacent;		//contains an adjacent pointer
		int vertex1;
		int vertex2;
};

#endif
