#pragma once
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream> 
#include "Node.hpp"

using namespace std;

template<typename Type>
class LinkedList {
public:
    LinkedList();
    LinkedList(const LinkedList<Type>&);
    ~LinkedList();

    void insertNode(Type);
    void printList();
    void deleteNode(int);
    Node<Type>* cloneHead(Node<Type>&);
    void clear();


    void setHead(Node<Type>*& otherHead);
    Node<Type>* getHead();

    const LinkedList<Type>& operator=(const LinkedList<Type>&);
private:
    Node<Type>* head;
};

#include "LinkedList.cpp"
#endif 

