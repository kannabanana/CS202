/*
SR Kanna
CS202
HW3
5/8/2015
HW3

STRING.H

PURPOSE OF STRING.H: Implements the operators for the string class functionality

*/


#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#ifndef KSTRING_H
#define KSTRING_H


class mystring
{
	public:
		mystring();		//constructor
		mystring(const mystring &);	//copy constructor
		mystring(const char * );
		~mystring();		//deconstructor


		int get_strlen() const;

		friend ostream &operator << (ostream &, const mystring &);	//write out
		friend istream &operator >> (istream &, mystring &);	//read in

		mystring & operator = (const mystring &);	//deep copy
		bool operator == (const mystring &) const;			//check if two things are equal - strcpy 
		bool operator == (const char *) const;


		mystring & operator += (const mystring &);
		char & operator [] (int index) const;		//overload [] to return the char
	//	string & operator -= (const string &);

	private:
		char * kstring;
		int length;

};

#endif
