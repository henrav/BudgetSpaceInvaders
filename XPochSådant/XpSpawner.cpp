//
// Created by Henrik Ravnborg on 2023-11-21.
//

#include <iostream>
#include "XpSpawner.h"
using namespace std;

static std::vector<XP> XPList;

void XpSpawner::spawnXP(float xpos, float ypos, sf::RenderWindow &window, float experience) {
    XP xp(window, experience, xpos, ypos);
    XPList.emplace_back(xp);
}

std::vector<XP> XpSpawner::getXPList() {
    return XPList;
}

void XpSpawner::drawXP(sf::RenderWindow &window) {
    for (auto &XP: XPList){
        XP.draw(window);
    }
}

void XpSpawner::moveXP(Player &player){
    for (auto it = XPList.begin(); it != XPList.end(); ){
        it->moveToPlayer(player);
        if (checkClosenessToPlayer(player, *it)){
            it = XPList.erase(it);
        } else {
            ++it;
        }
    }
}

bool XpSpawner::checkClosenessToPlayer(Player &player, XP &xp) {
    float x = player.getShapePos().getPosition().x - xp.getRectangleShape().getPosition().x;
    float y = player.getShapePos().getPosition().y - xp.getRectangleShape().getPosition().y;
    float distance = sqrt(pow(x, 2) + pow(y, 2));
    if (distance <= 50){
        player.increaseXP(xp.getXP(player.getLevel()));
        return true;
    }
    return false;
}

void XpSpawner::clearXPList() {
    XPList.clear();
}
