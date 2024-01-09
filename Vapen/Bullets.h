//
// Created by Henrik Ravnborg on 2023-11-25.
//

#ifndef UNTITLED3_BULLETS_H
#define UNTITLED3_BULLETS_H


#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>



class Bullets {


protected:
    sf::RectangleShape bullet;
    float speed = 1;
    sf::Sprite bulletSprite;
    float SizeY = 60;
    float SizeX = 20;
    sf::Vector2f speedVector;

public:
    Bullets(float x, float y, float addPlayerSpeed);
    Bullets(float x, float y, float playerX, float playerY);
    float getSize() const;
    float getSpeed() const;
    void setSpeed(float speed);
    void setSize(float sizex, float sizey);
    virtual sf::RectangleShape &getBullet();
    sf::Sprite &getBulletSprite();
    sf::Texture &getBulletTexture();
    Bullets &getBulletObject();
    virtual void loadTexture();
    void setBulletSprite(sf::Sprite &bulletSprite);
    virtual void draw(sf::RenderWindow &window);
    virtual void update();
    void explode();
    static float getdmg();
    virtual void calculateSpeed(float playerX, float playerY);
};


#endif //UNTITLED3_BULLETS_H
