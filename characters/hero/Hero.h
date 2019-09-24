//
// Created by alexander on 18.09.2019.
//

#ifndef UNTITLED_HERO_H
#define UNTITLED_HERO_H

#include <string>

class Hero {
public:
    void rest();
    bool move(Hero *);
    bool fastMove(Hero *);
    virtual bool specialAction(Hero *) = 0;
    ~Hero();

    std::string getName();
    int getLevel();
    void setLevel(int);
    void setSpecActionUse(bool);
    void showIndicators();
    int getMoveCost();
    int getFastMoveCost();
    int getSpecActionCost();
    std::string getSpecActionDescription();
protected:
    Hero(std::string, int, int, int, std::string);
    bool checkEndurance(int);
    bool isDwarfUsedSpecAction(Hero *);
    void doStep(int, int, int);

    std::string name;
    int level = 0;
    int endurance;
    int maxEndurance;
    bool isSpecActionUsed = false;
    int recovery = 2;
    int moveCost = 5;
    int fastMoveCost;
    int specActionCost;
    std::string specActionDescription;
};


#endif //UNTITLED_HERO_H
