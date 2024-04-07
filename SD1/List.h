#pragma once
template<typename T>
//interface defining all operations we will use on different structures
class List
{
public:
    virtual ~List() {}

    virtual void push_back(T element) = 0;

    virtual void push_front(T element) = 0;

    virtual void addElement(T element, int index) = 0;

    virtual T getElement(int index) = 0;

    virtual int findElement(T element) const = 0;

    virtual int getSize() const = 0;

    virtual bool isEmpty() const = 0;
};

