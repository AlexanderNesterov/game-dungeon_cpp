//
// Created by alexander on 20.09.2019.
//

#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(bool isBot) {
    this->isBot = isBot;
}

Player::~Player() {
    delete hero;
}

void Player::rest() {
    hero->rest();
}

bool Player::move(Player *opponent) {
    return hero->move(opponent->hero);
}

bool Player::fastMove(Player *opponent) {
    return hero->fastMove(opponent->hero);
}

bool Player::specialAction(Player *opponent) {
    return hero->specialAction(opponent->hero);
}

void Player::setHero(Hero *newHero) {
    this->hero = newHero;
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

void Player::showIndicators() {
    hero->showIndicators();
}

bool Player::isItBot() {
    return isBot;
}

void Player::showInfo() {
    cout << "Отдых: Восстанавливает дополнительно 3 ед. энергии Всего получаем 5 единиц." << endl;
    cout << "Спуск: Перемещает персонажа на этаж ниже. Стоимость: " << hero->getMoveCost() << endl;
    cout << "Быстрый спуск: Перемещает персонажа на 2 этажа ниже. Стоимость: " << hero->getFastMoveCost() << endl;
    cout << "Особое действие: " << hero->getSpecActionDescription() <<
    " Стоимость: " << hero->getSpecActionCost() << endl;
}