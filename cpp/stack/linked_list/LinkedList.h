#pragma once
#include<iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
};

template <typename T>
class LinkedList {
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    size_t size = 0;
    void copy(const LinkedList<T>&);
    void cleanup();
public:
    LinkedList();
    LinkedList(const LinkedList<T>&);
    LinkedList<T>& operator=(const LinkedList<T>&);
    ~LinkedList();
    void push(const T&);
    void pop();
    bool isEmpty();
    T getLast();
    void print(std::ostream&);
    size_t length();
};
template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& other)
{
    Node<T> * tempNode = other.head;
    while(tempNode != nullptr)
    {
        this->push(tempNode->data);
        tempNode = tempNode->next;
    }
    
}
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
    copy(other);
}
template <typename T>
void LinkedList<T>::cleanup()
{
    Node<T>* current;
    current = head;
    while(current != nullptr)
    {
        delete current;
        current = current->next;
    }
}
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
    if(this != &other)
    {
        copy(other);
    }
    return *this;
}
template <typename T>
LinkedList<T>::~LinkedList()
{
    cleanup();
}
template <typename T>
void LinkedList<T>::push(const T& elem)
{
    Node<T> * node = new Node<T>();
    node->data = elem;
    if(size == 0)
    {
        head = node;
        tail = head;
    }
    else if(size > 0) {

        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    else {
        //error
    }
    size++;
}
template <typename T>
void LinkedList<T>::pop()
{
    if(size > 1)
    {
        Node<T>* toDel = tail;
        delete toDel;
        tail = tail->prev;
        tail->next = nullptr;
    }
    else if(size == 1)
    {
        Node<T>* toDel = tail;
        delete toDel;
        tail = nullptr;
        head = nullptr;
    }
    else {
        //error
    }
    size--;
}
template <typename T>
bool LinkedList<T>::isEmpty()
{
    return size == 0;
}
template <typename T>
void LinkedList<T>::print(std::ostream& os)
{
    Node<T>* current;
    current = head;
    while(current != nullptr)
    {
        os << current->data << '\n';
        current = current->next;
    }
}
template <typename T>
T LinkedList<T>::getLast()
{
    if(!this->isEmpty())
    {
        return tail->data;
    }
    else {
        //error
    }
}
template <typename T>
size_t LinkedList<T>::length()
{
    return size;
}
