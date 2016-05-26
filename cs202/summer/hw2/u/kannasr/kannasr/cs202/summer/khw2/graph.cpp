/*
GRAPH.CPP

SR Kanna
HW1&2
CS202
7/11/2015

*/

#include "graph.h"
//default constructor
graph::graph(int size)
{
	adjacency_list = new vertex[size];
	for(int i  = 0;i<size;++i)
	{
		adjacency_list[i].get_head() = NULL;
		adjacency_list[i].set_name(0);
		adjacency_list[i].set_before(0);
	}
	this->size = size;
}



//copy a graph
graph::graph(const graph & graph_obj)
{

}


//destructor
graph::~graph()
{
	for(int i =0; i<size;++i)
	{
		edge * temp = adjacency_list[i].get_head();
		while(temp != NULL)
		{
			adjacency_list[i].get_head() = adjacency_list[i].get_head()->go_next();
			delete temp;
			temp = adjacency_list[i].get_head();
		}
		adjacency_list[i].get_head() = NULL;

	}
	delete [] adjacency_list;
}



/*
//reading in from vertex file
void graph::read_in_vertex()
{
	vertex vertex_obj;
	ifstream file_in;
	file_in.open("vertex.txt");
	if(!file_in)
		return;
	else
	{
		int vertex_name;
		while(!file_in.eof())
		{
			vertex_name = vertex_obj.get_name();
			cout << "This is the name of the vertex " << vertex_name << " ";
			file_in >> vertex_name;
			file_in.ignore(100,';');

			insert_vertex(vertex_obj.get_name());
		}
	}
}




//insert vertex
int graph::insert_vertex(int real_name)
{
	for(int i =0;i<size;++i)
	{
		if(adjacency_list[i].get_name() == 0)
		{
			adjacency_list[i].set_name(real_name);
			return 1;
		}
	}		
	return 0;
	
}
*/


void graph::insert_vertex()
{
	for(int i=0;i<5;++i)
	{
		adjacency_list[i].set_name(i+1);
	}
}



void graph::print()
{
	for(int i =0;i<5;++i)
	{
		cout << adjacency_list[i].get_name() << '\t';
	}
}


/*
void graph::read_in_edges()
{
	edge edge_obj;
	ifstream file_in;
	file_in.open("edge.txt");
	if(!file_in)
		return;
	else
	{
		int vertex1;
		int vertex2;
		while(!file_in.eof())
		{
			vertex1 = edge_obj.get_vertex1();
			cout << "This is vertex1 " << vertex1 << " ";
			file_in >> vertex1;	file_in.ignore(100,';');
		
			vertex2 = edge_obj.get_vertex2();
		//	cout << "This is vertex2 " << vertex2 << " ";
			file_in >> vertex2;
			file_in.ignore(100,'\n');

			insert_edge(edge_obj.get_vertex1(),edge_obj.get_vertex2());
		}
	}
}



int graph::find_location(int key_value)
{
	for(int i=0;i<size;++i)
	{
		if(adjacency_list[i].get_name() != 0)
		{
			if(adjacency_list[i].get_name() == key_value)
			{
				return i;
			}
		}
	}
	return -1;
}



void graph::insert_edge(int vertex1, int vertex2)
{
	int first = find_location(vertex1);
	int second = find_location(vertex2);
	if(first >= 0 && second >= 0)
	{
		edge * temp = new edge;
		temp->get_adjacent() = &adjacency_list[second];	//edge adjacent is pointed to the second one
		if (adjacency_list[vertex1].get_head() == NULL)			//if the edge list is null - make it hte first one
		{
			adjacency_list[vertex1].get_head() = temp;
			adjacency_list[vertex1].get_head()->go_next() = NULL;
		}
		else			//otherwise add at the end
		{
			edge * current = adjacency_list[vertex1].get_head();
			while(current->go_next() != NULL)
			{
				current = current->go_next();
			}
			current->go_next() = temp;
			temp->go_next() = NULL;
		}

	}
}
*/



//for loop - 
//for each index, create an edge (5) for each vertex
void graph::create_edges()
{
	for(int i = 0;i<5;++i)
	{		
		for (int j =0;j<5;++j)
		{
			edge * temp = adjacency_list[i].get_head();	
			if (temp == NULL)
			{
				temp = new edge;
				temp->get_adjacent() = &adjacency_list[j];
				temp->go_next() = NULL;
				adjacency_list[i].get_head() = temp;
			}
			else if (temp->go_next() == NULL)
			{
				temp = new edge;
				adjacency_list[i].get_head()->go_next() = temp;
				temp->get_adjacent()=&adjacency_list[j];
				temp->go_next() = NULL;
			}
			else
			{
				edge * current = adjacency_list[i].get_head();
				temp = new edge;
				while (current->go_next() != NULL)
				{
					current = current->go_next();
				}
				current->go_next() = temp;
				temp->get_adjacent() =&adjacency_list[j];
				temp->go_next() = NULL;
			}
		}
	}
}




//display edges next to adjacecy list
void graph::display_adjacency_list(void)
{
	for(int i =0;i<size;++i)
	{
			cout << "The vertex is " << adjacency_list[i].get_name() << " is connected to ";
			display_adjacency_assist(adjacency_list[i].get_head());
			cout << endl << endl << endl;
	}
}


//recursive function to display names in edge list of an adjacent index
void graph::display_adjacency_assist(edge * head)
{
	if(head == NULL)
		return;
	cout << head->get_adjacent()->get_name() << '\t';
	display_adjacency_assist(head->go_next());
}




//tell an edge they want removed
	//tell two numbers
//the linked list is empty
//it's the first one
//there is more than one
void graph::remove(int first,int second)
{
	first = first-1;
	second = second-1;
	if(adjacency_list[first].get_head() == NULL)
	{
		return;
	}

	else
	{
		edge * temp = adjacency_list[first].get_head();
	
		//check what it's attachig to is equivlanet to is the first node in the linked list

		if (second == 0)
//		if(adjacency_list[first].get_head()->get_adjacent() == adjacency_list[second].get_head())
		{
			edge * temp2 = adjacency_list[first].get_head()->go_next();
			delete adjacency_list[first].get_head();
			adjacency_list[first].get_head() = temp2;
		}

		else
		{
			edge * prev = NULL;
			edge * current = adjacency_list[first].get_head();
			
			for(int i = 1;i<second+1;++i)
			{
				prev = current;
				current = current->go_next();	
			}
				prev->go_next() = current->go_next();
				delete current;
				temp = NULL;
		}
	}
}

//retrieve


//the first time you traverse the tree
int * graph::ask(int * storage,int i)
{	
	
	int response = adjacency_list[i].ask_direction2(i);		//store their response

	storage[3] = adjacency_list[i].get_name();		//the name of the node in the first one
	int back = storage[3];
	edge * temp;

	if (response > 0)
	{
		if (i < 5)
			temp = adjacency_list[i].get_head();
		else
			temp = adjacency_list[back].get_head();
		
		for(int j = 1;j<response;++j)
		{
			temp = temp->go_next();
		}

		storage = traverse(temp,storage);	//calls the function to traverse the list
	}

	else	//want to go backwards
	{
		//find out what the third element is
		edge * temp = adjacency_list[back].get_head();
		for(int j = 1;j<response;++j)
		{
			temp = temp->go_next();
		}

		storage = traverse(temp,storage);	//calls the function to traverse the list
	}
		return storage;
}


//traverse the graph
int * graph::traverse(edge * temp,int * storage)
{
	if (temp == NULL)
	{
		storage[0] = 11;
		return storage;
	}
	else
	{
		//find the adjacent one it's pointing
		vertex * current = temp->get_adjacent();

		//send it into the path to find out it's even or odd
		storage = current->what_intersection(storage);
		storage = current->is_finish_line2(storage);

		//call the what_intersection function
		return storage;	
	}
}
