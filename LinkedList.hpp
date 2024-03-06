#pragma once
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream> 
#include "Node.hpp"

using namespace std;

template<typename Type>
class LinkedList {
public:
    Node<Type>* head;

    LinkedList();
    ~LinkedList();

    void insertNode(Type);
    void printList();
    void deleteNode(int);
};

#include "LinkedList.cpp"
#endif 

