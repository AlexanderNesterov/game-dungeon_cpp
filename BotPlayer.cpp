//
// Created by alexander on 20.09.2019.
//

#include "BotPlayer.h"
#include <iostream>
using namespace std;

BotPlayer::BotPlayer() {}

BotPlayer::~BotPlayer() {}

void BotPlayer::selectAction(Player *opponent) {
    int choice;

    do {
        choice = 1 + rand() % 4;

        switch (choice) {
            case 1:
                cout << "Выбран: отдых" << endl;
                this->rest();
                return;
            case 2:
                cout << "Выбран: спуск" << endl;
                this->move(opponent);
                return;
            case 3:
                cout << "Выбран: быстрый спуск" << endl;
                this->fastMove(opponent);
                return;
            case 4:
                cout << "Выбран: особое действие" << endl;
                this->specialAction(opponent);
                return;
            case 5:
                this->moveDescription();
                return;

            default:
                cout << "НЕВЕРНОЕ ЧИСЛО!" << endl;
        }
    } while (true);
}