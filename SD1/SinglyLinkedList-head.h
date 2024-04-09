#pragma once
#include <iostream>
#include "List.h" 

using namespace std;

template<typename T>
class Node { 
public:
    T value;  
    Node* next; 
    Node(T val, Node* nxt = nullptr) : value(val), next(nxt) {
    }
};

template<typename T>
class SinglyLinkedList_head : public List<T> {
private:
    Node<T>* head;                                              //head of the list
    int listsize;                                               //size of the list (number of nodes)
public:
    SinglyLinkedList_head() : head(nullptr), listsize(0) {
    }
    virtual ~SinglyLinkedList_head() {                          //iterates through the list to delete all nodes preventing memory leaks
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
    
    void push_back(T element) {                                 //method adding new element to the end of the list
        Node<T>* newNode = new Node<T>(element);
        if (head == nullptr) {                                  //if list is empty
            head = newNode;
        }
        else {
            Node<T>* t = head;
            while (t->next != nullptr) {
                t = t->next;
            }
            t->next = newNode;
        }
        listsize++;
    }
    
    void push_front(T element) {                                //method adds new element to the start of the list
        head = new Node<T>(element, head);
        listsize++;
    }
    
    void addElement(T element, int index) {                     //method inserts new element at a given index
        if (index < 0 or index > listsize) {
            cout << "Wrong index" << endl;
            return;
        }
        if (index == 0) {
            push_front(element);
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

    T pop_front() {                                             //method deletes element at start of the list
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return T();                                         //if list is empty returns default T
        }

        T poppedValue = head->value; 
        Node<T>* temp = head;                                   //keep pointer on first element
        head = head->next;                                      //change head pointer to next element
        delete temp;
        listsize--;

        return poppedValue;
    }

    T pop_back() {                                              //method deletes element at end of the list
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return T();                                         //if list is empty returns default T
        }

        T poppedValue;
        if (head->next == nullptr) {                            //if list has just one element
            poppedValue = head->value;
            delete head;
            head = nullptr;
        }
        else {
            Node<T>* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            poppedValue = current->next->value;                 //keep value of last element
            delete current->next;                               //delete last element
            current->next = nullptr;                            //set pointer next of new last element to nullptr
        }
        listsize--;

        return poppedValue;
    }

    T deleteElement(int index) {                                //delete element at given index
        if (index < 0 || index >= listsize) {
            cout << "Invalid index!" << endl;
            return T();                                         //if list is empty or given index <0 returns default T
        }

        Node<T>* deletedNode;
        if (index == 0) {
            deletedNode = head;
            head = head->next;
        }
        else {
            Node<T>* current = head;
            for (int i = 1; i < index; i++) {
                current = current->next;
            }
            deletedNode = current->next;                        //set object to delete
            current->next = deletedNode->next;                  //set pointer next to new object
        }

        T deletedValue = deletedNode->value;
        delete deletedNode;
        listsize--;

        return deletedValue;
    }

    
    T getElement(int index) {                                   //method returns element by index
        if (index < 0 or index >= listsize) {
            cout << "Index out of range" << endl;
            return T();                                         //if list is empty or given index <0 returns default T
        }
        Node<T>* t = head;
        for (int i = 0; i < index; i++) {
            t = t->next;
        }
        return t->value;
    }
    
    int findElement(T element) const {                          //method searches for element and returns its index or -1 if not found
        Node<T>* t = head;
        int index = 0;
        while (t != nullptr) {
            if (t->value == element) {
                return index;
            }
            t = t->next;
            index++;
        }
        return -1;
    }
    
    int getSize() const {                                       //method returns the current size
        return listsize;
    }
    
    bool isEmpty() const {                                      //method checks if list is empty
        return head == nullptr;
    }
};
