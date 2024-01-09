//
// Created by Henrik Ravnborg on 2023-11-28.
//

#include "PowerUpBulletSpeedlvl1.h"

PowerUpBulletSpeedlvl1::PowerUpBulletSpeedlvl1() {
    this->powerUpName = "Bullet Speed lvl 2";
    this->powerUpDescription = "Increases the speed of your bullets";
    this->powerUpValue = "2";
    this->afterSelectedText = "Bullet Speed increased by 2";
    this->rarity = 1;
    this->attackDamage = 0;
    this->attackRate = 0;
    this->health = 0;
    this->speed = 0;
    this->bulletSpeed = 2;

}

void PowerUpBulletSpeedlvl1::increasePlayerStats() {
    Player::addExtraBulletSpeed(bulletSpeed);
}

int PowerUpBulletSpeedlvl1::getRarity() {
    return rarity;
}

std::string PowerUpBulletSpeedlvl1::getPowerUpName() {
    return powerUpName;
}

std::string PowerUpBulletSpeedlvl1::getPowerUpDescription() {
    return powerUpDescription;
}

std::string PowerUpBulletSpeedlvl1::getPowerUpValue() {
    return powerUpValue;
}

std::string PowerUpBulletSpeedlvl1::getAfterSelectedText() {
    return afterSelectedText;
}

float PowerUpBulletSpeedlvl1::getBulletSpeed() {
    return bulletSpeed;
}
