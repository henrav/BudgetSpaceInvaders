//
// Created by Henrik Ravnborg on 2023-12-05.
//

#include "EnemyVapen.h"
EnemyVapen::EnemyVapen() {
    this->baseFireRate = 1000;
    this->baseDamage = 10;
    this->baseSpeed = 1;
    this->fireRate = 50;
}

void EnemyVapen::shoot(float x, float y, float playerX, float playerY, float dmg) {
    enemyBullets.push_back(new NyEnemyBullets(x, y, playerX, playerY, dmg));
}

void EnemyVapen::clearBullets() {
    enemyBullets.clear();
}

std::vector<NyEnemyBullets *> EnemyVapen::getEnemyBullets() {
    return enemyBullets;
}

void EnemyVapen::drawBullets(sf::RenderWindow &window) {
    for (int i = 0; i < enemyBullets.size(); i++) {
        enemyBullets[i]->draw(window);
    }
}

void EnemyVapen::updateBullets() {
    for (int i = 0; i < enemyBullets.size(); i++) {
        enemyBullets[i]-> updateBullet();
    }
}

void EnemyVapen::removeBulletAtIterator(int place) {
    enemyBullets.erase(enemyBullets.begin() + place);
}

NyEnemyBullets EnemyVapen::getSingleBullet(int place) {
    return *enemyBullets[place];
}
