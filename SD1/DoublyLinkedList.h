#pragma once
#include <iostream>
#include "List.h"

using namespace std;

template<typename T>
class DNode{
public:
    T value;
    DNode* prev;
    DNode* next;
    DNode(T val, DNode* prv = nullptr, DNode* nxt = nullptr) : value(val), prev(prv), next(nxt){
    }
};

template<typename T>
class DoublyLinkedList : public List<T>{
private:
    DNode<T>* head;
    DNode<T>* tail;
    int listsize;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), listsize(0){
    }
    virtual ~DoublyLinkedList(){
        DNode<T>* current = head;
        while (current != nullptr){
            DNode<T>* next = current->next;
            delete current;
            current = next;
        }
    }
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
    int getSize() const{
        return listsize;
    }
    bool isEmpty() const{
        return listsize == 0;
    }
};

