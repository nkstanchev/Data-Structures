#include <iostream>
#include "BST.h"
template <typename T>
bool biggerThan3(const T& data) {
    return data > 3;
}

int main() {

    BST<int> bst;

    bst.insert(3);
    bst.insert(2);
    bst.insert(1);
    bst.insert(5);
    bst.insert(4);
    bst.insert(6);
    

    BST<int> bst2(bst);
    bst2.insert(7);
    bst2.insert(4);
    std::cout << "Size of tree : " << bst.size() << std::endl;
    std::cout << "Size of tree : " << bst2.size() << std::endl;
    std::cout << "Bigger than 3 : " << bst.countByCondt(biggerThan3) << std::endl;
    std::cout << "Height of tree : " << bst.height() << std::endl;
    std::cout << "Count leaves : " << bst.countLeaves() << std::endl;
    std:: cout << "Element of LL : " << bst.getElement("LL") << std::endl;
    std::cout << "Max leaf is : " <<  bst.maxLeaf() << std::endl;
 
    bst = bst2;

    std::cout << bst.search(3) << std::endl;
    std::cout << bst.search(1) << std::endl;
    std::cout << bst.search(-1)  << std::endl;
    
    bst.remove(6);
    bst.remove(2);
    bst.remove(3);

    return 0;
}