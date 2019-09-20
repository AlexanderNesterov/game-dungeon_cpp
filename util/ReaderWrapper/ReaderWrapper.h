//
// Created by alexander on 20.09.2019.
//

#ifndef UNTITLED_READERWRAPPER_H
#define UNTITLED_READERWRAPPER_H


#include <string>

class ReaderWrapper {
public:
    static int newInt();
private:
    static bool isNumber(std::string);
};


#endif //UNTITLED_READERWRAPPER_H
