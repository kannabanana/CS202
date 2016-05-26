#include "song.h"
using namespace std;

//default constructor
song::song():genre(NULL)		//initializes genre ptr to NULL
{
	genre = new mystring[2];
}

//deconstructor
song::~song()
{
	delete [] genre;
	genre = NULL;

}


//copy constructor of type object
song::song(const song & source)
{
	artist = source.artist;			//assignment operator - does deep copy!
	song_name = source.song_name;
	genre = new mystring[2];
	for (int i = 0; i < 2; ++i)
	{
		genre[i] = source.genre[i];
	}
}


//copy constructor with ptr arguments
song::song(const song * source)
{
	artist = source->artist;
	song_name = source->song_name;
	genre = new mystring[2];
	for (int i =2; i<2; ++i)
	{
		genre[i] = source->genre[i];
	}
}


//constructor w/arguments
song::song(const mystring & artist, const mystring & song_name, const mystring genre[])
{
	this->artist = artist;
	this->song_name = song_name;

	this->genre = new mystring[2];
	for (int i = 0; i <2; ++i)
	{
		this->genre[i] = genre[i];
	}
}


//getter for aritst - hash table
mystring const & song::get_artist() const
{
	return artist;
}


//OPERATORS:

//deep copy
song & song::operator = (const song & s2)
{
	if(this == &s2)
		return *this;
//don't need to check delete because string does it

	artist = s2.artist;
	song_name = s2.song_name;

	if (genre)
		delete [] genre;

	genre = new mystring[2];
	for(int i = 0;i <2;++i)
	{
		genre[i] = s2.genre[i];
	}
}


//display
ostream & operator << (ostream & o, const song & s)
{
	o << s.song_name << '\t' << s.artist << '\t' << s.genre[0] << '\t' << s.genre[1] << endl;
	return o;
}



//read in operator
istream & operator >> (istream & in,song &s)
{
//based on external data file

	in >> s.artist;
	in.ignore(100, ':');
	
	s.genre = new mystring[2];
	in >> s.genre[0];
	in.ignore(100,':');

	in >> s.genre[1];
	in.ignore(100,':');
	
	in >> s.song_name;
	in.ignore(100,'\n');
	
}


//getting a genre
mystring song::get_genre(int index)
{
	return genre[index];
}

//getter for song
mystring song::get_song()
{
	return song_name;
}

//getter for song
mystring song::get_artist()
{
	return artist;
}


//get index of first genre
int song::get_index(song & to_insert, int n)
{
	if(to_insert.genre[n] == "oldies")
		return 0;
	if(to_insert.genre[n] == "r&b")
		return 1;
	if(to_insert.genre[n] == "rap")
		return 2;
	if(to_insert.genre[n] == "bollywood")
		return 3;
	if(to_insert.genre[n] == "classic")
		return 4;
	if(to_insert.genre[n] == "love")
		return 5;
	if(to_insert.genre[n] == "country")
		return 6;
	else
		return 0;
}
