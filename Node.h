//
// Created by vanes on 11/22/2021.
//

#ifndef MAIN_CPP_NODE_H
#define MAIN_CPP_NODE_H

template <class T>
struct Node {
    T data;
    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;
};
#endif //MAIN_CPP_NODE_H
