#include "node.h"
using namespace std;


class hash_table
{

public:
	hash_table();
	hash_table(int size = 7);
	hash_table(const hash_table &);		//copy constructor
	~hash_table();
	
	int hash_function(const mystring artist);	//hashes based on artist
	int hash_function_nc(mystring aritst);
	void hash_insert_nc(mystring key_value,song &);
	void hash_insert(const mystring key_value, const song & );	//inserts based 
	void copy_lll(const node * source,node *& dest);	//copy function for chaining

//OPERATOR FUNCTIONS:
	hash_table & operator += (const song & s);	//+= to add a song to hash_table

//	= - deep copy
	hash_table & operator = (const hash_table & s2); 
	friend ostream &operator << (ostream & o,const hash_table & s); 


private:
	node ** table;				//takes a head ptr
	int size;
};
