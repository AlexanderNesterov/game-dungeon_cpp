//
// Created by alexander on 20.09.2019.
//

#include "ElfScout.h"

const static std::string NAME = "Elf-Scout";
const static int MAX_ENDURANCE = 40;
const static int FAST_MOVE_COST = 12;
const static int SPEC_ACTION_COST = 24;
const static std::string SPEC_ACTION_DESCRIPTION = "Спускается на 3 уровня ниже";

ElfScout::ElfScout() :
        Hero(NAME, MAX_ENDURANCE, FAST_MOVE_COST, SPEC_ACTION_COST, SPEC_ACTION_DESCRIPTION) {}

ElfScout::~ElfScout() {}

bool ElfScout::specialAction(Hero *anotherHero) {
    if (!checkEndurance(specActionCost))
        return false;

    int step = 3;

    if (isDwarfUsedSpecAction(anotherHero)) {
        int levelDifference = anotherHero->getLevel() - level;
        doStep(levelDifference, step, anotherHero->getLevel());
    } else {
        level += step;
    }

    endurance = endurance - specActionCost + recovery;
}