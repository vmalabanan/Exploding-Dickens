//
// Created by vanes on 11/22/2021.
//

#ifndef MAIN_CPP_QUEUE_H
#define MAIN_CPP_QUEUE_H
#include "DoublyLinkedList.h"

template<class T>
class Queue {
public:
    void push(const T& item);
    void pop();
    T& front();
    bool empty();
    int size();
    T& peek(int n);

private:
    DoublyLinkedList<T> list;
};

#include "Queue.cpp"
#endif //MAIN_CPP_QUEUE_H
