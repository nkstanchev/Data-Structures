#include <iostream>
#include "Stack.h"
int main()
{
    Stack<int> my_stack;
    for(size_t i = 1; i <= MAX; i++)
    {
        my_stack.push(i);
    }
    for(size_t i = 1; i < MAX; i++)
    {
        my_stack.pop();
    }
    std::cout << my_stack.peek();
    return 0;
}