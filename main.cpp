#include <iostream>
#include "ArrayList.h"
#include "ArrayList.cpp"
#include "Hero.h"
#include "DwarfWarrior.h"
#include "MagicMan.h"
#include "ElfScout.h"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    ArrayList<Hero *> list(3);
    list.add(new DwarfWarrior());
    list.add(new MagicMan());
    list.add(new ElfScout());

    for (int i = 0; i < list.getSize(); ++i) {
        list.get(i)->allFields();
    }

    return 0;
}