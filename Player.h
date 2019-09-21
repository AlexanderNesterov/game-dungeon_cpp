//
// Created by alexander on 20.09.2019.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H


#include "characters/Hero.h"

class Player {
public:
    virtual void selectAction(Player *) = 0;
    void setHero(Hero *);
    int getLevel();
    std::string getName();
    void setSpecActionUse(bool);
protected:
    Hero *hero;

    Player();
    ~Player();
    void rest();
    void fastMove(Player *);
    void specialAction(Player *);
    void move(Player *);
    void moveDescription();
};


#endif //UNTITLED_PLAYER_H
