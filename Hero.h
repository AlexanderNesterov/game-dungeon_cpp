//
// Created by alexander on 18.09.2019.
//

#ifndef UNTITLED_HERO_H
#define UNTITLED_HERO_H

#include <string>

class Hero {
public:
    Hero();
    ~Hero();
    virtual bool specialAction(Hero);
    void rest();
    bool move(Hero);
    bool fastMove(Hero);
protected:
    bool checkEndurance(int);
    bool isDwarfUsedSpecAction(Hero);
    void doStep(int, int, int);
private:
    std::string name;
    int level;
    int endurance;
    int maxEndurance;
    bool isSpecActionUsed;
    int recovery;
    int moveCost;
    int fastMoveCost;
    int specActionCost;
    std::string specActionDescription;
};


#endif //UNTITLED_HERO_H
