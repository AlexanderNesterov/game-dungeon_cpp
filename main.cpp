/*#include <iostream>
#include "util/ArrayList/ArrayList.h"
#include "util/ArrayList/ArrayList.cpp"
#include "characters/Hero.h"
#include "characters/DwarfWarrior.h"
#include "characters/MagicMan.h"
#include "characters/ElfScout.h"
#include "util/ReaderWrapper/ReaderWrapper.h"*/
#include "Game.h"
//#include "Game.cpp"

using namespace std;

int main() {
/*    std::cout << "Hello, World!" << std::endl;
    ArrayList<Hero *> list(3);
    list.add(new DwarfWarrior());
    list.add(new MagicMan());
    list.add(new ElfScout());

    for (int i = 0; i < list.getSize(); ++i) {
        list.get(i)->allFields();
        cout << endl;
    }

    cout << list.get(4) << endl;*/

    //int num = ReaderWrapper::newInt();

    Game *game = new Game();
    game->startGame();

    return 0;
}