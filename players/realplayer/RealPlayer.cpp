//
// Created by alexander on 20.09.2019.
//

#include "RealPlayer.h"
#include "../../util/ReaderWrapper/ReaderWrapper.h"
#include <iostream>
using namespace std;

const static bool IS_BOT = false;

RealPlayer::RealPlayer() : Player(IS_BOT) {}

RealPlayer::~RealPlayer() {}

void RealPlayer::selectAction(Player *opponent) {
    int choice;
    std::string notEnoughEndurance = "НЕ ХВАТАЕТ ВЫНОСЛИВОСТИ!";

    cout << "Выберете действие: \n1:Отдых\n2:Спуск"
            "\n3:Быстрый спуск\n4:Особое действие\n5:инфо" << endl;

    do {
        choice = ReaderWrapper::newInt();

        switch (choice) {
            case 1:
                cout << "Выбран: отдых" << endl;
                this->rest();
                return;
            case 2:
                cout << "Выбран: спуск" << endl;
                if (this->move(opponent)) {
                    return;
                } else {
                    cout << notEnoughEndurance << endl;
                    continue;
                }
            case 3:
                cout << "Выбран: быстрый спуск" << endl;
                if (this->fastMove(opponent)) {
                    return;
                } else {
                    cout << notEnoughEndurance << endl;
                    continue;
                }
            case 4:
                cout << "Выбран: особое действие" << endl;
                if (this->specialAction(opponent)) {
                    return;
                } else {
                    cout << notEnoughEndurance << endl;
                    continue;
                }
            case 5:
                this->showInfo();
                continue;

            default:
                cout << "НЕВЕРНОЕ ЧИСЛО!" << endl;
        }
    } while (true);
}