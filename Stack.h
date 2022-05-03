//
// Created by vanes on 11/22/2021.
//

#ifndef MAIN_CPP_STACK_H
#define MAIN_CPP_STACK_H
#include "DoublyLinkedList.h"

template<class T>
class Stack {
public:
    void push(const T& item);
    void pop();
    T& top();
    bool empty();
    int size() const;
    T& peek(int n);

//    friend class Deck;

//private:
    DoublyLinkedList<T> list;
};

#include "Stack.cpp"
#endif //MAIN_CPP_STACK_H
