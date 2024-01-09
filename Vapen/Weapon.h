//
// Created by Henrik Ravnborg on 2023-11-15.
//

#ifndef HELLOSFML_WEAPON_H
#define HELLOSFML_WEAPON_H

#include <chrono>
#include <ctime>
#include <cmath>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>

#include "Bullets.h"
#include "PlayerBullets/PlayerBullets.h"




static std::vector<Bullets> bullets;

class Weapon {
public :


    virtual void shoot(float x, float y, float playerBulletSpeed);
    virtual void EnemyShoot(float enemyX, float enemyY, float playerX, float playerY);
    //static void drawBullets(sf::RenderWindow &window);
    bool checkAmmo();
    void setAmmo(float ammo);
    float getAmmo();
    void setFireRate(float fireRate);
    int getFireRate() const;
    void setDmg(float dmg);
    float getDmg();
    void setSpeed(float speed);
    float getSpeed();
    virtual void clearBullets();
    void resetAmmo();
    virtual std::vector<Bullets> &getBullets();


    void removeBullets(int i);

private:
    float size = 5;
    float maxAmmo = 100000;
    float ammo = 100000;;

protected:
    int baseFireRate = 900;
    float dmg = 50;
    float speed = 20;
    int32_t fireRate = 20;
    sf::Clock clock;
};


#endif //HELLOSFML_WEAPON_H
