//
// Created by alexander on 20.09.2019.
//

#include "Game.h"
#include "characters/DwarfWarrior.h"
#include "characters/ElfScout.h"
#include "characters/MagicMan.h"

Game::Game() {
    level = 20;
}

Game::~Game() {}

void Game::startGame() {
    heroes = new ArrayList<Hero *>(3);

    heroes->add(new DwarfWarrior());
    heroes->add(new ElfScout());
    heroes->add(new MagicMan());
}