#include "dlist.h"
using namespace std;


void duplicate(node *& new_copy,node * origional)
{
if (origional == NULL)
    new_copy = NULL;
if (origional != NULL)
{
    new_copy = new node;
    new_copy->data = origional->data;
    duplicate(new_copy->next,origional->next);
}
//no nodes
//nodes
//create a new copy node
//set the duplicate to the origional
//call the function on the next


}
