//
// Created by alexander on 20.09.2019.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H


#include "Player.h"
#include "util/ArrayList/ArrayList.h"

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

    Player * selectHero();
    Player * game(Player *, Player *);
};


#endif //UNTITLED_GAME_H
