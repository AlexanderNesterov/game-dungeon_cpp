//
// Created by alexander on 19.09.2019.
//

#include "DwarfWarrior.h"

const static std::string NAME = "Dwarf-warrior";
const static int MAX_ENDURANCE = 50;
const static int FAST_MOVE_COST = 15;
const static int SPEC_ACTION_COST = 20;
const static std::string SPEC_ACTION_DESCRIPTION = "Перемещает персонажа на уровень ниже. "
                                            "До следующего хода никакой персонаж не может ни обогнать его, "
                                            "ни оказаться на одном этаже с ним.";

DwarfWarrior::DwarfWarrior() :
Hero(NAME, MAX_ENDURANCE, FAST_MOVE_COST, SPEC_ACTION_COST, SPEC_ACTION_DESCRIPTION) {}

DwarfWarrior::~DwarfWarrior() {}

bool DwarfWarrior::specialAction(Hero *anotherHero) {
    if (!checkEndurance(specActionCost))
        return false;

    int step = 1;

    level += + step;
    isSpecActionUsed = true;

    endurance = endurance - specActionCost + recovery;
    return true;
}
