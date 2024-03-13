#include <iostream> 
#include "LinkedList.hpp"

template<typename Type>
void LinkedList<Type>::clear() {
    Node<Type>* cur;
    while (head != NULL) {
        cur = head->next;
        delete head;
        head = cur;

    }
}

template<typename Type>
void LinkedList<Type>::setHead(Node<Type>*& otherHead) {
    clear();
    head = otherHead;
}

template<typename Type>
Node<Type>* LinkedList<Type>::getHead() {
    return head;
}

template<typename Type>
Node<Type>* LinkedList<Type>::cloneHead(Node<Type>& cur) {
    if (cur == NULL) {
        return NULL;
    }
    Node<Type>* newNode = new Node<Type>(cur->data);
    newNode->next = cloneHead(cur->next);
    return newNode;
}

template<typename Type>
LinkedList<Type>::LinkedList() : head(NULL) {}

template<typename Type>
LinkedList<Type>::LinkedList(const LinkedList<Type>& list) {
    head = NULL;
    Node<Type>* cur = NULL;
    Node<Type>* other = list.head;
    while (other != NULL) {
        Node<Type>* newNode = new Node<Type>();
        newNode->next = NULL;
        newNode->data = other->data;
        if (cur != NULL)
            cur->next = newNode;
        if (head == NULL)
            head = newNode;
        cur = newNode;
        other = other->next;
    }
}


template<typename Type>
LinkedList<Type>::~LinkedList() {
    clear();
}

template<typename Type>
void LinkedList<Type>::deleteNode(int nodeOffset) {
    Node<Type>* temp1 = head, * temp2 = NULL;
    int ListLen = 0;

    if (head == NULL) {
        cout << "List empty." << endl;
        return;
    }

    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }

    if (ListLen < nodeOffset) {
        cout << "Index out of range"
            << endl;
        return;
    }

    temp1 = head;

    if (nodeOffset == 1) {
        head = head->next;
        delete temp1;
        return;
    }

    while (nodeOffset-- > 1) {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;

    delete temp1;
}

template<typename Type>
void LinkedList<Type>::insertNode(Type data) {

    Node<Type>* newNode = new Node<Type>(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node<Type>* temp = head;
    while (temp->next != NULL) {

        temp = temp->next;
    }

    temp->next = newNode;
}

template<typename Type>
void LinkedList<Type>::printList() {
    Node<Type>* temp = head;

    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

template<typename Type>
const LinkedList<Type>& LinkedList<Type>::operator=(const LinkedList<Type>& list) {
    head = NULL;
    Node<Type>* cur = NULL;
    Node<Type>* other = list.head;
    while (other != NULL) {
        Node<Type>* newNode = new Node<Type>();
        newNode->next = NULL;
        newNode->data = other->data;
        if (cur != NULL)
            cur->next = newNode;
        if (head == NULL)
            head = newNode;
        cur = newNode;
        other = other->next;
    }
    
    return *this;
}
