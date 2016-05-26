#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    node * copy = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    duplicate(copy,head);
    cout << "This is the copy of my new DLL" << endl;
    display(copy);

    destroy(head);    
    return 0;
}
