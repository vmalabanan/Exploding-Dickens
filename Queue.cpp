//
// Created by vanes on 11/22/2021.
//
#ifndef MAIN_CPP_QUEUE_CPP
#define MAIN_CPP_QUEUE_CPP
#include "Queue.h"

template<class T>
void Queue<T>::push(const T& item) {
    list.push_back(item);
}

template<class T>
void Queue<T>::pop() {
    list.pop_front();
}

template<class T>
T& Queue<T>::front() {
    return list.front();
}

template<class T>
bool Queue<T>::empty() {
    return list.empty();
}

template<class T>
int Queue<T>::size() {
    return list.size();
}

template<class T>
T& Queue<T>::peek(int n) {
    return list.peek(n);
}

#endif