#pragma once
#include <iostream>
#include "List.h"

using  namespace std;

template<typename T>
class Node { // Definicja klasy wêz³a
public:
    T value;  // Dane przechowywane w wêŸle
    Node* next; // WskaŸnik na nastêpny wêze³ w liœcie
    // Konstruktor inicjalizuj¹cy wêze³ wartoœci¹ i opcjonalnym wskaŸnikiem na nastêpny wêze³
    Node(T val, Node* nxt = nullptr) : value(val), next(nxt) {
    }
};
//implements SinglyLinkedList with head and tail
template<typename T>
class SinglyLinkedList_tail : public List<T>{
private:
    Node<T>* head;
    Node<T>* tail;
    int listsize;

public:
    //similar to list with head but with a tail pointer for efficient push_back
    SinglyLinkedList_tail() : head(nullptr), tail(nullptr), listsize(0){
    }
    virtual ~SinglyLinkedList_tail(){
        Node<T>* current = head;
        while (current != nullptr){
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
    //adding new element to the end of the list (using the tail pointer avoiding going through full list)
    void push_back(T element){
        Node<T>* newNode = new Node<T>(element);
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode; 
            tail = newNode; 
        }
        listsize++;
    }
    //adds new element to the start of the list
    void push_front(T element){
        Node<T>* newNode = new Node<T>(element, head);
        head = newNode;
        if (tail == nullptr){ 
            tail = newNode;
        }
        listsize++;
    }
    //inserts new element at a given index
    void addElement(T element, int index){
        if (index < 0 or index > listsize){
            cout << "zly index" <<endl;
            return;
        }
        if (index == 0) {
            push_front(element);
        }
        else if (index == listsize) { 
            push_back(element);
        }
        else {
            Node<T>* t = head;
            for (int i = 1; i < index; i++) {
                t = t->next;
            }
            t->next = new Node<T>(element, t->next);
            listsize++;
        }
    }
    //retrieves element by index
    T getElement(int index){
        if (index < 0 or index >= listsize){
            cout<<"out of range"<<endl;
            return T{};
        }
        Node<T>* t = head;
        for (int i = 0; i < index; i++){
            t = t->next;
        }
        return t->value;
    }
    //searches for element and returns its index or -1 if not found (starting from head)
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
        return -1;
    }
    //returns the current size
    int getSize() const{
        return listsize;
    }
    //checks if list is empty
    bool isEmpty() const{
        return head == nullptr;
    }
};
