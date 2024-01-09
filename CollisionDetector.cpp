//
// Created by Henrik Ravnborg on 2023-11-16.
//

#include "CollisionDetector.h"
#include "EnemySpawner.h"

using namespace std;

void CollisionDetector::collisionDetection(Game &game) {
    auto &PlayerBullets = PlayerVapen::getPlayerBullets();
    std::vector<Enemies *> enemies = EnemySpawner::getEnemies();

    for (auto bulletIter = PlayerBullets.begin(); bulletIter != PlayerBullets.end();) {
        bool bulletRemoved = false;

        for (int i = 0; i < enemies.size(); i++) {
            if (bulletIter->getBullet().getGlobalBounds().intersects(enemies[i]->getGlobalBounds())) {
                bulletIter->explodeAnimation();
                PlayerBullets.erase(bulletIter);
                enemies[i]->takeDamage(game.getPlayer().getWeapon().getDmg());
                if (enemies[i]->getHealth() <= 0){
                    float xpos = enemies[i]->getPosition().x;
                    float ypos = enemies[i]->getPosition().y;
                    XpSpawner::spawnXP(xpos, ypos, game.getWindow(), Enemies::generatexp(game.getPlayer().getLevel()));
                    enemies.erase(enemies.begin() + i);
                }

                bulletRemoved = true;
                break;  // Break out of the inner loop since bullet is already removed
            }
        }

        if (!bulletRemoved) {
            ++bulletIter;
        }
    }
}

void CollisionDetector::collisionDetectionEnemyBullets(Game &game) {
    for (int i = 0; i < EnemyVapen::getEnemyBullets().size(); i++) {
        if (EnemyVapen::getEnemyBullets()[i]->getBullet().getGlobalBounds().intersects(game.getPlayer().getShapePos().getGlobalBounds())) {
            game.getPlayer().takeDamage(EnemyVapen::getEnemyBullets()[i]->getDamage());
            EnemyVapen::getSingleBullet(i).explodeAnimation();
            EnemyVapen::removeBulletAtIterator(i);
        }
    }

}

