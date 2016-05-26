#include "arraylll.h"



table::table(int size)
{
	hash_table = new node*[size];
	for(int i =0;i<size;++i)
	{
		hash_table[i] = NULL;
	}
	hash_table_size = size;
	srand(time(NULL));
}



table::~table(void)
{
	for(int i = 0;i<hash_table_size;++i)
	{
		node * temp = hash_table[i];
	
		while(hash_table[i] != NULL)
		{
			hash_table[i] = hash_table[i]->next;
			delete temp;	
			temp = hash_table[i];
		}
		hash_table[i] = NULL;
	}
	delete [] hash_table;
}


int table::random(int random)
{
	random =(rand()%50);
	return random;
}



void table::insert(node *& head)
{
	int num = 0;
	num = random(num);


	for(int j = 0;j<hash_table_size;++j)		//loop through the index
	{
		int insert_data = random(num);
		for(int i = 0;i<insert_data;++i)		//loop through the array specific index and insert the specific number of nodes
		{

			if (hash_table[i] == NULL)
			{
				hash_table[i] = new node;
				hash_table[i]->data = random(insert_data);
				hash_table[i]->next = NULL;
			}
			else
			{
				node * temp = new node;
				temp ->data = random(insert_data);
				temp->next = hash_table[i];
				hash_table[i] = temp;
			}
		}
	}
}


void table::display()
{
	for (int i = 0;i<hash_table_size;++i)
	{
		if (hash_table[i] == NULL)
			return;
		node * temp = hash_table[i];
		cout << "The index is " << i << " ";
		if (hash_table[i] != NULL)
		{
			while(temp != NULL)
			{
				cout << temp->data << '\t';
				temp = temp->next;
			}
		}
		cout << endl;
	}
}
