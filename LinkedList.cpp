#include <iostream> 

template<typename Type>
LinkedList<Type>::LinkedList() : head(NULL) {};

template<typename Type>
LinkedList<Type>::~LinkedList() {
    Node<Type>* cur;
    while (head != NULL) {
        cur = head->next;
        delete head;
        head = cur;

    }
}

template<typename Type>
void LinkedList<Type>::deleteNode(int nodeOffset)
{
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
}
