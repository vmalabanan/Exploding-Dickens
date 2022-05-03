//
// Created by vanes on 11/22/2021.
//

#ifndef MAIN_CPP_DOUBLYLINKEDLIST_H
#define MAIN_CPP_DOUBLYLINKEDLIST_H
#include "Node.h"
#include <iostream>

template <class T>
class DoublyLinkedList {
public:
    // Default constructor
    DoublyLinkedList();
    // Copy constructor
    DoublyLinkedList<T>(const DoublyLinkedList<T>& list);
    //Destructor
    ~DoublyLinkedList<T>();

    // Note: functions takes an argument of type T and not Node<T>.
    // Users of the class should not need to know that nodes are involved.

    void push_front(T item); // Inserts an item at the beginning of the list
    void push_back(T item); // Inserts an item at the end of the list

    void insertAfter(T targetItem, T newItem); // Inserts an item after targetItem. (Does nothing if targetItem is not on the list)
    void insertBefore(T targetItem, T newItem); // Inserts an item before targetItem. (Does nothing if targetItem is not on the list)
    void deleteItem(T item); // Deletes first instance of item. (Does nothing if targetItem is not on the list)
    void deleteItem(Node<T>* nodePtr); // Deletes item pointed to by nodePtr

    Node<T>* find(T item); // Returns a pointer to item; if not found, returns nullptr
    bool isEmpty(); // Returns 1 if list is empty, 0 otherwise
    int size() const; // Returns size of the list

    T& front(); // Returns reference to item at front of list
    T& back(); // Returns reference to item at back of list
    void pop_back(); // Deletes last item from the list
    void pop_front(); // Deletes first item from the list
    T& peek(int n); // Returns reference to item at nth position on the list (first item = 0)

    void operator +=(T item); // Inserts an item at the end of the list (same as push_back)
    void operator =(const DoublyLinkedList<T>& rhs);

    template <class S>
            friend std::ostream& operator <<(std::ostream& out, const DoublyLinkedList<S>& list); // Outputs all data in the list

private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    Node<T>* createNode(T item);
    void addFirstNode(T item);
};

#include "DoublyLinkedList.cpp"
#endif //MAIN_CPP_DOUBLYLINKEDLIST_H
