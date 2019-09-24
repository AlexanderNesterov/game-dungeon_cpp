//
// Created by alexander on 20.09.2019.
//

#include "Game.h"
#include "../characters/dwarfwarrior/DwarfWarrior.h"
#include "../characters/elfscout/ElfScout.h"
#include "../characters/magicman/MagicMan.h"
#include "../util/ReaderWrapper/ReaderWrapper.h"
#include "../players/realplayer/RealPlayer.h"
#include "../players/botplayer/BotPlayer.h"
#include <iostream>
#include <ctime>
#include "thread"
#include "chrono"
#include "../util/ArrayList/ArrayList.cpp"

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

    cout << endl << "ПОБЕДИТЕЛЬ - " << winner->getName() << endl;
}

Player *Game::selectPlayer() {
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

        if (choice < 1 || choice > heroes->getSize()) {
            cout << "НЕВЕРНОЕ ЧИСЛО" << endl;
            continue;
        }

        if (heroes->get(choice - 1) != nullptr) {
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

Player *Game::game(Player *firstPlayer, Player *secondPlayer) {
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

        if (firstPlayer->isItBot() && secondPlayer->isItBot()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(800));
        }
    }

    return (firstPlayer->getLevel() >= level) ? firstPlayer : secondPlayer;
}

Player *Game::randomStart() {
    srand(time(0));
    int num = 1 + rand() % 2;

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
            cout << i + 1 << ". " << heroes->get(i)->getName() << endl;
        }
    }
}