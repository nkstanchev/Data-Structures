#include <iostream>
#include "LinkedList.h"
#include "Queue.h"
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
        llist2.push_front(i);
    }
    llist2.print(std::cout);
    llist2 = llist;
    llist2.print(std::cout);

    /*  Stack Tests */
    
    Queue<int> my_queue;
    for(size_t i = 0; i < 10; i++)
    {
        my_queue.enqueue(i);
    }
    for(size_t i = 0; i < 9; i++)
    {
        my_queue.dequeue();
    }
    int res = my_queue.rear();
    my_queue.dequeue();

    return 0;
}