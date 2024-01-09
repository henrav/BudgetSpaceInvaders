//
// Created by Henrik Ravnborg on 2023-11-21.
//

#include "XP.h"
static float speedAfterWin = 5;

float XP::getXP(int playerLevel) {
    return xpMängd;
}

void XP::setXP(int amount) {
    this->xpMängd = amount;
}

void XP::generatePseudoRandomXP(int playerLevel) {

}

XP::XP(sf::RenderWindow &window, float xp, float xpos, float ypos) {
    this->xpShape.setSize(sf::Vector2f(size, size));
    this->xpMängd = xp;
    this->xpShape.setPosition(xpos, ypos);
}

void XP::moveToPlayer(Player &player) {
    float x = player.getShapePos().getPosition().x - this->xpShape.getPosition().x;
    float y = player.getShapePos().getPosition().y - this->xpShape.getPosition().y;
    float distance = sqrt(pow(x, 2) + pow(y, 2));
    float speed = speedAfterWin;
    float dx = speed * x / distance;
    float dy = speed * y / distance;
    this->xpShape.move(dx, dy);
}

void XP::draw(sf::RenderWindow &window) {
    window.draw(xpShape);
}



sf::RectangleShape XP::getRectangleShape() {
    return xpShape;
}

void XP::setRealSpeed(float speed) {
    speedAfterWin = speed;
}


