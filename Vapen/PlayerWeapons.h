//
// Created by Henrik Ravnborg on 2023-11-30.
//

#ifndef UNTITLED3_PLAYERWEAPONS_H
#define UNTITLED3_PLAYERWEAPONS_H


#include "Weapon.h"

class PlayerWeapons : public Weapon{
private:
public:
    PlayerWeapons();
    void shoot(float x, float y, float playerBulletSpeed) override;
    void EnemyShoot(float enemyX, float enemyY, float playerX, float playerY) override ;
    int getFireRate() const;
    float getDmg();
    void clearBullets() override;
    static std::vector<PlayerBullets> &getPlayerBullets();
    void drawBullets(sf::RenderWindow &window);
    void updateBullets();


};



#endif //UNTITLED3_PLAYERWEAPONS_H
