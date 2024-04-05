#include <iostream>
#include "List.h"
#include "ArrayList.h"
#include "Scanner.h"
using namespace std;

int main()
{
    ArrayList<int> arraylist;
    Scanner<int> myScanner; 

    myScanner.scanFile("liczby.txt", arraylist, 100);
    
    for (int i = 0; i < arraylist.getSize();i++) {
        cout << arraylist.getElement(i) << " ";
    }
    cout << endl;
    cout << arraylist.findElement(2998) << endl;
    cout<<arraylist.getSize()<<endl;
    cout << arraylist.getCapacity();
}

