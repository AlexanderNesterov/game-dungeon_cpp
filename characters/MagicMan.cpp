//
// Created by alexander on 20.09.2019.
//

#include "MagicMan.h"

const static std::string NAME = "Magic_man";
const static int MAX_ENDURANCE = 30;
const static int FAST_MOVE_COST = 13;
const static int SPEC_ACTION_COST = 15;
const static std::string SPEC_ACTION_DESCRIPTION = "Если на уровне ниже есть персонаж, "
                                                   "то меняется с ним местами иначе спускается на один уровень.";

MagicMan::MagicMan() :
        Hero(NAME, MAX_ENDURANCE, FAST_MOVE_COST, SPEC_ACTION_COST, SPEC_ACTION_DESCRIPTION) {}

MagicMan::~MagicMan() {}

bool MagicMan::specialAction(Hero *anotherHero) {

    if (!checkEndurance(specActionCost))
        return false;

    if (isDwarfUsedSpecAction(anotherHero)) {
        int tempLevel = level;
        level = anotherHero->level;
        anotherHero->level = tempLevel;
    }

    isSpecActionUsed = true;
    endurance = endurance - specActionCost + recovery;
    return true;
}