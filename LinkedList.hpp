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

    struct Iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = Type;
        using pointer = Node<Type>*;
        using reference = Type&;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return m_ptr->data; } // m_ptr != nullptr ? m_ptr->data : NULL (хз как это сделать)
        pointer operator->() { return m_ptr; }
        Iterator& operator++() { 
            if (first) {
                first = false;
                helper(m_ptr->next, m_ptr->data);
            } else {
                helper(m_ptr->next, m_ptr->data * m_ptr->data * inc(m_ptr->data));
            }
            return *this; 
               
        }
        Iterator operator++(int) { 
            Iterator tmp = *this; ++(*this); return tmp; 
        }
        
        friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

    private:
        pointer m_ptr;
        bool first = true;

        void helper (pointer p, int i) {
            if (p != NULL && i != p->data) {
                helper(p->next, i * p->data);
            } else {
                m_ptr = p;
            }
        }

        short inc(value_type p) {
            if (std::is_same_v<decltype(p), int>)
                return p < 0 ? -1 : 1;
            else
                return 1;
        }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return NULL; }

    Iterator createIterator() {
        return begin();
    }


private:
    Node<Type>* head;
    int listSize;
};

#include "LinkedList.cpp"
#endif 

