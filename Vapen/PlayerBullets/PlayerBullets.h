//
// Created by Henrik Ravnborg on 2023-11-30.
//

#ifndef UNTITLED3_PLAYERBULLETS_H
#define UNTITLED3_PLAYERBULLETS_H


#include "../Bullets.h"
static sf::Texture playerBulletTexture;
class PlayerBullets : public Bullets{
    private:
    float size = 10;
    float dmg;

    std::string bulletTexturePath = "/Users/henrikravnborg/CLionProjects/untitled3/Bilder/NormalPlayerShot.png";
public:
    PlayerBullets(float x, float y, float addPlayerSpeed, float weaponSpeed, float dmg);
    virtual sf::RectangleShape &getBullet() override;
    virtual void loadTexture()  override;
    virtual void draw(sf::RenderWindow &window) override;
    virtual void update() override;
    void calculateSpeed(float playerX, float playerY) override;
    float getDmg();

};


#endif //UNTITLED3_PLAYERBULLETS_H
