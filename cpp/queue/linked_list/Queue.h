#pragma once
#include "LinkedList.h"
template <typename T>
class Queue {
    LinkedList<T>* list;  
public:
    Queue();
    Queue(const Queue<T>&);
    Queue<T> operator =(const Queue<T>&);
    ~Queue();
    void enqueue(T);
    void dequeue();
    T front();
    T rear();
    bool isEmpty();
};
template <typename T>
Queue<T>::Queue() {
    list = new LinkedList<T>();
}
template <typename T>
Queue<T>::Queue(const Queue<T>& other)
{
    *list = other.list;
}
template <typename T>
Queue<T> Queue<T>::operator =(const Queue<T>& other)
{
    if(this != &other)
    {
        delete list;
        *list = other.list;
    }
    return *this;
}
template <typename T>
Queue<T>::~Queue()
{
    delete list;
}
template <typename T>
void Queue<T>::enqueue(T elem)
{
    list->push_front(elem);
}
template <typename T>
void Queue<T>::dequeue()
{
    list->pop();
}
template <typename T>
T Queue<T>::front()
{
    if(!this->isEmpty())
    {
        return list->getFirst();
    }
    else
    {
        throw new std::runtime_error("Queue is empty");
    }
    
}
template <typename T>
T Queue<T>::rear()
{
    if(!this->isEmpty())
    {
        return list->getLast();
    }
    else
    {
        throw new std::runtime_error("Queue is empty");
    }
    
}
template <typename T>
bool Queue<T>::isEmpty()
{
    return list->length() == 0;
}