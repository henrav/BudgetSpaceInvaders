//
// Created by Henrik Ravnborg on 2023-11-30.
//

#ifndef UNTITLED3_ENEMYFACTORY_H
#define UNTITLED3_ENEMYFACTORY_H


#include "../Enemies.h"

class EnemyFactory {
public:
    virtual Enemies* createEnemy(sf::RenderWindow &window) = 0;

};


#endif //UNTITLED3_ENEMYFACTORY_H
