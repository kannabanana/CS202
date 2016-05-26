/*
SR Kanna
NODE.H

THIS IS THE NODE.H
*/

#include "song.h"

#ifndef _NODE_H
#define _NODE_H

class node: public song
{

public:
	node();			//default constructor
	~node();		//deconstructor
	node(const node &);	//copy constructor
	node(const node *);	//copy constructor
	node(const song &);	//copy constructor I: Takes song object O: Nothing 

	node *& get_next();
	const node * go_next() const;
	

	void set_next(node * source);

private:
	node * next;

};

#endif
