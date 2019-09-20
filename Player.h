//
// Created by alexander on 20.09.2019.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H


#include "characters/Hero.h"

class Player {
public:
    virtual void selectAction(Player *) = 0;
protected:
    Hero *hero;

    Player(Hero *);
    ~Player();
    void rest();
    void fastMove(Player *);
    void specialAction(Player *);
    void move(Player *);
    void moveDescription();
};


#endif //UNTITLED_PLAYER_H
