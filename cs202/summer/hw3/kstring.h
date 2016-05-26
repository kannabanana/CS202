#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sdlib.h>
#include <time.h>

using namespace std;

#ifdef KSTRING_H
#define KSTRING_H


class mystring
{
	public:
		mystring();		//default costructor
		mystring(const mystring &);		//copy constructor - constant because the object is not modified
		~mystring();		//destructor

		int get_strlen() const;		//getter of the length of the string - constant because none of the data members are modified

		friend ostream &operator << (ostream &, const mystring &);	//friend because of datatype operator
		friend istream &operator >> (istream &, mystring &);


	protected:
		char * kstring;
		int length;


};
#endif
