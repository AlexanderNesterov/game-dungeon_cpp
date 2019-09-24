//
// Created by alexander on 20.09.2019.
//

#include "BotPlayer.h"
#include <iostream>
#include <ctime>
using namespace std;

const static bool IS_BOT = true;

BotPlayer::BotPlayer() : Player(IS_BOT) {}

BotPlayer::~BotPlayer() {}

void BotPlayer::selectAction(Player *opponent) {
    int choice;
    srand(time(0));

    do {
        choice = 1 + rand() % 4;

        switch (choice) {
            case 1:
                cout << "Выбран: отдых" << endl;
                this->rest();
                return;
            case 2:
                if (this->move(opponent)) {
                    cout << "Выбран: спуск" << endl;
                    return;
                } else {
                    continue;
                }
            case 3:
                if (this->fastMove(opponent)) {
                    cout << "Выбран: быстрый спуск" << endl;
                    return;
                } else {
                    continue;
                }
            case 4:
                if (this->specialAction(opponent)) {
                    cout << "Выбран: особое действие" << endl;
                    return;
                } else {
                    continue;
                }

            default:
                cout << "НЕВЕРНОЕ ЧИСЛО!" << endl;
        }
    } while (true);
}