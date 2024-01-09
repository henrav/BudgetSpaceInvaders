//
// Created by Henrik Ravnborg on 2023-12-05.
//

#ifndef UNTITLED3_NYBULLETS_H
#define UNTITLED3_NYBULLETS_H


#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <random>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

class NyBullets {
protected:
    sf::RectangleShape bullet;
    float speed = 0;
    float SizeY = 60;
    float SizeX = 20;
    float damage = 10;
    sf::Sprite bulletSprite;
    sf::Vector2f speedVector;
    sf::Texture bulletTexture;
public:
    virtual float getSizeY() ;
    virtual float getSizeX() ;
    virtual float getSpeed() ;
    virtual float getDamage();
    virtual void setDamage(float damage);
    virtual void setSpeed(float speed);
    virtual void setSize(float sizex, float sizey);
    virtual sf::RectangleShape &getBullet();
    virtual sf::Sprite &getBulletSprite();
    virtual sf::Texture &getBulletTexture();
    virtual sf::Vector2f &getSpeedVector();
    virtual void loadTexture();
    virtual void draw(sf::RenderWindow &window);
    virtual void updateBullet();
    virtual void explodeAnimation();


};


#endif //UNTITLED3_NYBULLETS_H
