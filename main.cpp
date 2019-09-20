#include <iostream>
#include "util/ArrayList/ArrayList.h"
#include "util/ArrayList/ArrayList.cpp"
#include "characters/Hero.h"
#include "characters/DwarfWarrior.h"
#include "characters/MagicMan.h"
#include "characters/ElfScout.h"
#include "util/ReaderWrapper/ReaderWrapper.h"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
/*
    ArrayList<Hero *> list(3);
    list.add(new DwarfWarrior());
    list.add(new MagicMan());
    list.add(new ElfScout());

    for (int i = 0; i < list.getSize(); ++i) {
        list.get(i)->allFields();
        cout << endl;
    }*/

/*    int str = std::stoi("s");
    cout << str << endl;*/



    int num = ReaderWrapper::newInt();

    return 0;
}