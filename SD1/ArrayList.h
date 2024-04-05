#pragma once
#include <iostream>
#include "List.h"
using namespace std;

template<typename T>
class ArrayList : public List<T>
{
    int size = 0;
    int capacity = 1;
    T *tab = new T[capacity];
public:
    ArrayList() {}

    ~ArrayList() {
        delete[] tab;
    }

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

    T getElement(int index) {
        return tab[index];
    };

    int findElement(T element) const {
        for (int i = 0; i < size; ++i) {
            if (tab[i] == element) {
                return i;
            }
        }
        return -1;
    };

    int getSize() const {
        return size;
    };

    int getCapacity() const {
        return capacity;
    }

    bool isEmpty() const {
        return size ? true : false;
    };

};



