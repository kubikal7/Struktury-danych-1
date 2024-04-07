#include <iostream>
#include "List.h"
#include "ArrayList.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h" 
#include "Scanner.h"
using namespace std;

int main()
{
    /*ArrayList<int> arraylist;*/
    //SinglyLinkedList<int> list;
    DoublyLinkedList<int> list;
    Scanner<int> scanner; 

    scanner.scanFile("liczby.txt", list, 100);
    
    for (int i = 0; i < list.getSize();i++) {
        cout << list.getElement(i) << " ";
    }

    cout << endl;
    cout << "Znaleziony element: " << list.findElement(2998) << endl;
    cout << "Rozmiar listy: " << list.getSize()<<endl;
    //cout << list.getCapacity();

    return 0;
}

