#pragma once
#include <fstream>
#include <string>
#include "ArrayList.h"

using namespace std;

template<typename T>
class Scanner
{
public:
    //opens a file by name and reads elements from it
    void scanFileAndSaveFront(const string& filename, List<T>& list, const int& count) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Cannot open file!" << endl;
            return;
        }
        //inserts elements to list's front using push_front
        for (int i = 0; i < count; i++) {
            T data;
            if (file >> data) {
                list.push_front(data);
            }
            //error 
            else {
                cout << "Error reading data from file." << endl;
                break;
            }
        }

        file.close();
    }

    void scanFileAndSaveBack(const string& filename, List<T>& list, const int& count) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Cannot open file!" << endl;
            return;
        }
        //inserts elements to list's front using push_back
        for (int i = 0; i < count; i++) {
            T data;
            if (file >> data) {
                list.push_back(data);
            }
            //error 
            else {
                cout << "Error reading data from file." << endl;
                break;
            }
        }

        file.close();
    }

    void scanFileAndSaveAtIndex(const string& filename, List<T>& list, const int& index, const int& count) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Cannot open file!" << endl;
            return;
        }
        //inserts elements to list's using addElement
        for (int i = 0; i < count; i++) {
            T data;
            if (file >> data) {
                list.addElement(data, index);
            }
            //error 
            else {
                cout << "Error reading data from file." << endl;
                break;
            }
        }

        file.close();
    }
};
