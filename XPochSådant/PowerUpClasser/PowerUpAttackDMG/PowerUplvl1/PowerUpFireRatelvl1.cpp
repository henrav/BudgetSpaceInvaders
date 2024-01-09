//
// Created by Henrik Ravnborg on 2023-11-23.
//

#include "PowerUpFireRatelvl1.h"
#include "iostream"
using namespace std;


void PowerUpFireRatelvl1::increasePlayerStats() {
    cout << "Fire rate increased by 10" << endl;
    Player::addExtraFireRate(attackRate);
}

PowerUpFireRatelvl1::PowerUpFireRatelvl1() {
    this->powerUpName = "Fire rate lvl 1";
    this->powerUpDescription = "Increases your fire rate by 10";
    this->powerUpValue = "10";
    this->afterSelectedText = "Fire rate increased by 10";
    this->rarity = 1;
    this->attackDamage = 0;
    this->attackRate = 10;
    this->health = 0;
    this->speed = 0;
    this->bulletSpeed = 0;

}

int PowerUpFireRatelvl1::getRarity() {
    return rarity;
}

std::string PowerUpFireRatelvl1::getPowerUpName() {
    return powerUpName;
}

std::string PowerUpFireRatelvl1::getPowerUpDescription() {
    return powerUpDescription;
}

std::string PowerUpFireRatelvl1::getPowerUpValue() {
    return powerUpValue;
}

std::string PowerUpFireRatelvl1::getAfterSelectedText() {
    return afterSelectedText;
}

int PowerUpFireRatelvl1::getAttackRate() {
    return attackRate;
}
