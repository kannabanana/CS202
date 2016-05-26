//this is the song class .h implementation

#include "kstring.h"
using namespace std;

#ifndef _SONG_H
#define _SONG_H

//string class
class song
{
public:

	song();		//default constructor
	~song();		//deconstructor
	song(const song &);	//copy constructor
	song(const song *);	//copy constructor
	song(const mystring & , const mystring &, const mystring genre[] );
	
	
	mystring const & get_artist() const;
	mystring get_genre(int);	//getting a genre
	int get_index(song &,int n);
	mystring get_song();
	mystring get_artist();


//OPERATORS:
	song & operator = (const song & s2);	//asignment operator
	friend ostream &operator << (ostream & o, const song & s);
	friend istream &operator >> (istream & in,song &s);

	

	//compare?

protected:
	mystring artist;		//artist name
	mystring song_name;	//song name
	mystring * genre;		//genere
};

#endif
