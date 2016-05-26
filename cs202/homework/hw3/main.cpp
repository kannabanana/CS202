/*SR Kanna
CS202
MAIN.CPP
*/

//#include "manager.h"
#include "graph.h"
using namespace std;


int main()
{
	//objects:
	graph graph_obj(7);
//	hash_table hash_table_obj(7);
//	manager mymanager;
	mystring song1;
	mystring artist;
	mystring genre[2];


	cout << "Please enter a song title: ";
	cin >> song1;	cin.ignore(100,'\n');

	cout << "Please enter a genre title: ";
	cin >> genre[0];	cin.ignore(100,'\n');

	cout << "Please enter a genre title: ";
	cin >> genre[1];	cin.ignore(100,'\n');
	cout << "Please enter an artist title: ";
	cin >> artist;	cin.ignore(100,'\n');

	//This is one way:
	//	string to_insert = song(song,genre,artist);


	//Other Suggestion:
	song to_insert(artist,song1,genre);
//	cout << to_insert;
	cout << "HELLO" << endl;
	graph_obj += to_insert;
	cout << "HELLO" << endl;
	graph_obj += to_insert;
	cout << "HELLO" << endl;
	graph_obj += to_insert;
	graph_obj += to_insert;

	cout << graph_obj;	  


//	mymanager.read_in();
//	cout << hash_table_obj;

	return 0;
};
