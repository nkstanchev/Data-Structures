//
// Created by nikolay on 8/30/18.
//

#ifndef BINARY_SEARCH_TREE_BST_H
#define BINARY_SEARCH_TREE_BST_H

#include <assert.h>
#include "string.h"
#include <string>

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
    int sizeHelper(Node<T>*&);
    int countByCondtHelper(Node<T>*&, bool (*pred)(const T&));
    int heightHelper(Node<T>*&);
    int countLeavesHelper(Node<T>*&);
    T maxLeafHelper(Node<T>*&);
    T& getElementHelper(Node<T>*, const char *);
    Node<T>* readSchemeHelper(const char * s);
public:
    BST();
    BST(const BST<T>&);
    BST<T> operator =(const BST<T>&);
    ~BST();
    bool search(const T&);
    void insert(const T&);
    void remove(const T&);
    int size();
    int countByCondt(bool (*pred)(const T&));
    int height();
    int countLeaves();
    T maxLeaf();
    T& getElement(const char * s);
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
    else return searchHelper(elem, node->right);
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
    return searchHelper(elem, root);
}
template <typename T>
void BST<T>::insert(const T& elem)
{
    insertHelper(elem, root);
}
template <class T>
Node<T>* getMinNode(Node<T>* root) {
    if (root->left == nullptr) {
        return root;
    } else {
        return getMinNode(root->left);
    }
}
template <typename T>
void BST<T>::removeHelper(const T& elem, Node<T>*& node) {
    if (node == nullptr) return;
    if (elem < node->data) {
        removeHelper(elem, node->left);
    } else if (elem > node->data) {
        removeHelper(elem, node->right);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if (node->left == nullptr || node->right == nullptr) {
            Node<T> *next = (node->left != nullptr) ? node->left : node->right;
            Node<T> *temp = node;
            delete temp;
            node = next;
        } else {
            Node<T> *minNode = getMinNode(node->right);
            node->data = minNode->data;
            removeHelper(minNode->data, node->right);
        }
    }
}
template <typename T>
void BST<T>::remove(const T& elem)
{
   removeHelper(elem, root);
}
template <typename T>
int BST<T>::sizeHelper(Node<T>*& node) {
    if(node == nullptr) {
        return 0;
    }
    return 1 + sizeHelper(node->left) + sizeHelper(node->right);
}
template <typename T>
int BST<T>::size() {
    return sizeHelper(root);
}
template <typename T>
int BST<T>::countByCondtHelper(Node<T>*& node, bool (*pred)(const T&)) {
    if(node == nullptr) {
        return 0;
    }
    if(pred(node->data)) {
        return 1 + countByCondtHelper(node->left, pred) + countByCondtHelper(node->right, pred);
    } else {
        return 0 + countByCondtHelper(node->left, pred) + countByCondtHelper(node->right, pred);
    }
    
}
template <typename T>
int BST<T>::countByCondt(bool (*pred)(const T&)) {
    return countByCondtHelper(root, pred);
}
template <typename T>
int BST<T>::heightHelper(Node<T>*& node) {
    if(node == nullptr) {
        return 0;
    }
    return 1 + std::max(heightHelper(node->left), heightHelper(node->right));
}
template <typename T>
int BST<T>::height() {
    return heightHelper(root);
}
template <typename T>
int BST<T>::countLeavesHelper(Node<T>*& node) {
    if(node != nullptr && node->left == nullptr && node->right == nullptr) {
        return 1;
    }
    if(node != nullptr && node->left != nullptr && node->right == nullptr) {
        return countLeavesHelper(node->left);
    }
    if(node != nullptr && node->left == nullptr && node->right != nullptr) {
        return countLeavesHelper(node->right);
    }
    return countLeavesHelper(node->left) + countLeavesHelper(node->right);
}
template <typename T>
int BST<T>::countLeaves() {
    return countLeavesHelper(root);
}
template <typename T>
T& BST<T>::getElementHelper(Node<T>* node, const char * s) {
    assert(*s == 'L' || *s == 'R' || *s == '\0' || node == nullptr);
    if(strlen(s) == 0 && node != nullptr) {
        return node->data;
    }
    if(*s == 'L') {
        return getElementHelper(node->left, s+1);
    }
    if(*s == 'R') {
        return getElementHelper(node->right, s+1);
    }
}
template <typename T>
T& BST<T>::getElement(const char * s) {
    assert(root != nullptr);
    if(strlen(s) == 0 && root != nullptr) {
        return root->data;
    }
    return getElementHelper(root, s);
}
template <typename T>
T BST<T>::maxLeafHelper(Node<T>*& node) {
    if(node != nullptr && node->left == nullptr && node->right == nullptr) {
        return node->data;
    }
    if(node != nullptr && node->left != nullptr && node->right == nullptr) {
        return maxLeafHelper(node->left);
    }
    if(node != nullptr && node->left == nullptr && node->right != nullptr) {
        return maxLeafHelper(node->right);
    }
    T left = maxLeafHelper(node->left);
    T right = maxLeafHelper(node->right);
    if(left < right) {
        return right;
    } else {
        return left;
    }
    
}
template <typename T>
T BST<T>::maxLeaf() {
    return maxLeafHelper(root);
}
#endif //BINARY_SEARCH_TREE_BST_H
