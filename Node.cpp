#include <iostream>

template<class T>
Node<T>::Node() : next(NULL) {
	data = NULL;
}

template<class T>
Node<T>::Node(T p_data) : next(NULL), data(p_data){}

template<class T>
Node<T>::~Node(){}
