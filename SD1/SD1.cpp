#include <iostream>
#include "List.h"
#include "ArrayList.h"
#include "SinglyLinkedList-head.h"
#include "SinglyLinkedList-head.h"
#include "DoublyLinkedList.h" 
#include "Scanner.h"
using namespace std;

int main()
{
    //ArrayList<int> arraylist;
    //SinglyLinkedList<int> list;
    DoublyLinkedList<int> list; //initializes data structure here doublylinkedlist
    Scanner<int> scanner; 

    //uses a scanner to fill it with data from txt
    scanner.scanFile("liczby.txt", list, 100); 
    
    for (int i = 0; i < list.getSize();i++) {
        cout << list.getElement(i) << " ";
    }
    //operations to show the list's functionality
    cout << endl;
    cout << "found element: " << list.findElement(2998) << endl;
    cout << "size: " << list.getSize()<<endl;
    //cout << list.getCapacity();

    return 0;
}

