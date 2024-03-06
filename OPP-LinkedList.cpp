#include <iostream>
#include <string>

#include "Node.hpp"
#include "LinkedList.hpp"


int main() {

    LinkedList<char> list{};

    list.insertNode('s');
    list.insertNode('b');
    list.printList();

    return 0;
}
