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
#include "util/ArrayList/ArrayList.cpp"

using namespace std;

Game::Game() {
    level = 20;
}

Game::~Game() {}

void Game::startGame() {
    heroes = new ArrayList<Hero *>(3);

    heroes->add(new DwarfWarrior());
    heroes->add(new ElfScout());
    heroes->add(new MagicMan());


    selectPlayer(firstPlayer);
    selectPlayer(secondPlayer);

    selectHero(firstPlayer);
    cout << "4" << endl;
    selectHero(secondPlayer);

    Player *winner = game(firstPlayer, secondPlayer);
    cout << "ПОБЕДИТЕЛЬ - " << winner->getName() << endl;
}

void Game::selectPlayer(Player *player) {
    int choice;

    cout << "Выберете тип игрока\n1: Бот\n2: Игрок" << endl;

    while (true) {
        choice = ReaderWrapper::newInt();

        switch (choice) {
            case 1:
                player = new RealPlayer();
                return;
            case 2:
                player = new BotPlayer();
                return;

            default:
                cout << "НЕВЕРНОЕ ЧИСЛО!" << endl;
        }
    }
}

void Game::selectHero(Player *player) {
    int choice;

    while (true) {
        showAvailableHeroes();

        //cout << "1" << endl;

        choice = ReaderWrapper::newInt();

        //cout << "2" << endl;

/*        if (choice <= 0 || choice > heroes->getSize()) {
            cout << "НЕВЕРНОЕ ЧИСЛО" << endl;
            continue;
        }*/

        //cout << "3" << endl;

        switch (choice) {
            case 1:
                player->setHero(heroes->get(0));
                heroes->set(0, nullptr);
                return;
            case 2:
                player->setHero(heroes->get(1));
                heroes->set(1, nullptr);
                //player->setHero(new ElfScout());
                return;
            case 3:
                player->setHero(heroes->get(2));
                heroes->set(2, nullptr);
                //player->setHero(new MagicMan());
                return;

            default:
                cout << "НЕВЕРНОЕ ЧИСЛО" << endl;
        }
    }
}

Player* Game::game(Player *, Player *) {
    int turn = 1;
    cout << "\n\n\nИГРА НАЧАЛАСЬ" << endl;

    while (firstPlayer->getLevel() < level && secondPlayer->getLevel() < level) {

        cout << "\n\nХОД " << turn << ":\n" << endl;
        cout << firstPlayer << "\n" << secondPlayer << endl;

        cout << "\nХОД " << firstPlayer->getName() << ":" << endl;

        if (firstPlayer->getLevel() >= level)
            break;

        cout << "\nХОД " << secondPlayer->getName() << endl;

        firstPlayer->setSpecActionUse(false);
        secondPlayer->setSpecActionUse(false);

        turn++;
    }

    cout << firstPlayer << "\n" << secondPlayer;

    return (firstPlayer->getLevel() >= level) ? firstPlayer : secondPlayer;
}

void Game::showAvailableHeroes() {
    cout << "Доступные герои: " << endl;
    for (int i = 0; i < heroes->getSize(); ++i) {
        if (heroes->get(i) != nullptr) {
            cout << i+1 << ". " << heroes->get(i)->getName() << endl;
        }
    }
}