//
// Created by Henrik Ravnborg on 2023-11-30.
//

#ifndef UNTITLED3_EXPLOSIONLISTY_H
#define UNTITLED3_EXPLOSIONLISTY_H
#include "BulletExplosion.h"
#include <vector>


static std::vector<BulletExplosion*> explosions;
class ExplosionListy {
private:

public:
    static void addExplosion(float posX, float posY);
    static void drawAndUpdate(sf::RenderWindow &window);

};


#endif //UNTITLED3_EXPLOSIONLISTY_H
