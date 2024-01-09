//
// Created by Henrik Ravnborg on 2023-11-28.
//

#include "PowerUpFireRatelvl2.h"

PowerUpFireRatelvl2::PowerUpFireRatelvl2() {
    this->powerUpName = "Fire Rate lvl 2";
    this->powerUpDescription = "Increases your fire rate by 20";
    this->powerUpValue = "20";
    this->afterSelectedText = "Fire rate increased by 20";
    this->rarity = 1;
    this->attackDamage = 0;
    this->attackRate = 20;
    this->health = 0;
    this->speed = 0;
    this->bulletSpeed = 0;

}

void PowerUpFireRatelvl2::increasePlayerStats() {
    Player::addExtraFireRate(attackRate);
}

int PowerUpFireRatelvl2::getRarity() {
    return rarity;
}

std::string PowerUpFireRatelvl2::getPowerUpName() {
    return powerUpName;
}

std::string PowerUpFireRatelvl2::getPowerUpDescription() {
    return powerUpDescription;
}

std::string PowerUpFireRatelvl2::getPowerUpValue() {
    return powerUpValue;
}

std::string PowerUpFireRatelvl2::getAfterSelectedText() {
    return afterSelectedText;
}

int PowerUpFireRatelvl2::getAttackRate() {
    return attackRate;
}
