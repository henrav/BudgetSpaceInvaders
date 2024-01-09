//
// Created by Henrik Ravnborg on 2023-11-27.
//

#include "PowerUpDMGlvl1.h"


void PowerUpDMGlvl1::increasePlayerStats() {
    Player::addExtraDmg(attackDamage);
}

int PowerUpDMGlvl1::getRarity() {
    return rarity;
}

std::string PowerUpDMGlvl1::getPowerUpName() {
    return powerUpName;
}

std::string PowerUpDMGlvl1::getPowerUpDescription() {
    return powerUpDescription;
}

std::string PowerUpDMGlvl1::getPowerUpValue() {
    return powerUpValue;
}

std::string PowerUpDMGlvl1::getAfterSelectedText() {
    return afterSelectedText;
}

int PowerUpDMGlvl1::getAttackDamage() {
    return attackDamage;
}

PowerUpDMGlvl1::PowerUpDMGlvl1() {
    this->powerUpName = "Damage lvl 1";
    this->powerUpDescription = "Increases your damage by 10";
    this->powerUpValue = "10";
    this->afterSelectedText = "Damage increased by 10";
    this->rarity = 1;
    this->attackDamage = 10;
    this->attackRate = 0;
    this->health = 0;
    this->speed = 0;
    this->bulletSpeed = 0;
}


