#pragma once
#include <fstream>
#include <string>
#include "ArrayList.h"

using namespace std;

template<typename T>
class Scanner
{
public:
    void scanFile(const std::string& filename, List<T>& list, int count) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Cannot open file!" << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            T data;
            if (file >> data) {
                list.push_front(data);
            }
            else {
                cout << "Error reading data from file." << endl;
                break;
            }
        }

        file.close();
    }
};
