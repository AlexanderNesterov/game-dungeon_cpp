//
// Created by alexander on 20.09.2019.
//

#ifndef UNTITLED_BOTPLAYER_H
#define UNTITLED_BOTPLAYER_H


#include "Player.h"

class BotPlayer : public Player {
public:
    BotPlayer();
    ~BotPlayer();
    void selectAction(Player *) override;
};


#endif //UNTITLED_BOTPLAYER_H
