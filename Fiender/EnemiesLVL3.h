//
// Created by Henrik Ravnborg on 2023-11-29.
//

#ifndef UNTITLED3_ENEMIESLVL3_H
#define UNTITLED3_ENEMIESLVL3_H


#include <SFML/Graphics/Texture.hpp>
#include "Enemies.h"

static sf::Texture enemyTextureLVL3;
class EnemiesLVL3 : public Enemies{
private:
    float size = 50;
    sf::Texture enemyTexture;
public:

        EnemiesLVL3(sf::RenderWindow &window);

        void draw(sf::RenderWindow &window) override;

        void loadTexture() override;

        int generateRandomSpeed() override;

        void shoot( sf::Vector2f playerPosition) override;

        void moveDown() override;

        void enemiesMove() override;

        void generateRandomPosition(sf::RenderWindow &window) override;

        sf::Vector2f getCenterPosForShot();

};


#endif //UNTITLED3_ENEMIESLVL3_H
