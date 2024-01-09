//
// Created by Henrik Ravnborg on 2023-11-28.
//

#include "PowerUpDMGlvl2.h"

PowerUpDMGlvl2::PowerUpDMGlvl2() {
    this->powerUpName = "Attack Damage lvl 2";
    this->powerUpDescription = "Increases your attack damage by 20";
    this->powerUpValue = "20";
    this->afterSelectedText = "Your attack damage has been increased by 20";
    this->rarity = 2;
    this->attackDamage = 20;
    this->attackRate = 0;
    this->health = 0;
    this->speed = 0;
    this->bulletSpeed = 0;

}

void PowerUpDMGlvl2::increasePlayerStats() {
    Player::addExtraDmg(attackDamage);
}

int PowerUpDMGlvl2::getRarity() {
    return rarity;
}

std::string PowerUpDMGlvl2::getPowerUpName() {
    return powerUpName;
}

std::string PowerUpDMGlvl2::getPowerUpDescription() {
    return powerUpDescription;
}

std::string PowerUpDMGlvl2::getPowerUpValue() {
    return powerUpValue;
}

std::string PowerUpDMGlvl2::getAfterSelectedText() {
    return afterSelectedText;
}

int PowerUpDMGlvl2::getAttackDamage() {
    return attackDamage;
}
