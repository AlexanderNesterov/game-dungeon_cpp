//
// Created by alexander on 20.09.2019.
//

#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() {}

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

void Player::setHero(Hero *hero) {
    this->hero = hero;
}

int Player::getLevel() {
    return hero->getLevel();
}

std::string Player::getName() {
    return hero->getName();
}

void Player::setSpecActionUse(bool t) {
    hero->setSpecActionUse(t);
}