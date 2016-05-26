#include "cll.h"
#include "hash_table.h"
#include "graph.h"
using namespace std;


class manager
{
public:
	manager();
	~manager();
	manager(const manager &);

	void read_in(void);	//read in from file

protected:
	cll * cll_obj;
	graph * graph_obj;
	hash_table * hash_table_obj;
};
