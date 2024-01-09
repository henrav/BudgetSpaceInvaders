//
// Created by Henrik Ravnborg on 2023-11-21.
//

#ifndef UNTITLED3_XP_H
#define UNTITLED3_XP_H


#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Spelaren/Player.h"
#include "../Fiender/Enemies.h"

class XP {
private:
    float xpMängd;
    sf::RectangleShape xpShape;
    float size = 10;
public:
    XP(sf::RenderWindow &window, float xp, float xpos, float ypos);
    float getXP(int playerLevel);
    void setXP(int amunt);
    void generatePseudoRandomXP(int playerLevel);
    void moveToPlayer(Player &player);
    void draw(sf::RenderWindow &window);
    int generateXpBasedOnEnemy(Enemies &enemy);
    sf::RectangleShape getRectangleShape();
    static void setRealSpeed(float speed);
};


#endif //UNTITLED3_XP_H
