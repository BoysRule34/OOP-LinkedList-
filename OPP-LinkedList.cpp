#include <iostream>
#include <string>

#include "LinkedList.hpp"

int main() {

    LinkedList<char> list{};
    LinkedList<char> list2{};
    list.insertNode('a');
    list.insertNode('b');
    list.insertNode('c');
    

    list2 = list;
    list.deleteNode(3);
    list.insertNode('a');
    

    std::cout << "list = ";
    list.printList();
    std::cout << "list2 = ";
    list2.printList();


    std::cout << "1) (list != list2) = " + to_string((list != list2)) + " \n";

    std::cout << "2) (list == list2) = " + to_string((list == list2)) + " \n";

    std::cout << "3) list.swap(list2): \n";
    list.swap(list2);
    std::cout << "list = ";
    list.printList();
    std::cout << "list2 = ";
    list2.printList();

    std::cout << "4) list.size() = " + to_string(list.size()) + "\n";
    
    std::cout << "5) list.max_size() = " + to_string(list.max_size()) + "\n";

    std::cout << "6) list.empty() = " + to_string(list.empty()) + "\n";

    std::cout << "7) list = list 2 \n";
    list = list2;
    std::cout << "list = ";
    list.printList();
    std::cout << "list2 = ";
    list2.printList();



    
    

    



    return 0;
}

