//
// Created by Henrik Ravnborg on 2023-12-05.
//

#ifndef UNTITLED3_NYPLAYERBULLETS_H
#define UNTITLED3_NYPLAYERBULLETS_H


#include "../NyBullets.h"

static sf::Texture xdplayerBulletTexture;
class NyPlayerBullets : public NyBullets{

private:
    sf::RectangleShape bullet;
    float speed = 0;
    float SizeY = 60;
    float SizeX = 20;
    float damage;
    sf::Sprite bulletSprite;
    sf::Vector2f speedVector;
    sf::Texture bulletTexture;

public:
    NyPlayerBullets(float posx, float posy, float speed, float dmg);
    void setDamage(float damage) override;
    void setSpeed(float speed) override;
    void setSize(float sizex, float sizey) override;
    sf::RectangleShape &getBullet() override;
    sf::Sprite &getBulletSprite() override;
    sf::Texture &getBulletTexture() override;
    sf::Vector2f &getSpeedVector()  override;
    void loadTexture() override;
    void draw(sf::RenderWindow &window) override;
    void updateBullet() override;
    virtual float getSizeY()  override;
    virtual float getSizeX()  override;
    virtual float getSpeed()  override;
    virtual float getDamage()  override;
    void explodeAnimation();





};


#endif //UNTITLED3_NYPLAYERBULLETS_H
