//
// Created by alexander on 19.09.2019.
//

#ifndef UNTITLED_DWARFWARRIOR_H
#define UNTITLED_DWARFWARRIOR_H


#include "Hero.h"

class DwarfWarrior : public Hero {
public:
    DwarfWarrior(std::string, int, int, int, std::string);
    ~DwarfWarrior();
    bool specialAction(Hero *) override;
};


#endif //UNTITLED_DWARFWARRIOR_H
