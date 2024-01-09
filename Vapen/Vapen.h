//
// Created by Henrik Ravnborg on 2023-12-05.
//

#ifndef UNTITLED3_VAPEN_H
#define UNTITLED3_VAPEN_H


#include <cstdint>
#include <SFML/System/Clock.hpp>
#include <vector>
#include "Bullets.h"

class Vapen {
protected:
    int baseFireRate;
    int baseDamage;
    int baseSpeed;
    int32_t fireRate;
    sf::Clock clock;
public:

    int getFireRate() const;
    float getDmg();
    virtual void clearBullets();
    virtual std::vector<Bullets> &getBullets();
    int getPlayerFireRate() const;


    int getEnemyFireRate();
};


#endif //UNTITLED3_VAPEN_H
