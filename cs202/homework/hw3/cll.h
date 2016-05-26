/*
SR Kanna
HW3
5/11/2015
CLL.H
PURPOSE OF CLL.H:
*/

#include "node.h"

#ifndef _CLL_H
#define _CLL_H

//CLL class - manages playlist
class cll
{
public:

	cll();				//default constructor
	~cll();				//deconstructor
	cll(const cll &);		//copy constructor
	

//FUNCTIONS:
	void sew_cll(node *& rear,node *& rear2);	//sewing the cll back together

	void remove_all(node *& rear);	//remove all - destructor
	void remove_all_lll(node *& rear);	//remove all lll
	
	void copy_wrapper(const node * source,node *& dest);
	void copy(const node * source,const node * source_temp,node *& dest);
	
	void insert(const song &);	//insert a rear ptr into the cll


//OPERATOR:
	cll & operator += (const song &);	//+= operator
	cll & operator = (const cll & s2);	//deep copy of cll
	friend ostream & operator << (ostream & o, const cll & s);


private:
	node * rear;			//has a node ptr
};

#endif
