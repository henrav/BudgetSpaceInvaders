//
// Created by Henrik Ravnborg on 2023-11-16.
//

#include <iostream>
using namespace std;
#include "EnemySpawner.h"
#include "Fiender/EnemiesLVL1.h"
#include "Fiender/EnemiesLVL2.h"
#include "Fiender/EnemiesLVL3.h"

void EnemySpawner::spawnEnemies(Game &game) {
    std::vector<std::vector<EnemyInfo>> roundEnemies = {
            {{1, 1}, {2, 5}},  // Round 1: 10 enemies of type 1, 1 enemy of type 2 = 11 enemies total
            {{1, 8}, {2, 3}}, // Round 2: 8 enemies of type 1, 3 enemies of type 2 = 11 enemies total
            {{1, 6}, {2, 5}}, // Round 3: 6 enemies of type 1, 5 enemies of type 2 = 11 enemies total
            {{1, 4},{2, 7}}, // Round 4: 4 enemies of type 1, 7 enemies of type 2 = 11 enemies total
            {{1, 2},{2, 9}}, // Round 5: 2 enemies of type 1, 9 enemies of type 2 = 11 enemies total
            {{1, 5},{2,8}},  // Round 6: 5 enemiesof type 1, 8 enemies of typ 2 = 13 enemies total
            {{1, 4},{2,10}},   // Round 7: 4 enemies of type 1, 10 enemies of type 2 = 14 enemies total
            {{1, 3}, {2, 12}}, // Round 8: 3 enemies of type 1, 12 enemeis of type 2 = 15 enemies total
            {{1, 3}, {2, 7}, {3, 5}},  // Round 9: 3 enemies of type 1, 7 enemies of type 2, 5 enemies of type 3 = 15 enemies total
            {{1, 5}, {2, 5}, {3, 5}}, // Round 10: 5 enemies of type 1, 5 enemies of type 2, 5 enemies of type 3 = 15 enemies total
            {{1, 6}, {2, 6}, {3, 5}}, // Round 11: 6 enemies of type 1, 6 enemies of type 2, 5 enemies of type 3 = 17 enemies total
            {{1, 7}, {2, 7}, {3, 6}}, // Round 12: 7 enemies of type 1, 7 enemies of type 2, 6 enemies of type 3 = 20 enemies total
            {{1, 8}, {2, 8}, {3, 7}}, // Round 13: 8 enemies of type 1, 8 enemies of type 2, 7 enemies of type 3 = 23 enemies total
            {{1, 9}, {2, 9}, {3, 8}}, // Round 14: 9 enemies of type 1, 9 enemies of type 2, 8 enemies of type 3 = 26 enemies total
            {{1, 10}, {2, 10}, {3, 9}}, // Round 15: 10 enemies of type 1, 10 enemies of type 2, 9 enemies of type 3 = 29 enemies total
            {{1, 11}, {2, 11}, {3, 10}}, // Round 16: 11 enemies of type 1, 11 enemies of type 2, 10 enemies of type 3 = 32 enemies total
            {{1, 12}, {2, 12}, {3, 11}}, // Round 17: 12 enemies of type




            // Round 6: 5 enemies of type 1, 8 enemies of type 2 = 13 enemies total


            // Round 2: 5 enemies of type 1, 2 enemies of type 2
            // Add more rounds as needed
    };

    int roundNr = game.getRoundNr();
    if (roundNr > 0 && roundNr <= roundEnemies.size()) {
        for (const auto& enemyInfo : roundEnemies[roundNr - 1]) {
            for (int i = 0; i < enemyInfo.count; i++) {
                if (enemyInfo.type == 1) {
                    enemies.push_back(new EnemiesLVL1(game.getWindow()));
                } else if (enemyInfo.type == 2) {
                    enemies.push_back(new EnemiesLVL2(game.getWindow()));
                }
                else if (enemyInfo.type == 3) {
                    enemies.push_back(new EnemiesLVL3(game.getWindow()));
                }

                // Add more enemy types as needed
            }
        }
    }
}


/*
void EnemySpawner::spawnEnemies(Game &game) {
    for (int i = 0; i < 100; i++) {
        auto *enemy = new EnemiesLVL1(game.getWindow());
        enemies.push_back(*enemy);
    }
}
 */










void EnemySpawner::drawEnemies(sf::RenderWindow &window) {
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->draw(window);
    }
}

bool EnemySpawner::updateEnemies(sf::RenderWindow &window, Game &game) {
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->shoot(game.getPlayer().getShapePos().getPosition());
        enemies[i]->enemiesMove();
        if (enemies[i]->getPosition().x > window.getSize().x) {
            enemies[i]->moveDown();
            enemies[i]->setSpeed(-enemies[i]->getSpeed());
        }
        if (enemies[i]->getPosition().x < 0) {
            enemies[i]->moveDown();
            enemies[i]->setSpeed(-enemies[i]->getSpeed());
        }
    }
}

std::vector<Enemies*> EnemySpawner::getEnemies() {
    return enemies;
}

void EnemySpawner::removeEnemies() {
    for (int i = 0; i < enemies.size(); i++) {
        enemies.erase(enemies.begin() + i);
    }
    enemies.clear();

}

void EnemySpawner::spawnEnemy2(sf::RenderWindow &window) {

}




