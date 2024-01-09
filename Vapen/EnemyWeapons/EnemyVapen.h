//
// Created by Henrik Ravnborg on 2023-12-05.
//

#ifndef UNTITLED3_ENEMYVAPEN_H
#define UNTITLED3_ENEMYVAPEN_H


#include "../Vapen.h"
#include "../EnemyBullets/NyEnemyBullets.h"
static std::vector<NyEnemyBullets*> enemyBullets;

class EnemyVapen : public Vapen{
private:
    sf::Clock playerClock;

public:

    EnemyVapen();
    void shoot(float x, float y, float playerX, float playerY, float dmg);
    void clearBullets() override;
    static std::vector<NyEnemyBullets *> getEnemyBullets();
    static void drawBullets(sf::RenderWindow &window);
    static void updateBullets();
    static void removeBulletAtIterator(int place);

    static NyEnemyBullets getSingleBullet(int place);
};


#endif //UNTITLED3_ENEMYVAPEN_H
