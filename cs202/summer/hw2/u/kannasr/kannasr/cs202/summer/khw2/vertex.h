/*
VERTEX.H

*/

#include "path.h"

#ifndef _VERTEX_H
#define _VERTEX_H

class edge;
class vertex:public path
{
	public:
		vertex();
		vertex(const vertex & vertex_obj);
		~vertex();

		
		edge *& get_head();
		void display();		//empty function - need it so this is not an abstract base class
	
	protected:
		edge * head;	
};

#endif
