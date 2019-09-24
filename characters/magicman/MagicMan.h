//
// Created by alexander on 20.09.2019.
//

#ifndef UNTITLED_MAGICMAN_H
#define UNTITLED_MAGICMAN_H


#include "../hero/Hero.h"

class MagicMan : public Hero {
public:
    MagicMan();
    ~MagicMan();
    bool specialAction(Hero *) override;
};


#endif //UNTITLED_MAGICMAN_H
