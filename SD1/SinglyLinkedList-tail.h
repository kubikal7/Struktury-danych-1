#pragma once
#include <iostream>
#include "List.h"

using  namespace std;


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
    virtual ~SinglyLinkedList_tail(){                           //iterates through the list to delete all nodes preventing memory leaks
        Node<T>* current = head;
        while (current != nullptr){
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
    
    void push_back(T element){                                  //method adding new element to the end of the list (using the tail pointer avoiding going through full list)
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
    
    void push_front(T element){                                 //method adds new element to the start of the list (adjusting head and sometimes tail)
        Node<T>* newNode = new Node<T>(element, head);
        head = newNode;
        if (tail == nullptr){ 
            tail = newNode;
        }
        listsize++;
    }
    
    void addElement(T element, int index){                      //method inserts new element at a given index (similar to head list but adjusts tail if adding at the end)
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

    T pop_front() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return T();                                         //if list is empty returns default T
        }

        T poppedValue = head->value; 
        Node<T>* temp = head;                                   //keep pointer on first element
        head = head->next;                                      //change head pointer to next element
        delete temp; 
        listsize--; 

        if (head == nullptr) {
            tail = nullptr;                                     //is list is now empty set tail pointer to nullptr
        }

        return poppedValue; 
    }

    T pop_back() {                                              //if list is empty returns default T
        if (head == nullptr) {
            cout<< "List is empty" << endl;
            return T(); 
        }

        T poppedValue;
        if (head->next == nullptr) {                            //if list has just one element
            poppedValue = head->value;
            delete head;
            head = nullptr;
            tail = nullptr; 
        }
        else {
            Node<T>* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            poppedValue = current->next->value; 
            delete current->next; 
            current->next = nullptr;                            //set next pointer of new last element to nullptr
            tail = current;                                     //set tail pointer to new last element
        }
        listsize--; 

        return poppedValue;
    }

    T deleteElement(int index) {
        if (index < 0 || index >= listsize) {
            cout << "Invalid index!" << endl;
            return T();                                         //if list is empty returns default T
        }

        Node<T>* deletedNode;
        if (index == 0) {
            deletedNode = head;
            head = head->next;
            if (head == nullptr) {                              //if head is nullptr - tail is also nullptr
                tail = nullptr; 
            }
        }
        else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            deletedNode = current->next;
            current->next = deletedNode->next;                  //set next pointer to next of deleted element
            if (current->next == nullptr) {
                tail = current;                                 //if now element is last, set tail to this element
            }
        }

        T deletedValue = deletedNode->value;
        delete deletedNode;
        listsize--;

        return deletedValue;
    }

    
    T getElement(int index){                                    //method returns element by index
        if (index < 0 or index >= listsize){
            cout<<"out of range"<<endl;
            return T();
        }
        Node<T>* t = head;
        for (int i = 0; i < index; i++){
            t = t->next;
        }
        return t->value;
    }
    
    int findElement(T element) const{                           //method searches for element and returns its index or -1 if not found (starting from head)
        Node<T>* t = head;
        int index = 0;
        while (t != nullptr){
            if (t->value == element){
                return index;
            }
            t = t->next;
            index++;
        }
        return -1;                                              //return -1 if element not found
    }
    
    int getSize() const{                                        //method returns the current size
        return listsize;
    }
    
    bool isEmpty() const{                                       //method checks if list is empty
        return head == nullptr;
    }
};
