//
// Created by alexander on 18.09.2019.
//

#include "Hero.h"
#include "DwarfWarrior.h"
#include <iostream>
using namespace std;

Hero::Hero(std::string name, int maxEndurance, int fastMoveCost,
        int specActionCost, std::string specActionDescription) {
    this->name = name;
    this->maxEndurance = maxEndurance;
    this->fastMoveCost = fastMoveCost;
    this->specActionCost = specActionCost;
    this->specActionDescription = specActionDescription;
    this->endurance = maxEndurance;
}

Hero::~Hero() {

}

void Hero::rest() {
    endurance += 5;

    if (endurance > maxEndurance) {
        endurance = maxEndurance;
    }
}

bool Hero::move(Hero *anotherHero) {
    if (!checkEndurance(moveCost)) {
        return false;
    }

    int step = 1;

    if (isDwarfUsedSpecAction(anotherHero)) {
        int levelDifference = anotherHero->level - level;
        doStep(levelDifference, step, anotherHero->level);
    } else {
        level += step;
    }
}

bool Hero::fastMove(Hero *anotherHero) {
    if (!checkEndurance(fastMoveCost)) {
        return false;
    }

    int step = 2;

    if (isDwarfUsedSpecAction(anotherHero)) {
        int levelDifference = anotherHero->level - level;
        doStep(levelDifference, step, anotherHero->level);
    } else {
        level += step;
    }
}

bool Hero::checkEndurance(int enduranceCost) {
    if (endurance - enduranceCost >= 0) {
        return true;
    } else {
        cout << "НЕ ХВАТАЕТ ВЫНОСЛИВОСТИ" << endl;
        return false;
    }

}

void Hero::doStep(int levelDifference, int step, int anotherHeroLevel) {
    if (levelDifference == 0)
        return;

    if (levelDifference < 0) {
        level += step;
        return;
    }

    if (levelDifference > 0) {
        if (step - levelDifference == 0 || step - levelDifference > 0)
            level = anotherHeroLevel - 1;
        else
            level = level + step;

        return;
    }
}

//DO CHECK DWARF WARRIOR
bool Hero::isDwarfUsedSpecAction(Hero *anotherHero) {
    DwarfWarrior *dw = dynamic_cast<DwarfWarrior*> (anotherHero);
    if (dw == nullptr) {
        cout << "false" << endl;
        return false;
    }

    cout << "true" << endl;
    return anotherHero->isSpecActionUsed;
}

std::string Hero::getName() {
    return name;
}

int Hero::getLevel() {
    return level;
}

void Hero::setSpecActionUse(bool t) {
    isSpecActionUsed = t;
}

void Hero::allFields() {
    cout << "name: " << name << endl
            << "level: " << level << endl
            << "endurance: " << endurance << endl
            << "maxEndurance: " << maxEndurance << endl
            << "isSpecActionUsed: " << isSpecActionUsed << endl
            << "recovery: " << recovery << endl
            << "moveCost: " << moveCost << endl
            << "fastMoveCost: " << fastMoveCost << endl
            << "specActionCost: " << specActionCost << endl
            << "specActionDescription: " << specActionDescription << endl;


}