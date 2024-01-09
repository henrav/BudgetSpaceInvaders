//
// Created by Henrik Ravnborg on 2023-11-30.
//

#include "ExplosionListy.h"

void ExplosionListy::addExplosion(float posX, float posY) {
    auto *bulletExplosion = new BulletExplosion(posX, posY);
    explosions.emplace_back(bulletExplosion);
}

void ExplosionListy::drawAndUpdate(sf::RenderWindow &window) {
    for (auto it = explosions.begin(); it != explosions.end(); ){
        (*it)->draw(window);
        if ((*it)->getClock().getElapsedTime().asMilliseconds() >= 200){
            it = explosions.erase(it);
        } else {
            ++it;
        }
    }

}
