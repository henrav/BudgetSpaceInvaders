//
// Created by Henrik Ravnborg on 2023-12-05.
//

#ifndef UNTITLED3_NYENEMYBULLETS_H
#define UNTITLED3_NYENEMYBULLETS_H


#include "../NyBullets.h"

static sf::Texture texture;
class NyEnemyBullets : public NyBullets {
public:
    NyEnemyBullets(float posx, float posy, float playerx , float playery, float dmg);
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
    void calculateSpeedandDirection(float playerx, float playery);
    float getDamage() override;
    void explodeAnimation() override;

};


#endif //UNTITLED3_NYENEMYBULLETS_H
