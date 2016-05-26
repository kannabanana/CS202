#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    node * copy = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
//    change_last_value(head);
    	remove_all_twos(head);
	display(head);

    destroy(head);
    return 0;
}
