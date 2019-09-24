//
// Created by alexander on 20.09.2019.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H


#include "../characters/hero/Hero.h"
#include "../characters/dwarfwarrior/DwarfWarrior.h"

class Player {
public:
    virtual void selectAction(Player *) = 0;
    void setHero(Hero *);
    int getLevel();
    std::string getName();
    void setSpecActionUse(bool);
    void showIndicators();
    bool isItBot();
    void showInfo();
    ~Player();
protected:
    Hero *hero;
    bool isBot;

    Player(bool);
    void rest();
    bool fastMove(Player *);
    bool specialAction(Player *);
    bool move(Player *);
};


#endif //UNTITLED_PLAYER_H
