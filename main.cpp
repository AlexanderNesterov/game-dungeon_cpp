#include <iostream>
#include "ArrayList.h"
#include "ArrayList.cpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    ArrayList<char > arrayList(8);
    arrayList.toString();

    for (int i = 0; i < 15; ++i) {
        arrayList.add('a' + i);
        if (i == 10) {
            arrayList.toString();
        }
    }

    arrayList.toString();
    cout << arrayList.get(17) << endl;
    cout << arrayList.getSize() << endl;
    return 0;
}