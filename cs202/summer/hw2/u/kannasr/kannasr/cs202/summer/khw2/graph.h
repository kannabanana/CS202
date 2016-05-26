/*
SR Kanna
HW1&2
GRAPH.H

*/

//#include <fstream>
#include "edge.h"
#ifndef _GRAPH_H
#define _GRAPH_H
class graph
{

	public:
		graph(int size =5);
		graph(const graph &);
		~graph();


		void read_in_vertex();
		void read_in_edges();
		int insert_vertex(int vertex);
		void insert_vertex();
		void insert_edge(int vertex1,int vertex2);
		void create_edges();
		int find_location(int key_value);
		void display_adjacency_list();
		void display_adjacency_assist(edge * head);
		int * traverse(edge *, int *);
		int * ask(int * storage,int i);
		void remove(int one,int two);


		void display();
		void print();
		void retrieve();
		void remove_all();
			

	protected:
		vertex * adjacency_list;
		int size;
};

#endif
