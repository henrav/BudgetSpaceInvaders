//
// Created by Henrik Ravnborg on 2023-11-24.
//

#ifndef UNTITLED3_ENEMIES_H
#define UNTITLED3_ENEMIES_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Enemies.h"
#include "../Vapen/Weapon.h"
#include "../Vapen/EnemyWeapons/EnemyVapen.h"

class Enemies  {

    float xpos{};
    float ypos{};
public:
    Enemies();

    sf::Vector2f getPosition();

    void takeDamage(float damage);

    void setPostion(sf::RenderWindow &window);

    float getSpeed() const;

    void setSpeed(int speed);

    virtual void moveDown();

    virtual void enemiesMove();

    sf::Rect<float> getGlobalBounds();

    int getHealth();

    virtual int generateRandomSpeed();

    int getXP();

    virtual void draw(sf::RenderWindow &window);

    virtual void loadTexture();

    virtual void generateRandomPosition(sf::RenderWindow &window);
    static double generatexp(int playerLevel);
    virtual void shoot( sf::Vector2f playerPosition);
    Weapon getWeapon();
    virtual float getDamage();


protected:
    sf::RectangleShape enemy;
    int speed = 1;
    float health = 100;
    int xp = 0;
    float damage = 10;
    sf::Sprite enemySprite;
    EnemyVapen weapon;
    sf::Clock clock;
    float baseFireRate = 2000;

    void generateRandomFireRate();
};


#endif //UNTITLED3_ENEMIES_H
