//
// Created by vanes on 11/22/2021.
//
#ifndef MAIN_CPP_STACK_CPP
#define MAIN_CPP_STACK_CPP
#include "Stack.h"


template<class T>
void Stack<T>::push(const T& item){
    list.push_back(item);
}

template<class T>
void Stack<T>::pop() {
    list.pop_back();
}

template<class T>
T& Stack<T>::top() {
    return list.back();
}

template<class T>
bool Stack<T>::empty() {
    return list.empty();
}

template<class T>
int Stack<T>::size() const {
    return list.size();
}

template<class T>
T& Stack<T>::peek(int n) {
    return list.peek(n);
}


#endif