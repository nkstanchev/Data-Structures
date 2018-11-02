//
// Created by nikolay on 8/30/18.
//

#ifndef BINARY_SEARCH_TREE_BST_H
#define BINARY_SEARCH_TREE_BST_H

template <typename T>
struct Node {
    T data;
    Node<T>* left  = nullptr;
    Node<T>* right = nullptr;
    Node(T data, Node<T>* left, Node<T>* right ) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

template <typename T>
class BST {
    Node<T>* root = nullptr;
    void insertHelper(const T&, Node<T>*&);
    void removeHelper(const T&, Node<T>*&);
    bool searchHelper(const T&, Node<T>*&);

public:
    bool search(const T&);
    void insert(const T&);
    void remove(const T&);

};

template <typename T>
bool BST<T>::searchHelper(const T& elem, Node<T>*& node) 
{
    if(node == nullptr) return false;
    else if(node->data == elem) return true;
    else if(elem < node->data) return searchHelper(elem, node->left);
    else if(elem > node->data) return searchHelper(elem, node->right);
}
template <typename T>
void BST<T>::insertHelper(const T& elem, Node<T>*& node) {
    if(node == nullptr) {
        Node<T>* newNode = new Node<T>(elem, nullptr, nullptr);
        node = newNode;
        return;
    } else if (elem < node->data) {
        return insertHelper(elem, node->left);
    }
     else if (elem >= node->data) {
        return insertHelper(elem, node->right);
    }
}
template <typename T>
bool BST<T>::search(const T& elem)
{
    searchHelper(elem, root);
}
template <typename T>
void BST<T>::insert(const T& elem)
{
    insertHelper(elem, root);
}
template <typename T>
void BST<T>::removeHelper(const T& elem, Node<T>*& node) {
    if(node == nullptr) return;
    else if(node->data == elem) {
        removeHelper(elem, node->left);
        removeHelper(elem, node->right);
        delete node;
        node = nullptr;
    } else if(elem < node->data) {
        removeHelper(elem, node->left);
    } else if (elem >= node->data) {
        removeHelper(elem, node->right);
    }
}
template <typename T>
void BST<T>::remove(const T& elem)
{
   removeHelper(elem, root);
}
#endif //BINARY_SEARCH_TREE_BST_H
