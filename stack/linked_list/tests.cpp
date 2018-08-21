#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
int main()
{
    /*  Linked List Tests */
    LinkedList<int> llist;
    for(size_t i = 0; i < 10; i++)
    {
        llist.push(i);
    }
    LinkedList<int> llist2(llist);

    // llist.print(std::cout);
    for(size_t i = 0; i < 10; i++)
    {
        llist2.pop();
    }
    llist2.print(std::cout);
    llist2 = llist;
    llist2.print(std::cout);

    /*  Stack Tests */
    
    Stack<int> my_stack;
    for(size_t i = 0; i < 10; i++)
    {
        my_stack.push(i);
    }
    for(size_t i = 0; i < 9; i++)
    {
        my_stack.pop();
    }
    int res = my_stack.peek();
    my_stack.pop();

    return 0;
}