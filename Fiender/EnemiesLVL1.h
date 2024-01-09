//
// Created by Henrik Ravnborg on 2023-11-24.
//

#ifndef UNTITLED3_ENEMIESLVL1_H
#define UNTITLED3_ENEMIESLVL1_H


#include "Enemies.h"

static sf::Texture enemyTextureLVL1;
class EnemiesLVL1 : public Enemies {
private:
    float size = 40;
public:
    EnemiesLVL1(sf::RenderWindow &window);

    void draw(sf::RenderWindow &window) override;

    void loadTexture() override;

    int generateRandomSpeed() override;

    void shoot(sf::Vector2f playerPosition) override;

    void moveDown() override;

    void enemiesMove() override;

    void generateRandomPosition(sf::RenderWindow &window) override;


    sf::Vector2f getCenterPosForShot();
};


#endif //UNTITLED3_ENEMIESLVL1_H
