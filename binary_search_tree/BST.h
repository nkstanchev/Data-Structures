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
    Node<T>* copy(Node<T>*);
    void cleanup(Node<T>*&);
    void insertHelper(const T&, Node<T>*&);
    void removeHelper(const T&, Node<T>*&);
    bool searchHelper(const T&, Node<T>*&);

public:
    BST();
    BST(const BST<T>&);
    BST<T> operator =(const BST<T>&);
    ~BST();
    bool search(const T&);
    void insert(const T&);
    void remove(const T&);

};
template <typename T>
BST<T>::BST() {
    root = nullptr;
}

template <typename T>
Node<T>* BST<T>::copy(Node<T>* otherCurrent)
{
    if (otherCurrent == nullptr) return nullptr;
    return new Node<T> (otherCurrent->data,
                        copy (otherCurrent->left),
                        copy (otherCurrent->right));
}
template <typename T>
BST<T>::BST(const BST<T>& other) {
    root = copy(other.root);
}
template <typename T>
BST<T> BST<T>::operator=(const BST<T>& other) {
    if(this != &other) {
        this->cleanup(root);
        root = this->copy(other.root);
    }
    return *this;
}
template <typename T>
BST<T>::~BST() {
    cleanup(root);
}
template <typename T>
void BST<T>::cleanup(Node<T>*& node) {
    if(node == nullptr) return;
    if(node->left == nullptr && node->right == nullptr) {
        delete node;
        node = nullptr;
    } else {
        cleanup(node->left);
        cleanup(node->right);
        if(node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
    }
}

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
