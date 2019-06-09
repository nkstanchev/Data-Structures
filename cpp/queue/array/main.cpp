#include <iostream>
#include "Queue.h"
int main()
{
    Queue<int> my_queue;
    for(size_t i = 10; i >= 1; i--)
    {
        my_queue.enqueue(i);
    }
    for(size_t i = 1; i < 9; i++)
    {
        my_queue.dequeue();
    }
    std::cout << my_queue.front() << '\n';
    std::cout << my_queue.rear() << '\n';
    return 0;
}