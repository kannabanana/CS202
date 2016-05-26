#include "clist.h"
using namespace std;


//make a new list of every other node - and remove them from the origional
void copy_every_other(node * source)
{
//disconnect CLL
if (source == NULL)
    return;

if (source != NULL)
{
    node * temp = source;
    node * temp2 = source->next;
    source = temp2;
    temp->next = NULL;

    display_lll(source);
    cout << "Hello" << endl;
    remove_all_twos(source);
    //sew CLL back together

    sew_cll(source,source);
}
}

void display_lll(node * head)
{
if (head == NULL)
    return;
cout << head->data << '\t';
return display_lll(head->next);
}

void remove_all_twos(node *& head)
{
if (head == NULL)
    return;
if (head != NULL)
{
    if (head->data == 2)
    {
        node * temp = head->next;
        delete head;
        head = temp;
        return remove_all_twos(head);
    }
    if (head->data != 2)
    {
       return remove_all_twos(head->next);
    }
}
}


void sew_cll(node *& rear,node *& rear2)
{
if (rear2 == NULL)
    return;
if (rear2->next != NULL)
    sew_cll(rear,rear2->next);
if (rear2->next == NULL)
    rear2->next = rear;
}
