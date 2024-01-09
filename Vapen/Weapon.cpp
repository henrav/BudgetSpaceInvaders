//
// Created by Henrik Ravnborg on 2023-11-15.
//

#include <iostream>
#include "Weapon.h"
#include "../Spelaren/Player.h"
using namespace std;





/*
void Weapon::drawBullets(sf::RenderWindow &window) {
    for (auto &bullet : bullets) {
        bullet.draw(window);
    }
    for (auto &bullet : enemyBullets) {
        bullet.draw(window);
    }
}
 */

void Weapon::shoot(float x, float y, float playerBulletSpeed) {
    if (clock.getElapsedTime().asMilliseconds() > getFireRate()) {
        //cout << clock.getElapsedTime().asMilliseconds() << endl;
        bullets.emplace_back(x, y, playerBulletSpeed);
        clock.restart();
    }
}
bool Weapon::checkAmmo() {
    if (ammo > 0) {
        return true;
    } else {
        return false;
    }
}

void Weapon::setAmmo(float ammo) {
    this->ammo = ammo;

}

float Weapon::getAmmo() {
    return ammo;
}

void Weapon::setFireRate(float fireRate) {
    this->fireRate = fireRate;
}

int Weapon::getFireRate() const {
    int a = baseFireRate;
    int totalFireRate = fireRate + Player::getExtraFireRateStatic();
    // Use a logarithmic function to calculate the fire rate
    // The constant 10 is just an example, you can adjust it to get the curve you want
    int reduction = static_cast<int>((std::log(totalFireRate) + 1) * 110);
   // cout << "totalFireRate = " + to_string(totalFireRate) << endl;
    // Ensure that the fire rate never goes below 50 and above the maximum fire rate reduction
    return baseFireRate - reduction;
}


void Weapon::setDmg(float dmg) {
    this->dmg = dmg;

}

float Weapon::getDmg() {
    return dmg + Player::getExtraDmgStatic();
}

void Weapon::setSpeed(float speed) {
    this->speed = speed;

}

float Weapon::getSpeed() {
    return (speed + Player::getExtraBulletSpeedStatic()) * -1;
}


std::vector<Bullets> & Weapon::getBullets() {
    return bullets;
}

void Weapon::removeBullets(int i) {
    bullets.erase(bullets.begin() + i);
}

void Weapon::clearBullets() {
    bullets.clear();
}

void Weapon::resetAmmo() {
    ammo = maxAmmo;

}

void Weapon::EnemyShoot(float enemyX, float enemyY, float playerX, float playerY) {

}














