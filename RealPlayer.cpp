//
// Created by alexander on 20.09.2019.
//

#include "RealPlayer.h"
#include "util/ReaderWrapper/ReaderWrapper.h"
#include <iostream>
using namespace std;

RealPlayer::RealPlayer() {}

RealPlayer::~RealPlayer() {}

void RealPlayer::selectAction(Player *opponent) {
    int choice;
    cout << "Выберете действие: \n1:Отдых\n2:Спуск"
            "\n3:Быстрый спуск\n4:Особое действие\n5:инфо";

    do {
        choice = ReaderWrapper::newInt();

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