#pragma once
#include <iostream>
#include "List.h"

using namespace std;

template<typename T>
class Node{
public:
    T value;
    Node* next;
    Node(T val, Node* nxt = nullptr) : value(val), next(nxt) {
    }
};
template<typename T>
class SinglyLinkedList_head : public List<T>{
private:
    Node<T>* head;
    int listsize;

public:
    SinglyLinkedList_head() : head(nullptr), listsize(0){
    }
    virtual ~SinglyLinkedList_head(){
        Node<T>* current = head;
        while (current != nullptr){
            Node<T>* next =current->next;
            delete current;
            current =next;
        }
    }

    void push_back(T element){
        Node<T>* newNode = new Node<T>(element);
        if (head == nullptr){
            head =newNode;
        }
        else {
            Node<T>* t = head;
            while (t->next != nullptr){
                t = t->next;
            }
            t->next = newNode;
        }
        listsize++;
    }

    void push_front(T element){
        head = new Node<T>(element, head);
        listsize++;
    }

    void addElement(T element, int index){
        if (index < 0 or index > listsize){
            cout << "zly index" << endl;
            return;
        }
        if (index == 0){
            push_front(element);
        }
        else{
            Node<T>* t = head;
            for (int i = 1; i < index; i++){
                t = t->next;
            }
            t->next = new Node<T>(element, t->next);
            listsize++;
        }
    }

    T getElement(int index){
        if (index < 0 or index >= listsize){
            cout<<"Index out of range"<<endl;
            return T{};
        }
        Node<T>* t = head;
        for (int i = 0; i < index; i++){
            t = t->next;
        }
        return t->value;
    }

    int findElement(T element) const{
        Node<T>* t = head;
        int index = 0;
        while (t != nullptr){
            if (t->value == element){
                return index;
            }
            t = t->next;
            index++;
        }
        return -1; //nieznalaz³
    }

    int getSize() const{
        return listsize;
    }

    bool isEmpty() const{
        return head == nullptr;
    }
};
