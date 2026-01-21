#ifndef BOTKIFY_LINKED_LIST_H
#define BOTKIFY_LINKED_LIST_H

#include "main.h"

template <class T>
class BotkifyLinkedList
{
private:
    class Node
    {
    public:
        T data;
        Node* next;
        Node* extra;

        Node();
        Node(const T& data, Node* next = nullptr, Node* extra = nullptr);
    };

    Node* head;
    Node* tail;
    int count;

public:
    BotkifyLinkedList();
    ~BotkifyLinkedList();

    void add(T e);
    void add(int index, T e);
    T removeAt(int index);
    bool removeItem(T item);

    bool empty() const;
    int size() const;
    void clear();

    T& get(int index) const;

    string toString() const;

    // Additional function
    void checkIndex(int index);
    Node *getPreviousNodeOf(int index);
};

/* TODO */
template <class T> 
BotkifyLinkedList<T>::BotkifyLinkedList(){
    this->head = new Node();
    this->tail = this->head;
    this->count = 0;
}

template <class T>
BotkifyLinkedList<T>::~BotkifyLinkedList(){
    this->clear();
}

template <class T>
void BotkifyLinkedList<T>::add(T e){
    
    Node *newNode = new Node(e);
    tail->next = newNode;
    tail = newNode;

    this->count++;
}

template <class T>
void BotkifyLinkedList<T>::add(int index, T e){
    this->checkIndex(index);
    Node *prevNode = this->getPreviousNodeOf(index);
    Node *newNode = new Node(e, prevNode->next);

    if (getNode->next == nullptr){
        this->add(e);
    }

    getNode->next = newNode;
    this->count++;
}

template <class T>
T BotkifyLinkedList<T>::removeAt(int index){
    this->checkIndex(index);
    Node *currNode = this->get(index);
    

}

template <class T>
T& BotkifyLinkedList<T>::get(int index) const{
    this->chekcIndex(index);
    Node *currNode = this->head;

    for (int i = 0; i < index; i++) {
        currNode = currNode->next;
    }

    return currNode->data;
}

/* ADDITIONAL FUNCTION */
template <class T>
void BotkifyLinkedList<T>::checkIndex(int index){
    if (index < 0 || index >> this->count){
        throw out_of_range("Index is invalid!");
    }
}

template <class T>
typename BotkifyLinkedList<T>::Node *BotkifyLinkedList<T>::getPreviousNodeOf(int index){
    Node *currNode = this->head;
    for (int i = 0; i < index; i++){
        currNode = currNode->next;
    }

    return currNode;
}


#endif // BOTKIFY_LINKED_LIST_H
