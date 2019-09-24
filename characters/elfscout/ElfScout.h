//
// Created by alexander on 20.09.2019.
//

#ifndef UNTITLED_ELFSCOUT_H
#define UNTITLED_ELFSCOUT_H


#include "../hero/Hero.h"

class ElfScout : public Hero {
public:
    ElfScout();
    ~ElfScout();
    bool specialAction(Hero *) override;
};


#endif //UNTITLED_ELFSCOUT_H
