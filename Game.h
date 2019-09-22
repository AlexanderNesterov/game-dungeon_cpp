//
// Created by alexander on 20.09.2019.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H


#include "Player.h"
#include "util/ArrayList/ArrayList.h"
//#include "util/ArrayList/ArrayList.cpp"

class Game {
public:
    Game();
    ~Game();
    void startGame();
private:
    Player *firstPlayer;
    Player *secondPlayer;
    ArrayList<Hero *> *heroes;
    int level;

    Player * randomStart();
    void showAvailableHeroes();
    void selectHero(Player *);
    Player * selectPlayer();
    Player * game(Player *, Player *);
};


#endif //UNTITLED_GAME_H
