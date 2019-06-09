#pragma once
#define MAX 1000
template <typename T>
class Queue {
    T arr[MAX];
    short size = 0;   
public:
    void enqueue(T);
    void dequeue();
    T front();
    T rear();
    bool isEmpty();
};
template <typename T>
void Queue<T>::enqueue(T elem)
{
    if(size + 1 > MAX) throw new std::invalid_argument("Queue overflow");
    T temp;
    
    if(size > 0)
    {
        for(int i = size-1; i >= 0; i-- )
        {
            arr[i+1] = arr[i];
        }
    }
    arr[0] = elem;
    size++;
}
template <typename T>
void Queue<T>::dequeue()
{
    if(--size < 0) throw new std::invalid_argument("Queue underflow");
}
template <typename T>
T Queue<T>::front()
{
    if(!this->isEmpty())
    {
        return arr[0];
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
        return arr[size - 1];
    }
    else
    {
        throw new std::runtime_error("Queue is empty");
    }
    
}
template <typename T>
bool Queue<T>::isEmpty()
{
    return size == 0;
}