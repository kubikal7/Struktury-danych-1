#pragma once
#include <fstream>
#include <string>
#include "ArrayList.h"

using namespace std;
//reading data from a file and inserting it into list
template<typename T>
class Scanner
{
public:
    //opens a file by name and reads elements from it
    void scanFile(const string& filename, List<T>& list, int count) {
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
};
