#include "table.h"

int main()
{
    node * root = NULL;
    node * copy = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */
    copy_LLL(root,copy);
    display(copy);
    return 0;
}
