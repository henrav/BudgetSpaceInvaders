//
// Created by Henrik Ravnborg on 2023-11-22.
//

#include "PowerUp.h"
#include "PowerUpClasser/PowerUpAttackDMG/PowerUplvl1/PowerUpFireRatelvl1.h"

PowerUp::PowerUp() {

}

void PowerUp::increasePlayerHealth() {

}

void PowerUp::increasePlayerDMG() {
    Player::addExtraDmg(attackDamage);
}

void PowerUp::increasePlayerSpeed() {

}

void PowerUp::increasePlayerBulletSpeed() {
    Player::addExtraBulletSpeed(bulletSpeed);
}

std::string PowerUp::getPowerUpName() {
    return powerUpName;
}

std::string PowerUp::getPowerUpDescription() {
    return powerUpDescription;
}

std::string PowerUp::getPowerUpValue() {
    return powerUpValue;
}

int PowerUp::getRarity() {
    return rarity;
}

std::string PowerUp::getAfterSelectedText() {
    return afterSelectedText;
}

void PowerUp::increasePlayerAttackRate() {
    Player::addExtraFireRate(attackRate);
}

void PowerUp::increasePlayerStats() {

}
