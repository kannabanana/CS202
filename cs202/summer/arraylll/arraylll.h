#include <iostream>
#include <cctype>
#include <cstring>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct node
{
	int data;
	node * next;
};

struct table
{
public:
	table(int size);
	~table();
	void display();
	int random(int);
	void insert(node *& head);
private:
	node ** hash_table;
	int hash_table_size;
};
