#include "manager.h"
using namespace std;


manager::manager()
{
	cll_obj = NULL;
	graph_obj = NULL;
	hash_table_obj = NULL;
}


//no dynamic memory
manager::~manager()
{
//
}


//copy constructor
manager::manager(const manager & s)
{

//do dynamic memory

}


void manager::read_in(void)
{
	mystring temp;
	song temp_song;
//	graph temp_vertex(7);
	hash_table temp_hash(7);
	ifstream file_in;
	file_in.open("dataf.txt");
	if(!file_in)
		return;
	else
	{
		while(!file_in.eof())
		{
			file_in >> temp;	file_in.ignore(100,':');
//			temp_vertex.artist = temp;	
			temp_song.get_artist() = temp;

			file_in >> temp;	file_in.ignore(100,':');
//			temp_vertex.genre[0] = temp;	
			temp_song.get_genre(0) = temp;

			file_in >> temp;	file_in.ignore(100,':');
		//	temp_vertex.genre[1] = temp;	
			temp_song.get_genre(1) = temp;

			file_in >> temp;	file_in.ignore(100,'\n');
		//	temp_vertex.song = temp;	
			temp_song.get_song() = temp;
	
			if (temp.get_strlen() > 0)
			{
		//		insert(temp_vertex);
				temp_hash.hash_insert_nc(temp_song.get_artist(),temp_song);
			}
		}
	}
}
