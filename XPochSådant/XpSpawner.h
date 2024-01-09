//
// Created by Henrik Ravnborg on 2023-11-21.
//

#ifndef UNTITLED3_XPSPAWNER_H
#define UNTITLED3_XPSPAWNER_H


#include "../Fiender/Enemies.h"
#include "XP.h"


class XpSpawner {
public:
    static void spawnXP(float xpos, float ypos, sf::RenderWindow &window, float xp);
    static std::vector<XP> getXPList();
    static void drawXP(sf::RenderWindow &window);
    static void moveXP(Player &player);
    static bool checkClosenessToPlayer(Player &player, XP &xp);
    static void clearXPList();


};


#endif //UNTITLED3_XPSPAWNER_H
