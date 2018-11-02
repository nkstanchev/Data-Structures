#include <iostream>
#include "BST.h"
int main() {

    BST<int> bst;

    bst.insert(3);
    bst.insert(2);
    bst.insert(1);
    bst.insert(5);
    bst.insert(6);

    std::cout << bst.search(3) << std::endl;
    std::cout << bst.search(1) << std::endl;
    std::cout << bst.search(-1)  << std::endl;
    
    bst.remove(6);
    bst.remove(2);
    bst.remove(3);

    return 0;
}