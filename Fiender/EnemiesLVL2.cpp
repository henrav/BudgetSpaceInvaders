//
// Created by Henrik Ravnborg on 2023-11-24.
//

#include "EnemiesLVL2.h"
#include "iostream"
using namespace std;
EnemiesLVL2::EnemiesLVL2(sf::RenderWindow &window) {
    this->enemy.setSize(sf::Vector2f(size, size));
    this->speed = EnemiesLVL2::generateRandomSpeed();
    this->health = 300;
    this->weapon = EnemyVapen();
    EnemiesLVL2::loadTexture();
    EnemiesLVL2::generateRandomPosition(window);
    setPostion(window);
}

void EnemiesLVL2::draw(sf::RenderWindow &window) {
    window.draw(enemySprite);
}

void EnemiesLVL2::loadTexture() {
    if (!enemyTextureLVL2.loadFromFile("/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Fiender/FienderLevel2.png", enemy.getTextureRect())) {
        cout << "Error loading EnemyLevel2 texture" << endl;
    }
    enemySprite.setTexture(enemyTextureLVL2);
    float scaleX = size / enemySprite.getLocalBounds().width;
    float scaleY = size / enemySprite.getLocalBounds().height;
    enemySprite.setScale(scaleX, scaleY);
    enemySprite.setPosition(enemy.getPosition().x, enemy.getPosition().y);
}

int EnemiesLVL2::generateRandomSpeed() {
    speed = rand() % 6 + 2;
}

void EnemiesLVL2::shoot(sf::Vector2f playerPosition) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distributionDouble(5000, 15000);
    double randomChance = distributionDouble(generator);
    sf::Vector2f shotpos = getCenterPosForShot();
    if (randomChance < clock.getElapsedTime().asMilliseconds()) {
        weapon.shoot(shotpos.x, shotpos.y, playerPosition.x, playerPosition.y, damage);
        clock.restart();
    }
}

void EnemiesLVL2::moveDown() {
    enemy.move(0, 50);
    enemySprite.move(0, 50);
}

void EnemiesLVL2::enemiesMove() {
    enemy.move(speed, 0);
    enemySprite.move(speed, 0);
}

void EnemiesLVL2::generateRandomPosition(sf::RenderWindow &window) {
    float x = rand() % window.getSize().x;
    float y = (rand() % window.getSize().y / 2) ;
    enemy.setPosition(x, y);
    enemySprite.setPosition(x, y);
}
sf::Vector2f EnemiesLVL2::getCenterPosForShot() {
    float x = enemy.getPosition().x + (enemy.getLocalBounds().width);
    float y = enemy.getPosition().y + (enemy.getLocalBounds().height);
    return sf::Vector2f(x, y);
}
