#pragma once
#include "LinkedList.h"
template <typename T>
class Stack {
    LinkedList<T> * list;
public:
    Stack();
    Stack(const Stack<T>&);
    Stack& operator =(const Stack<T>&);
    ~Stack();
    void push(T);
    void pop();
    T peek();
    bool isEmpty();
    size_t size();
};
template <typename T>
Stack<T>::Stack()
{
    list = new LinkedList<T>();
}
template <typename T>
Stack<T>::Stack(const Stack<T>& other)
{
    *list = other.list;
    size = other.size;
}
template <typename T>
Stack<T>& Stack<T>::operator =(const Stack<T>& other)
{
    if(this != &other) 
    {
        delete &list;
        *list = other.list;
        size = other.size;
    }
    return *this;
}
template <typename T>
Stack<T>::~Stack()
{
    delete list;
}
template <typename T>
void Stack<T>::push(T elem)
{
    list->push(elem);
}
template <typename T>
void Stack<T>::pop()
{
    list->pop();
}
template <typename T>
T Stack<T>::peek() {
    
    if(!this->isEmpty())
    {
      return list->getLast();
    }
    else {
        //error
    }
}
template <typename T>
bool Stack<T>::isEmpty()
{
    return list->isEmpty();
}
template <typename T>
size_t Stack<T>::size()
{
    return list->size();
}
