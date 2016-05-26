#include "dlist.h"
using namespace std;


void copy_DLL(node * source, node *& dest)
{
if (source == NULL)
    dest = NULL;
if (source != NULL)
{
    dest = new node;
    dest->data = source->data;
    copy_DLL(source->next,dest->next);
}
//no nodes
//nodes
//
}


//remove end of DLL
//
void remove_end_DLL(node *& head)
{
    DLL_LLL(head);
    remove_last_node_lll(head);
    set_previous(head);

}

void remove_last_node_lll(node *& head)
{
if (head == NULL)
    return;
if (head->next == NULL)
{
    delete head;
    head = NULL;
    return;
}
    return remove_last_node_lll(head->next);
}



void DLL_LLL(node * head)
{
if (head == NULL)
    return;

if (head->previous != NULL)
    head->previous == NULL;

return DLL_LLL(head->next);
}


void set_previous(node * head)
{
if (head == NULL)
    return;
if (head->next == NULL)
    return;
head->next->previous = head;
return set_previous(head->next);
}
