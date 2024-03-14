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
    int size();
    const int max_size();
    bool empty();


    void setHead(Node<Type>*& otherHead);
    Node<Type>* getHead();


    const LinkedList<Type>& operator=(const LinkedList<Type>&);
    bool operator==(const LinkedList<Type>& list);
    bool operator!=(const LinkedList<Type>& list);
    void swap(LinkedList<Type>& list1);
    void swap(LinkedList<Type>& list1, LinkedList<Type>& list2);

private:
    Node<Type>* head;
    int listSize;
};

#include "LinkedList.cpp"
#endif 

