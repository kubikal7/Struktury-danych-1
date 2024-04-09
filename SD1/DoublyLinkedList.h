#pragma once
#include <iostream>
#include "List.h"

using namespace std;

template<typename T>
class DNode{                                                        //node class definition, each holding a value and pointers to previous and next nodes
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
    
    virtual ~DoublyLinkedList(){                                    //iterates through the list to delete all nodes preventing memory leaks
        DNode<T>* current = head;
        while (current != nullptr){
            DNode<T>* next = current->next;
            delete current;
            current = next;
        }
    }
    
    void push_back(T element){                                      //method adds new element to the end of the list (directly accesses tail making operation efficient)
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
    
    void push_front(T element){                                     //method inserts new element to the start of the list (updating head and prev pointer of old head)
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
    
    void addElement(T element, int index){                          //method inserts new element at a given index (updating next and prev pointers to keep list integrity)
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
            current->prev->next = newNode;                          //set next pointer of element in front of new element
            current->prev = newNode;                                //set prev pointer of element behind new element
            listsize++;
        }
    }

    T pop_front() {
        if (head == nullptr) {
            cout << "List is empt!" << endl;
            return T();                                             //if list is empty returns default T
        }

        T poppedValue = head->value;                                //keep first element value
        DNode<T>* temp = head;                                      //keep pointer on first element
        head = head->next; 
        if (head != nullptr) {
            head->prev = nullptr;                                   // if next element exists it sets prev pointer to nullptr
        }
        else {
            tail = nullptr;                                         // if there is no more element, tail is nullptr
        }
        delete temp; 
        listsize--; 

        return poppedValue; 
    }

    T pop_back() {
        if (tail == nullptr) {
            cout << "List is empt!" << endl;
            return T();                                             //if list is empty returns default T
        }

        T poppedValue = tail->value;                                //keep last element value
        DNode<T>* temp = tail;                                      //keep pointer on last element
        tail = tail->prev; 
        if (tail != nullptr) {
            tail->next = nullptr;                                   // if prev element exists it sets next pointer to nullptr
        }
        else {
            head = nullptr;                                         // if there is no more element, head is nullptr
        }
        delete temp; 
        listsize--; 

        return poppedValue; 
    }

    T deleteElement(int index) {                                    //if list is empty or given index >= listsize returns default T
        if (index < 0 || index >= listsize) {
            cout << "Invalid index!" << endl;
            return T(); 
        }

        DNode<T>* deletedNode;
        if (index == 0) {                                           //if index==0 delete first element
            deletedNode = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
        }
        else if (index == listsize - 1) {                           //if index==listsize-1 delete last element
            deletedNode = tail;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
        }
        else {
            DNode<T>* current;
            if (index < listsize / 2) {                             //if given index is in first half of list start iterate from begin
                current = head;
                for (int i = 0; i < index; i++) {
                    current = current->next;
                }
            }
            else {                                                  //if given index is in second half of list start iterate from end
                current = tail;
                for (int i = listsize - 1; i > index; i--) {
                    current = current->prev;
                }
            }
            deletedNode = current;
            current->prev->next = current->next;                    //set next pointer of element in front of deleted element
            current->next->prev = current->prev;                    //set prev pointer of element behind deleted element
        }

        T deletedValue = deletedNode->value;
        delete deletedNode;
        listsize--;

        return deletedValue;
    }

    
    T getElement(int index){                                        //method returns element by index, (search direction based on index's position relative to list size)
        if (index < 0 or index >= listsize){
            cout << "out of range" << endl;
            return T();                                             //if list is empty or given index >= listsize returns default T
        }
        DNode<T>* current;
        if (index < listsize / 2){                                  //if given index is in first half of list start iterate from begin
            current = head;
            for (int i = 0; i < index; i++){
                current = current->next;
            }
        }
        else {                                                      //if given index is in second half of list start iterate from end
            current = tail;
            for (int i = listsize - 1; i > index; i--){
                current = current->prev;
            }
        }
        return current->value;
    }
    
    int findElement(T element) const{                               //method searches for element and returns its index or -1 if not found (starting from head)
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
    
    int getSize() const{                                            //method returns the current size
        return listsize;
    }
    
    bool isEmpty() const{                                           //method checks if list is empty
        return listsize == 0;
    }
};

