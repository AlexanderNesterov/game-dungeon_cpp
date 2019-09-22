//
// Created by alexander on 20.09.2019.
//

#include "Game.h"
#include "characters/DwarfWarrior.h"
#include "characters/ElfScout.h"
#include "characters/MagicMan.h"
#include "util/ReaderWrapper/ReaderWrapper.h"
#include "RealPlayer.h"
#include "BotPlayer.h"
#include <iostream>
#include <ctime>
#include "util/ArrayList/ArrayList.cpp"

using namespace std;

Game::Game() {
    level = 20;
}

Game::~Game() {
    delete firstPlayer;
    delete secondPlayer;
    delete heroes;
}

void Game::startGame() {
    heroes = new ArrayList<Hero *>(3);

    heroes->add(new DwarfWarrior());
    heroes->add(new ElfScout());
    heroes->add(new MagicMan());

    firstPlayer = selectPlayer();
    secondPlayer = selectPlayer();

    cout << "Выберете героя для первого игрока" << endl;
    selectHero(firstPlayer);

    cout << "Выберете героя для второго игрока" << endl;
    selectHero(secondPlayer);

    Player *winner;

    if (!firstPlayer->isItBot() && !secondPlayer->isItBot()) {
        winner = randomStart();
    } else {
        winner = game(firstPlayer, secondPlayer);
    }

    cout << "ПОБЕДИТЕЛЬ - " << winner->getName() << endl;
}

Player* Game::selectPlayer() {
    int choice;

    cout << "Выберете тип игрока\n1: Бот\n2: Игрок" << endl;

    while (true) {
        choice = ReaderWrapper::newInt();

        switch (choice) {
            case 1:
                return new BotPlayer();
            case 2:
                return new RealPlayer();

            default:
                cout << "НЕВЕРНОЕ ЧИСЛО!" << endl;
        }
    }
}

void Game::selectHero(Player *player) {
    int choice;

    while (true) {
        showAvailableHeroes();

        choice = ReaderWrapper::newInt();

        if (choice < 0 || choice >= heroes->getSize()) {
            cout << "НЕВЕРНОЕ ЧИСЛО" << endl;
            continue;
        }

        cout << heroes->get(choice) << endl;

        if (heroes->get(choice) != nullptr) {
            switch (choice) {
                case 1:
                    player->setHero(heroes->get(0));
                    heroes->set(0, nullptr);
                    return;
                case 2:
                    player->setHero(heroes->get(1));
                    heroes->set(1, nullptr);
                    return;
                case 3:
                    player->setHero(heroes->get(2));
                    heroes->set(2, nullptr);
                    return;
            }
        }

        cout << "ГЕРОЙ ЗАНЯТ!" << endl;
    }
}

Player* Game::game(Player *firstPlayer, Player *secondPlayer) {
    int turn = 1;
    cout << "\n\n\nИГРА НАЧАЛАСЬ" << endl;

    while (firstPlayer->getLevel() < level && secondPlayer->getLevel() < level) {

        cout << "\n\nХОД " << turn << ":\n" << endl;
        firstPlayer->showIndicators();
        secondPlayer->showIndicators();

        cout << "\nХОД " << firstPlayer->getName() << ":" << endl;
        firstPlayer->selectAction(secondPlayer);

        if (firstPlayer->getLevel() >= level)
            break;

        cout << "\nХОД " << secondPlayer->getName() << endl;
        secondPlayer->selectAction(firstPlayer);

        firstPlayer->setSpecActionUse(false);
        secondPlayer->setSpecActionUse(false);

        turn++;
    }

    return (firstPlayer->getLevel() >= level) ? firstPlayer : secondPlayer;
}

Player* Game::randomStart() {
    srand(time(0));
    int num = 1 + rand() % 2;

    cout << num << endl;

    if (num % 2 == 0) {
        return game(firstPlayer, secondPlayer);
    } else {
        return game(secondPlayer, firstPlayer);
    }
}

void Game::showAvailableHeroes() {
    cout << "Доступные герои: " << endl;
    for (int i = 0; i < heroes->getSize(); ++i) {
        if (heroes->get(i) != nullptr) {
            cout << i+1 << ". " << heroes->get(i)->getName() << endl;
        }
    }
}