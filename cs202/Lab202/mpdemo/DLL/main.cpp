#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    node * copy = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    remove_end_DLL(head);
    display(head);
    destroy(head);    
    return 0;
}
