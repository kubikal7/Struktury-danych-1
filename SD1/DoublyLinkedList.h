#pragma once
#include <iostream>
#include "List.h"

using namespace std;

template<typename T>
class DNode{ //Represents the nodes in the list, each holding a value and pointers to both the previous and next nodes.
public:
    T value;
    DNode* prev;
    DNode* next;
    DNode(T val, DNode* prv = nullptr, DNode* nxt = nullptr) : value(val), prev(prv), next(nxt){
    }
};
//implements SinglyLinkedList with head and tail
template<typename T>
class DoublyLinkedList : public List<T>{
private:
    DNode<T>* head;
    DNode<T>* tail;
    int listsize;

public:

    //Initializes an empty list with head and tail set to nullptr and listsize to 0.
    DoublyLinkedList() : head(nullptr), tail(nullptr), listsize(0){
    }
    //Iterates through the list to delete all nodes, preventing memory leaks.
    virtual ~DoublyLinkedList(){
        DNode<T>* current = head;
        while (current != nullptr){
            DNode<T>* next = current->next;
            delete current;
            current = next;
        }
    }
    // Adds a new element to the end of the list. It directly accesses the tail, making the operation efficient.
    void push_back(T element){
        DNode<T>* newNode = new DNode<T>(element);
        if (tail == nullptr){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        listsize++;
    }
    // Inserts a new element at the beginning of the list, updating head and prev pointer of the old head.
    void push_front(T element){
        DNode<T>* newNode = new DNode<T>(element);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        listsize++;
    }
    // Inserts a new element at a specified index, updating relevant next and prev pointers to maintain list integrity.
    void addElement(T element, int index){
        if (index < 0 or index > listsize){
            cout << "zly index" <<endl;
            return;
        }
        if (index == 0) {
            push_front(element);
        }
        else if (index == listsize){
            push_back(element);
        }
        else {
            DNode<T>* current = head;
            for (int i = 0; i < index; i++){
                current = current->next;
            }
            DNode<T>* newNode = new DNode<T>(element, current->prev, current);
            current->prev->next = newNode;
            current->prev = newNode;
            listsize++;
        }
    }
    // Retrieves an element by index, optimizing search direction based on the index's position relative to the list's size.
    T getElement(int index){
        if (index < 0 or index >= listsize){
            cout << "out of range" << endl;
            return T{};
        }
        DNode<T>* current;
        if (index < listsize / 2){
            current = head;
            for (int i = 0; i < index; i++){
                current = current->next;
            }
        }
        else {
            current = tail;
            for (int i = listsize - 1; i > index; i--){
                current = current->prev;
            }
        }
        return current->value;
    }
    // Searches for an element and returns its index or -1 if not found. It traverses the list starting from head.
    int findElement(T element) const{
        DNode<T>* current = head;
        int index = 0;
        while (current != nullptr){
            if (current->value == element){
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }
    // Returns the current size of the list.
    int getSize() const{
        return listsize;
    }
    // Checks whether the list is empty by verifying if listsize is 0
    bool isEmpty() const{
        return listsize == 0;
    }
};

