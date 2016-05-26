
#include "graph.h"
using namespace std;

//default constructor
graph::graph()
{

}


//graph copy constructor
graph::graph(int size)
{
	adjacency_list = new vertex *[size];
	for(int i = 0;i< size;++i)
	{
		adjacency_list[i] = NULL;
//		adjacency_list[i]->go_head() = NULL;
//		adjacency_list[i]->get_genre() = NULL;
	}
	this->size = size;

	char temp2[] = "oldies";
	mystring temp = mystring(temp2);
	adjacency_list[0] = new vertex(temp);
	

/*
	char temp3[] ="r&b";
	temp = mystring(temp3);
	adjacency_list[1] = new vertex(temp);


	char temp4[] = "rap";
	temp = mystring(temp4);
	adjacency_list[2] = new vertex(temp);

	char temp5[] ="bollywood";
	temp = mystring(temp5);
	adjacency_list[3] = new vertex(temp);

	char temp6[] = "classic";
	temp = mystring(temp6);
	adjacency_list[4] = new vertex(temp);

	char temp7[] = "love";
	temp = mystring(temp7);
	adjacency_list[5] = new vertex(temp);

	char temp8[] = "country";
	temp = mystring(temp8);	
	adjacency_list[6] = new vertex(temp);
*/
}




//copy function
graph::graph(const graph &)
{
	
}


//default constructor
graph::~graph()
{

}



//insert function of vertex
void graph::insert_vertex(vertex & insert_song)
{

	int index = insert_song.get_index(insert_song,0);	//inserting the vertex based on the right genre
	int index2 = insert_song.get_index(insert_song,1);
	
//adding to the tail
	vertex * temp = new vertex(insert_song);
	vertex * c = adjacency_list[index];		//inserting at the end of the lll
	insert_last(c,temp);

/*
	while(c->go_next())
		c=c->go_next();
	c->go_next() = temp;
*/

	vertex * current = new vertex(insert_song);
	vertex * p = adjacency_list[index2];


	insert_last(p,current);
/*
	while(p->go_next())
		p = p->go_next();
	p->go_next() = current;	
*/

	current->insert(adjacency_list[index]);
	temp->insert(adjacency_list[index2]);

}


//recursive adjacency list
void graph::insert_last(vertex * head,vertex * insert)
{
	if (head == NULL)
	{
		head = insert;
		return;
	}

	if (head->go_next() == NULL)
	{	
		head->go_next() = insert;
		return;
	}
	return insert_last(head->go_next(),insert);
}


//insert function
graph & graph::operator +=(const song & to_insert)
{
	vertex temp(to_insert);
	insert_vertex(temp);
}


//display function
ostream & operator << (ostream & o,const graph & s)
{
	for(int i = 0; i<s.size;++i)
	{
		if(s.adjacency_list[i]->go_next() != NULL)
		{
			o << "Genre " << s.adjacency_list[i]->get_genre(i) << "has these songs ";

			vertex * current = s.adjacency_list[i]->go_next();		//assigning to first vertex in lll
			while (current != NULL)
			{
				//s.display_adjacency_assist(o,current);
				o << *current;
				o << '\t';
				current->go_next();
			}

			o << endl << endl;
			return o;
		}
	}
}


//assiting shit
void graph::display_adjacency_assist(ostream & o, vertex * head) const
{
	if (head == NULL)
		return;
	else
	{
		o << *head;
		return;
	}
//	return display_adjacency_assist(o,head->go_next());
}
