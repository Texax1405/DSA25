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

    // HELPER FUNCTION
    void checkIndex(int index);
    Node *getPreviousNodeOf(int index);
};

/* IMPLEMENTATION */
template <class T> 
BotkifyLinkedList<T>::BotkifyLinkedList(){
    this->head = new Node();
    this->tail = this->head;
    this->count = 0;
}

template <class T>
BotkifyLinkedList<T>::~BotkifyLinkedList(){
    this->clear();
    delete this->head
}

template <class T>
void BotkifyLinkedList<T>::add(T e){
    
    Node *newNode = new Node(e);
    this->tail->next = newNode;
    this->tail = newNode;

    this->count++;
}

template <class T>
void BotkifyLinkedList<T>::add(int index, T e){
    this->checkIndex(index);

    if (index == this->count) {
        this->add(e);
        return;
    }

    Node *prevNode = this->getPreviousNodeOf(index);
    Node *newNode = new Node(e, prevNode->next);

    prevNode->next = newNode;
    this->count++;
}

template <class T>
T BotkifyLinkedList<T>::removeAt(int index){
    this->checkIndex(index);
    Node *prevNode = this->getPreviousNodeOf(index);
    Node *removeNode = prevNode->next;
    T removeData = removeNode->data;

    if (removeNode == this->tail) {
        this->tail = prevNode;
    }

    prevNode->next = removeNode->next;

    delete removeNode;
    this->count--;
    return removeData;  
}

template <class T>
bool BotkifyLinkedList<T>::removeItem(T item){
    Node *prevNode = this->head;
    Node *currNode = prevNode->next;

    while (currNode != nullptr) {
        if (currNode->data == item) {
            prevNode->next = currNode->next;

            if (currNode == this->tail) {
                this->tail = prevNode;
            }

            delete currNode;
            this->count--;
            return true;
        }
    
        prevNode = currNode;
        currNode = currNode->next;
    }

    return false;
}

template <class T>
bool BotkifyLinkedList<T>::empty() const{
    return this->count == 0;
}

template <class T>
void BotkifyLinkedList<T>::clear(){
    Node *currNode = this->head;
    while (currNode != nullptr) {
        delete currNode;
        currNode = currNode->next;
    }

    this->head->next = nullptr;
    this->tail = this->head;
    this->count = 0;
}

template <class T>
int BotkifyLinkedList<T>::size() const{
    return this->count;
}

template <class T>
T& BotkifyLinkedList<T>::get(int index) const{
    this->cN heckIndex(index);
    Node *prevNode = this->getPreviousNodeOf(index);
    Node *currNode = prevNode->next;
    return currNode->data;
}

template <class T>
string BotkifyLinkedList<T>::toString() const{
    stringstream ss;
    Node *currNode = this-head->next;

    while (currNode != nullptr) {
        ss << currNode->data;

        if (currNode->next != nullptr) {
            ss << ",";
        }

        currNode = currNode->next;
    }


    return ss.str();
}

/* HELPER FUNCTION */
template <class T>
void BotkifyLinkedList<T>::checkIndex(int index){
    if (index < 0 || index > this->count){
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
