//
// Created by vanes on 11/22/2021.
//
#ifndef MAIN_CPP_DOUBLYLINKEDLIST_CPP
#define MAIN_CPP_DOUBLYLINKEDLIST_CPP
#include "DoublyLinkedList.h"
#include <cassert>

// Default constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {

}

// Copy constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& list) {
    *this = list;
}

//Destructor
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList<T>() {
    // Next time, it would be a good idea to call my deleteItem function! Also, check to see if deleteItem works to delete items from the list both forward and backward
    Node<T>* temp = head; // Create a temp node pointer and set equal to head
    Node<T>* discard; // Create a second node pointer to point at the node to be deleted. Note: since my list is doubly linked, I didn't need this pointer. Could have just done delete temp->prev

    while (temp != nullptr) // while there are still nodes in the list (i.e., if the list were empty to begin with, then head = nullptr; if the list were not empty to begin with, once you get to the last node, temp = temp->next is also nullptr)
        {
        discard = temp; // set discard equal to temp
        temp = temp->next; // move temp to the next node
        delete discard; // delete the node that discard is pointing to
        }

    head = nullptr;
    tail = nullptr;
}

// Inserts an item at the beginning of the list
template <class T>
void DoublyLinkedList<T>::push_front(T item) {
    // If list is empty, add first node
    if (head == nullptr)
        addFirstNode(item);
    else
    {
        Node<T>* n = createNode(item); // Create a new node
        n->next = head; // Point n's next to head
        head->prev = n; // Point head's prev to n
        head = n; // Point head to n
    }
}

// Inserts an item at the end of the list
template <class T>
void DoublyLinkedList<T>::push_back(T item) {
    // If list is empty, add first node
    if (head == nullptr)
        addFirstNode(item);

    else
    {
        Node<T>* n = createNode(item); // Create a new node
        n->prev = tail; // Point n's prev to tail
        tail->next = n; // Point tail's next to n
        tail = n; // Point tail to n
    }
}

// Inserts an item after targetItem. (Does nothing if targetItem is not on the list)
template <class T>
void DoublyLinkedList<T>::insertAfter(T targetItem, T newItem) {
    Node<T>* temp = find(targetItem); // Create a temp node pointer. Set equal to a pointer pointing at node containing targetItem

    if (temp != nullptr) // as long as targetItem is in the list
        {
        Node<T>* after = temp->next; // Create another node pointer that will point at the node AFTER target

        if(temp == tail)
            push_back(newItem);

        else
        {
            Node<T>* n = createNode(newItem); // Create a new node
            n->prev = temp; // point n's prev to temp
            n->next = after; // point n's next to after
            after->prev = n; // point after's prev to n
            temp->next = n; // point temp's next to n
        }
        }
}

// Inserts an item before targetItem. (Does nothing if targetItem is not on the list)
template <class T>
void DoublyLinkedList<T>::insertBefore(T targetItem, T newItem) { // I think there might be a way to use insert after in this function (e.g., insert after target->prev.
    // But I'm not sure how I'd deal with the if(temp==tail) code in insertAfter)
    Node<T>* temp = find(targetItem); // Create a temp node pointer and set equal to a pointer pointing at node containing targetItem

    if (temp != nullptr) // as long as targetItem is in the list
        {
        Node<T>* before = temp->prev; // Create another node pointer that will point at the node BEFORE target

        if(temp == head)
            push_front(newItem);

        else
        {
            Node<T>* n = createNode(newItem); // Create a new node
            n->next = temp; // point n's next to temp
            n->prev = before; // point n's prev to before
            before->next = n;
            temp->prev = n; // point temp's prev to n
        }
        }
}

// Deletes first instance of item. (Does nothing if targetItem is not on the list)
template <class T>
void DoublyLinkedList<T>::deleteItem(T item) {
    Node<T>* temp = find(item); // Create a temp node pointer and set equal to a pointer pointing at node containing targetItem

    deleteItem(temp);
}

// Deletes item pointed to by nodePtr
template <class T>
void DoublyLinkedList<T>::deleteItem(Node<T>* nodePtr) {
    if (nodePtr == head)
    {
        if (size() > 1) // If there is more than one node in the list
            {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
            }

        else // If there is only one node in the list
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
    }

    else if (nodePtr == tail)
    {
        if (size() == 2) // If there are only two nodes in the list
            {
            delete tail;
            tail = head;
            head->next = nullptr;
            }

        else // If there are more than two nodes in the list
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
    }

    else
    {
        // Create two node pointers. One will point to the node BEFORE the one to be deleted and one will point to the node AFTER to be deleted.
        Node<T>* before;
        Node<T>* after;

        before = nodePtr->prev;
        after = nodePtr->next;

        before->next = nodePtr->next;
        after->prev = nodePtr->prev;

        delete nodePtr;

        // I think this way is cleaner, but might be harder to follow
        //        nodePtr->prev->next = nodePtr->next;
        //        nodePtr->next->prev = nodePtr->prev;
        //        delete nodePtr;

    }

}

// Returns a pointer to item; if not found, returns nullptr
template <class T>
Node<T>* DoublyLinkedList<T>::find(T item) {
    Node<T>* temp = head; // Create a temp node pointer and set equal to head

    if (temp == nullptr)
        return nullptr;
    else
    {
        while (temp->next != nullptr && temp->data != item) // while there are still nodes in the list and temp's data != what we're looking for
            temp = temp->next; // Move temp to next node
            if (temp->data == item) // If temp's data == item, return temp
                return temp;
            else                    // Else, return nullptr
            return nullptr;
    }
}

// Returns 1 if list is empty, 0 otherwise
template <class T>
bool DoublyLinkedList<T>::isEmpty() {
    return head == nullptr;
}

// Returns size of the list
template <class T>
int DoublyLinkedList<T>::size() const {
    int count = 0; // counter

    Node<T>* temp = head; // Create a temp node pointer and set equal to head

    while (temp != nullptr) // while there are nodes in the list
    {
        temp = temp->next; // Move temp to next node
        count++; // Increase count
    }

    return count;
}

//Returns reference to item at front of list
template <class T>
T& DoublyLinkedList<T>::front() {
    assert(head != nullptr); // there must be items in the list

    return head->data;
}

// Returns reference to item at back of list
template <class T>
T& DoublyLinkedList<T>::back() {
    assert(head != nullptr); // there must be items in the list

    return tail->data;
}

// Deletes last item from the list
template <class T>
void DoublyLinkedList<T>::pop_back() {
    deleteItem(tail);
}

// Deletes first item from the list
template <class T>
void DoublyLinkedList<T>::pop_front() {
    deleteItem(head);
}

// Returns reference to item at nth position on the list (first item = 0)
template <class T>
T& DoublyLinkedList<T>::peek(int n) {
    assert(n >= 0 || n < size()); // n must be greater or equal to zero and less than size

    Node<T>* temp = head; // create a temp pointer and set = head

    for (int i = 0; i < n; ++i)
        temp = temp->next;

    return temp->data;
}

// Inserts an item at the end of the list (same as push_back function)
template <class T>
void DoublyLinkedList<T>::operator +=(T item) {
    push_back(item);
}

template <class T>
void DoublyLinkedList<T>::operator =(const DoublyLinkedList<T>& rhs) {
    if (this == &rhs) // if lhs and rhs refer to the same object, return.
        return;       // This takes care of the case where a user sets lhs = lhs, which would result in an error since we first we delete lhs

        this->~DoublyLinkedList(); // delete everything in lhs

        Node<T>* temp = rhs.head; // create a temp node pointer and set equal to rhs.head

        if (rhs.size() > 0) // if rhs has at least one node
            {
            for (int i = 0; i < rhs.size(); ++i) {
                push_back(temp->data); // push back node into lhs
                temp = temp->next; // iterate through the list, moving temp to the next node
            }
            }
}

// Outputs all items in the list
template <class S>
std::ostream& operator <<(std::ostream& out, const DoublyLinkedList<S>& list) {
    Node<S>* temp = list.head; // Create a temp node pointer and set equal to list.head

    while (temp != nullptr) // While temp != nullptr (i.e., while there are still nodes in the list)
    {
        out << temp->data << " "; // Output that node's data
        temp = temp->next; // Move temp to next node
    }
    out << std::endl;
    return out;
}

template <class T>
Node<T>* DoublyLinkedList<T>::createNode(T item) {
    Node<T>* n = new Node<T>;
    n->data = item;

    return n;
}

template <class T>
void DoublyLinkedList<T>::addFirstNode(T item) {
    Node<T>* n = createNode(item);
    head = n;
    tail = n;
}


#endif