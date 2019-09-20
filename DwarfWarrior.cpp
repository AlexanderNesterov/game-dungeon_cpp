//
// Created by alexander on 19.09.2019.
//

#include "DwarfWarrior.h"


DwarfWarrior::DwarfWarrior(std::string name, int maxEndurance, int fastMoveCost,
        int specActionCost, std::string specActionDescription) :
        Hero(name, maxEndurance, fastMoveCost, specActionCost, specActionDescription) {}

DwarfWarrior::~DwarfWarrior() {}

bool DwarfWarrior::specialAction(Hero *anotherHero) {
    if (!checkEndurance(specActionCost))
        return false;

    int step = 1;

    level += level + step;
    isSpecActionUsed = true;

    endurance = endurance - specActionCost + recovery;
    return true;
}