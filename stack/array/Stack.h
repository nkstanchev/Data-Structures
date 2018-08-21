#pragma once
#define MAX 1000
template <typename T>
class Stack {
    T arr[MAX];
    short size = 0;   
public:
    void push(T);
    void pop();
    T peek();
    bool isEmpty();
};
template <typename T>
void Stack<T>::push(T elem)
{
    if(++size > MAX) throw new std::invalid_argument("Stack overflow");
    arr[size] = elem;
}
template <typename T>
void Stack<T>::pop()
{
    if(--size < 0) throw new std::invalid_argument("Stack underflow");
}
template <typename T>
T Stack<T>::peek()
{
    if(!this->isEmpty())
    {
        return arr[size - 1];
    }
    else
    {
        throw new std::runtime_error("Stack is empty");
    }
    
}
template <typename T>
bool isEmpty()
{
    return size == 0;
}