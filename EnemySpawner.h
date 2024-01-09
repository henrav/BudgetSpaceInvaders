//
// Created by Henrik Ravnborg on 2023-11-16.
//

#ifndef HELLOSFML_ENEMYSPAWNER_H
#define HELLOSFML_ENEMYSPAWNER_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Fiender/Enemies.h"
#include "Game.h"
#include "Fiender/Enemies.h"


static std::vector<Enemies*> enemies;
static int enemyCountRound1 = 5;
static int enemyCountRound2 = 7;
static int enemyCountRound3 = 9;
static int enemyCountRound4 = 11;
static int enemyCountRound5 = 13;
static int enemyCountRound6 = 15;

class EnemySpawner {
private :
    struct EnemyInfo {
        int type;
        int count;
    };
    int enemyHealthRound1 = 100;
    int enemyHealthRound2 = 105;
    int enemyHealthRound3 = 110;
    int enemyHealthRound4 = 115;
    int enemyHealthRound5 = 120;
    int enemyHealthRound6 = 125;
    int enemySpeedRound1 = (rand() % 6) + 3;
    int enemySpeedRound2 = (rand() % 7) + 4;
    int enemySpeedRound3 = (rand() % 8) + 5;
    int enemySpeedRound4 = (rand() % 9) + 6;
    int enemySpeedRound5 = (rand() % 10) + 7;
    int enemySpeedRound6 = (rand() % 11) + 8;


public :
    static void spawnEnemies(Game &game);
    void spawnEnemiesRound1(sf::RenderWindow &window);
    void spawnEnemy1(sf::RenderWindow &window);
    void spawnEnemy2(sf::RenderWindow &window);
    void spawnEnemy3(sf::RenderWindow &window);
    void spawnEnemy4(sf::RenderWindow &window);
    void spawnEnemy5(sf::RenderWindow &window);
    void spawnEnemy6(sf::RenderWindow &window);
    void spawnEnemy7(sf::RenderWindow &window);
    static std::vector<Enemies*> getEnemies();
    static void drawEnemies(sf::RenderWindow &window);
    static bool updateEnemies(sf::RenderWindow &window);
    static void removeEnemies();


    static bool updateEnemies(sf::RenderWindow &window, Game &game);
};


#endif //HELLOSFML_ENEMYSPAWNER_H
