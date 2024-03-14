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
int LinkedList<Type>::size()
{
    return listSize;
}

template<typename Type>
const int LinkedList<Type>::max_size()
{
    return 999;
}

template<typename Type>
bool LinkedList<Type>::empty()
{
    return head == NULL;
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
LinkedList<Type>::LinkedList() : head(NULL) , listSize(0) {}

template<typename Type>
LinkedList<Type>::LinkedList(const LinkedList<Type>& list) {
    listSize = list.listSize;
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
void LinkedList<Type>::deleteNode(int id) {
    Node<Type>* cur1 = head, *cur2 = NULL;
    int count = 0;

    if (head == NULL) {
        cout << "List empty." << endl;
    }
    else {

        while (cur1 != NULL) {
            cur1 = cur1->next;
            count++;
        }

        if (count < id) {
            cout << "Index out of range"
                << endl;

        }
        else {
            cur1 = head;

            if (id == 1) {
                head = head->next;
                delete cur1;
            }
            else {

                while (id-- > 1) {
                    cur2 = cur1;
                    cur1 = cur1->next;
                }

                cur2->next = cur1->next;

                delete cur1;
            }
            listSize--;
        }
    }
}

template<typename Type>
void LinkedList<Type>::insertNode(Type data) {
    listSize++;
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
    listSize = list.listSize;
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

template<typename Type>
bool LinkedList<Type>::operator==(const LinkedList<Type>& list) {
    if (list.listSize != listSize)
        return false;
    Node<Type>* cur = list.head;
    Node<Type>* curHead = head;
    while (cur != NULL && cur->data == curHead->data) {
        cur = cur->next;
        curHead = curHead->next;
    }

    return cur == NULL;

}

template<typename Type>
bool LinkedList<Type>::operator!=(const LinkedList<Type>& list) {
    if (list.listSize != listSize)
        return true;
    Node<Type>* cur = list.head;
    Node<Type>* curHead = head;
    while (cur != NULL && cur->data == curHead->data) {
        cur = cur->next;
        curHead = curHead->next;
    }

    return !(cur == NULL);
}

template<typename Type>
void LinkedList<Type>::swap(LinkedList<Type>& list1) {
    int sizee = list1.listSize;
    list1.listSize = listSize;
    listSize = sizee;

    Node<Type>* swapHead = head;
    head = list1.getHead();
    list1.head = swapHead;
}

template<typename Type>
void LinkedList<Type>::swap(LinkedList<Type>& list1, LinkedList<Type>& list2) {
    list1.swap(list2);
}

