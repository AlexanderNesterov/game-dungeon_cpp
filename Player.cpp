//
// Created by alexander on 20.09.2019.
//

#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(Hero *hero) {
    this->hero = hero;
}

Player::~Player() {}

void Player::rest() {
    hero->rest();
}

void Player::move(Player *opponent) {
    hero->move(opponent->hero);
}

void Player::fastMove(Player *opponent) {
    hero->fastMove(opponent->hero);
}

void Player::specialAction(Player *opponent) {
    hero->specialAction(opponent->hero);
}

void Player::moveDescription() {
    cout << hero->specActionDescription;
}