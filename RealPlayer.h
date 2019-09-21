//
// Created by alexander on 20.09.2019.
//

#ifndef UNTITLED_REALPLAYER_H
#define UNTITLED_REALPLAYER_H


#include "Player.h"

class RealPlayer : public Player {
public:
    RealPlayer();
    ~RealPlayer();
    void selectAction(Player *) override;
};


#endif //UNTITLED_REALPLAYER_H
