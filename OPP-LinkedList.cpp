#include <iostream>
#include <string>

#include "LinkedList.hpp"

int main() {

    LinkedList<char> list{};
    LinkedList<char> list2{};
    list.insertNode('a');
    list.insertNode('b');
    list.insertNode('c');
    
    list.printList();

    LinkedList<char>(list).printList();

    list2.printList();
    

    



    return 0;
}

