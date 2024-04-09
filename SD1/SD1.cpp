#include <iostream>
#include <chrono>
#include "List.h"
#include "ArrayList.h"
#include "SinglyLinkedList-head.h"
#include "SinglyLinkedList-tail.h"
#include "DoublyLinkedList.h" 
#include "Scanner.h"
using namespace std;

int main()
{
    /*List<int>* list = nullptr;
    Scanner<int> scanner;
    
    const int numIterations = 100;
    double totalExecutionTime = 0.0;

    for (int i = 0; i < numIterations; i++) {
        list = new ArrayList<int>();

        scanner.scanFileAndSaveFront("liczby.txt", *list, 120000);

        auto start = chrono::high_resolution_clock::now();                          //tests

        list->addElement(24,1000);

        auto end = chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::micro> elapsed = end - start;
        totalExecutionTime += elapsed.count();

        delete list;
    }

    double averageExecutionTime = totalExecutionTime / numIterations; 
    cout << "Średni czas wykonania push_back: " << averageExecutionTime << " mikrosekund." << endl;*/

    /*for (int i = 0; i < list.getSize();i++) {
        cout << list.getElement(i) << " ";
    }*/

    List<int>* list = nullptr;
    Scanner<int> scanner;

    int structure_type;
    int load_type;
    int load_size;
    int action;
    int quit = false;

    while (!quit) {
        cout << "Which structure would you like choose?" << endl;
        cout << "1. ArrayList" << endl << "2. SinglyLinkedList_head" << endl << "3. SinglyLinkedList_tail" << endl << "4. DoublyLinkedList" << endl;
        cout << "Choose: ";
        cin >> structure_type;

        if (structure_type == 1)
            list = new ArrayList<int>();                //creating Arraylist object at List pointer
        else if (structure_type == 2)
            list = new SinglyLinkedList_head<int>();    //creating Singly Linked List without tail object at List pointer
        else if (structure_type == 3)
            list = new SinglyLinkedList_tail<int>();    //creating Singly Linked List with tail object at List pointer
        else if (structure_type == 4)
            list = new DoublyLinkedList<int>();         //creating Doubly Linked List object at List pointer

        if (list != nullptr) {

            cout << endl;

            cout << "How many elements would you like load from file?: ";
            cin >> load_size;

            cout << endl;

            cout << "Which type of load would you like choose?" << endl;
            cout << "1. Save At Front" << endl << "2. Save At Back" << endl;
            cout << "Choose: ";
            cin >> load_type;

            if (load_type == 1)
                scanner.scanFileAndSaveFront("liczby.txt", *list, load_size);       //load numbers from file liczby.txt and saving at front of existed list
            else if (load_type == 2)
                scanner.scanFileAndSaveBack("liczby.txt", *list, load_size);

            cout << endl;


            while (!quit) {
                cout << "Wchis action would you like choose?" << endl;
                cout << "1. Add element at front" << endl << "2. Add element at index" << endl << "3. Add alement at back" << endl << endl;
                cout << "4. Delete element at front" << endl << "5. Delete element at index" << endl << "6. Delete alement at back" << endl << endl;
                cout << "7. Print list" << endl << "8. Change structure" << endl << "9. Reset list" << endl << "10. Quit program" << endl;
                cout << "Choose: ";
                cin >> action;
                if (action == 1) {
                    int value;
                    cout << "Enter a value of element: ";
                    cin >> value;
                    auto start = chrono::high_resolution_clock::now();                      //timer
                    list->push_front(value);                                                //adding element at front of list
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double, std::micro> elapsed = end - start;
                    cout << "Operation time: " << elapsed.count() << " microseconds" << endl;
                }
                else if (action == 2) {
                    int value, index;
                    cout << "Enter a value of element: ";
                    cin >> value;
                    cout << endl << "Enter an index: ";
                    cin >> index;
                    auto start = chrono::high_resolution_clock::now();                  //timer
                    list->addElement(value, index);                                     //adding element inside of list
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double, std::micro> elapsed = end - start;
                    cout << "Operation time: " << elapsed.count() << " microseconds" << endl;
                }
                else if (action == 3) {
                    int value;
                    cout << "Enter a value of element: ";
                    cin >> value;
                    auto start = chrono::high_resolution_clock::now();                  //timer
                    list->push_back(value);                                             //adding element at back of list
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double, std::micro> elapsed = end - start;
                    cout << "Operation time: " << elapsed.count() << " microseconds" << endl;
                }
                else if (action == 4) {
                    auto start = chrono::high_resolution_clock::now();                      //timer
                    list->pop_front();                                                      //deleting element at front of list
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double, std::micro> elapsed = end - start;
                    cout << "Operation time: " << elapsed.count() << " microseconds" << endl;
                }
                else if (action == 5) {
                    int index;
                    cout << "Enter an index: ";
                    cin >> index;
                    auto start = chrono::high_resolution_clock::now();                      //timer
                    list->deleteElement(index);                                             //deleting element inside of list
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double, std::micro> elapsed = end - start;
                    cout << "Operation time: " << elapsed.count() << " microseconds" << endl;
                }
                else if (action == 6) {
                    auto start = chrono::high_resolution_clock::now();                      //timer
                    list->pop_back();                                                       //deleting element at back of list
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double, std::micro> elapsed = end - start;
                    cout << "Operation time: " << elapsed.count() << " microseconds" << endl;
                }
                else if (action == 7) {
                    for (int i = 0; i < list->getSize();i++) {
                        cout << list->getElement(i) << " ";                                 //print list
                    }
                    cout << endl;
                }
                else if (action == 8) {
                    delete list;                                                            //deleting list and return to first step in menu
                    break;
                }
                else if (action == 9) {                                                     //reset list means deleting list and make the same list with the same settings
                    delete list;
                    if (structure_type == 1)
                        list = new ArrayList<int>();
                    else if (structure_type == 2)
                        list = new SinglyLinkedList_head<int>();
                    else if (structure_type == 3)
                        list = new SinglyLinkedList_tail<int>();
                    else if (structure_type == 4)
                        list = new DoublyLinkedList<int>();
                    if (load_type == 1)
                        scanner.scanFileAndSaveFront("liczby.txt", *list, load_size);
                    else if (load_type == 2)
                        scanner.scanFileAndSaveBack("liczby.txt", *list, load_size);

                    cout << "List reseted" << endl;
                }
                else if (action == 10)                                                      //close 2x while loops
                    quit = true;

                cout << endl;
            }
            cout << endl;
        }
    }
    delete list;

return 0;
}

