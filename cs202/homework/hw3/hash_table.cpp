#include "hash_table.h"
using namespace std;

//initialization list - array is given size of five
hash_table::hash_table()
{
	size = 0;
}


//constructor w/arguments
hash_table::hash_table(int size)
{
	table = new node *[size];
	for (int i = 0; i<size;++i)
	{
		table[i] = NULL;
	}
	this->size = size;
}


//copy constructor
hash_table::hash_table(const hash_table & copy)
{
	this->table= new node*[size];
	for (int i = 0; i< size;++i)
	{
		this->table[i] = NULL;
	}

	//copy the array size - dynamic array
	for(int i = 0; i < size; ++i)
	{
		node * temp = copy.table[i];
		copy_lll(temp,this->table[i]);
	}
}


//copy function
void hash_table::copy_lll(const node * source,node *& dest)
{
	if(source == NULL)
	{
		dest = NULL;
		return;
	}

	else
	{
		dest = new node(source);
		copy_lll(source->go_next(),dest->get_next());
	}
}


//destructor
hash_table::~hash_table()
{
	for(int i = 0; i< size; ++i)
	{
		node * temp = *(table+i);			//assigning temp ptr to head
		while (temp != NULL)
		{
			*(table+i) = (*(table+i))->get_next();	//setting head to head next
		//	delete [] temp->genre;			//deleting values inside temp *this is of string class- taken care of, besides ptr genre
			delete temp;
			temp = temp->get_next();
		}
	}
	delete [] table;
}



//hash function
int hash_table::hash_function(const mystring artist)
{
	int num = 0;
	int len = artist.get_strlen();
	for (int i = 0; i <len; ++i)
	{
		num+= artist[i];
	}
	int answer = (num%size);
	return answer;
}

//insert function


void hash_table::hash_insert(const mystring key_value,const song & to_insert)
{
	int index = hash_function(key_value);
	node * temp = new node(to_insert);
	temp->get_next() = table[index];
	table[index] = temp;
}

int hash_table::hash_function_nc(mystring artist)
{
	int num = 0;
	int len = artist.get_strlen();
	for (int i = 0; i <len; ++i)
	{
		num+= artist[i];
	}
	int answer = (num%size);
	return answer;
}

//insert function


void hash_table::hash_insert_nc(mystring key_value,song & to_insert)
{
	int index = hash_function(key_value);
	node * temp = new node(to_insert);
	temp->get_next() = table[index];
	table[index] = temp;
}

//OPERATORS:
ostream &operator << (ostream & o,const hash_table & s)
{
	for (int i = 0; i < 7; ++i)
	{
		if (s.table[i] != NULL)
		{
			node * temp = s.table[i];
			while (temp != NULL)
			{
				o << *temp;	
				temp = temp->get_next();
			}
		}
	}
}


//+= operator
hash_table & hash_table::operator +=(const song & s)
{
	hash_insert(s.get_artist(),s);
}



//copy function
hash_table & hash_table::operator = (const hash_table & copy)
{
	this->table= new node*[size];
	for (int i = 0; i< size;++i)
	{
		this->table[i] = NULL;
	}

	//copy the array size - dynamic array
	for(int i = 0; i < size; ++i)
	{
		node * temp = copy.table[i];
		copy_lll(temp,this->table[i]);
	}

}



/*
//-= operator
hash_table & hash_table::operator -=(const song & s)
{
	remove(s);
}
*/
