#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    node * head2 = NULL;
    build(head);
    build(head2);
    //    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned

//    int match = 2;
//    int count = num_times(head,match);  
//    cout << "This is the number of times 2 appears in the list " << match << endl;
//    display(head);

    
/*    int count = display_first_last(head);
    cout << "This is the total of head and tail " << count << endl;
  
*/


    

    if(same_content(head,head2) == 0)
        cout << "They're different!" << endl;
    else 
        cout << "They're same!" << endl;
    
//    display(head);

    destroy(head);
    
    return 0;
}
