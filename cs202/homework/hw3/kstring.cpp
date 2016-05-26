#include "kstring.h"
using namespace std;

//default constructor
mystring::mystring():kstring(NULL),length(0)
{

}

//copy constructor
mystring::mystring(const mystring & source)
{
	length = source.length;
	kstring = new char[length+1];
	strcpy(kstring,source.kstring);
}


//copy for chars
mystring::mystring(const char * to_copy)
{
	kstring = new char[strlen(to_copy)+1];
	strcpy(kstring,to_copy);
}


//deconstructor
mystring::~mystring()
{
	delete [] kstring;
	kstring = NULL;
	length = 0;

}

//function to determine length
int mystring::get_strlen() const
{
	int num = strlen(kstring);
	return num;
}


//reading in
istream & operator >> (istream & in,mystring &s)
{
	char temp[1000];
	in >> temp;
//	if (in.kstring)
//		delete [] in.kstring;
	s.length = strlen(temp);
	s.kstring = new char[s.length+1];
	strcpy(s.kstring,temp);
	return in;
}


//reading out
ostream & operator << (ostream & o, const mystring & s)
{
	o << s.kstring;
	return o;
}


//equals operator - lvalue
mystring & mystring::operator = (const mystring & s2)
{
	if (this == &s2)
		return *this;
	if (kstring)
		delete [] kstring;
	length = s2.length;
	kstring = new char[s2.length+1];
	strcpy(kstring,s2.kstring);
	return *this;
}


//check if two things are the same
bool mystring::operator == (const mystring & s) const
{
if (strcmp(this->kstring,s.kstring)==0)
	return true;
else
	return false;
}

//check if two things are the same
bool mystring::operator == (const char * s) const
{
if (strcmp(this->kstring,s)==0)
	return true;
else
	return false;
}

//operator to add functionality
mystring & mystring::operator +=(const mystring & s)
{
	length += s.length;
	char * temp = new char[length+s.length+1];
	strcpy(temp,kstring);
	strcat(temp,s.kstring);
	kstring = temp;
	return *this;
}



//[] operator
char & mystring::operator [](int index) const
{
	return kstring[index];
}

/*
//operator to remove functionality
mystring & mystring::operator +-(const mystring & s)
{
	length -= s.length;
	char * temp = new char[length-s.length+1];
}
*/

