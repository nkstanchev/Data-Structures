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
    if(++size > MAX) throw new std::invalid_argument("Queue overflow");
    T temp;
    if(size == 2)
    {
        arr[1] = arr[0];
    }
    else {
        for(size_t i = 1; i < size - 1; i++ )
        {
            temp = arr[i]; 
            arr[i] = arr[i-1];
            arr[i+1] = temp;
        }
    }
    
    arr[0] = elem;
    
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