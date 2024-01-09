//
// Created by Henrik Ravnborg on 2023-11-30.
//

#ifndef UNTITLED3_ENEMYBULLETS_H
#define UNTITLED3_ENEMYBULLETS_H


#include "../Bullets.h"
static sf::Texture bulletTexture;
class EnemyBullets : public Bullets{
private:
    float size = 10;
    std::string bulletTexturePath = "/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Effecter_Kulor_Och_Sådant/EnemyBullets.png";

public:
    EnemyBullets(float x, float y, float playerX, float playerY);
    virtual sf::RectangleShape &getBullet() override;
    virtual void loadTexture()  override;
    virtual void draw(sf::RenderWindow &window) override;
    virtual void update() override;
    void calculateSpeed(float playerX, float playerY) override;




};


#endif //UNTITLED3_ENEMYBULLETS_H
