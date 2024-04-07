#pragma once
#include <iostream>
#include "List.h"
using namespace std;
//implements a dynamic array 
template<typename T>
class ArrayList : public List<T> 
{
    int size = 0;
    int capacity = 1;
    T *tab = new T[capacity];
public:
    ArrayList() {
    }
    ~ArrayList() {
        delete[] tab;
    }
    //adding elements - if the array reaches its capacity, it's resized to double its size and elements are copied to new array
    //adds a new element to the end of the array 
    void push_back(T element) {
        if (size == capacity) {
            capacity *= 2;
            T* newTab = new T[capacity];
            for (int i = 0; i < size; i++) {
                newTab[i] = tab[i];
            }
            delete[] tab;
            tab = newTab;
        }
        
        tab[size] = element;
        size++;
    };
    //adds a new element to the start of the array
    void push_front(T element) {
        if (size == capacity) {
            capacity *= 2;
            T* newTab = new T[capacity];
            for(int i = 0; i < size; i++) {
                newTab[i] = tab[i];
            }
            delete[] tab;
            tab = newTab;
        }

        for (int i = size; i > 0; i--) {
            tab[i] = tab[i - 1];
        }

        tab[0] = element;
        size++;
    };
    //inserts a new element at a given index
    void addElement(T element, int index) {
        if (index < 0 || index > size) {
            cout << "Invalid index!" << endl;
            return;
        }

        if (size == capacity) {
            capacity *= 2;
            T* newTab = new T[capacity];
            for (int i = 0; i < size; i++) {
                newTab[i] = tab[i];
            }
            delete[] tab;
            tab = newTab;
        }

        for (int i = size; i > index; i--) {
            tab[i] = tab[i - 1];
        }

        tab[index] = element;
        size++;
    };
    //retrieves element by index
    T getElement(int index) {
        return tab[index];
    };
    //searches for element and returns its index or -1 if not found
    int findElement(T element) const {
        for (int i = 0; i < size; ++i) {
            if (tab[i] == element) {
                return i;
            }
        }
        return -1;
    };
    //returns the number of elements
    int getSize() const {
        return size;
    };
    //gives current array capacity
    int getCapacity() const {
        return capacity;
    }
    //checks if list is empty
    bool isEmpty() const {
        return size ? true : false;
    };

};



