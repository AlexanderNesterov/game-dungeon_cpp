#include <iostream>
#include "ArrayList.h"
#include "ArrayList.cpp"
#include "Hero.h"
#include "DwarfWarrior.h"
//#include "Hero.cpp"

int main() {
/*    std::cout << "Hello, World!" << std::endl;
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
    cout << arrayList.getSize() << endl;*/
    Hero *hero = new DwarfWarrior("dw", 50, 15, 20, "ii");

    return 0;
}