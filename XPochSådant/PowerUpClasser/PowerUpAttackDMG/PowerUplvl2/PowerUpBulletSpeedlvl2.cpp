//
// Created by Henrik Ravnborg on 2023-11-28.
//

#include "PowerUpBulletSpeedlvl2.h"

PowerUpBulletSpeedlvl2::PowerUpBulletSpeedlvl2() {
    this->powerUpName = "Bullet Speed lvl 2";
    this->powerUpDescription = "Increases the speed of your bullets";
    this->powerUpValue = "4";
    this->afterSelectedText = "Bullet Speed increased by 4";
    this->rarity = 2;
    this->attackDamage = 0;
    this->attackRate = 0;
    this->health = 0;
    this->speed = 0;
    this->bulletSpeed = 4;

}

void PowerUpBulletSpeedlvl2::increasePlayerStats() {
    Player::addExtraBulletSpeed(bulletSpeed);
}

int PowerUpBulletSpeedlvl2::getRarity() {
    return rarity;
}

std::string PowerUpBulletSpeedlvl2::getPowerUpName() {
    return powerUpName;
}

std::string PowerUpBulletSpeedlvl2::getPowerUpDescription() {
    return powerUpDescription;
}

std::string PowerUpBulletSpeedlvl2::getPowerUpValue() {
    return powerUpValue;
}

std::string PowerUpBulletSpeedlvl2::getAfterSelectedText() {
    return afterSelectedText;
}

float PowerUpBulletSpeedlvl2::getBulletSpeed() {
    return bulletSpeed;
}
