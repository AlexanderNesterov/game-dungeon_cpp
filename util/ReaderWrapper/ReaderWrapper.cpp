//
// Created by alexander on 20.09.2019.
//

#include "ReaderWrapper.h"
#include <iostream>
using namespace std;

int ReaderWrapper::newInt() {
    while (true) {
        std::string str;
        cin >> str;

        if (isNumber(str)) {
            return std::stoi(str);
        } else {
            cout << "Не является целым числом!" << endl;
        }
    }
}

bool ReaderWrapper::isNumber(std::string str) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] < 48 || str[i] > 57) {
            return false;
        }
    }

    return true;
}