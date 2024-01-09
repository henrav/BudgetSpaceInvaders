//
// Created by Henrik Ravnborg on 2023-11-29.
//

#include "EnemiesLVL3.h"
#include "iostream"
using namespace std;

EnemiesLVL3::EnemiesLVL3(sf::RenderWindow &window) {
    this->enemy.setSize(sf::Vector2f(size, size));
    this->speed = EnemiesLVL3::generateRandomSpeed();
    this->health = 400;
    this->weapon = EnemyVapen();
    EnemiesLVL3::loadTexture();
    generateRandomPosition(window);
    setPostion(window);
}
void EnemiesLVL3::draw(sf::RenderWindow &window) {
    window.draw(enemy);
}

void EnemiesLVL3::loadTexture() {
    if (!enemyTextureLVL3.loadFromFile("/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Fiender/FienderLevel3.png", enemy.getTextureRect())) {
        cout << "Error loading EnemyLevel2 texture" << endl;
    }
    enemySprite.setTexture(enemyTextureLVL3);
    float scaleX = size / enemySprite.getLocalBounds().width;
    float scaleY = size / enemySprite.getLocalBounds().height;
    enemySprite.setScale(scaleX, scaleY);
    enemySprite.setPosition(enemy.getPosition().x, enemy.getPosition().y);
}

int EnemiesLVL3::generateRandomSpeed() {
    speed = rand() % 7 + 3;
}

void EnemiesLVL3::shoot(sf::Vector2f playerPosition) {
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

void EnemiesLVL3::moveDown() {
    enemy.move(0, 50);
    enemySprite.move(0, 50);
}

void EnemiesLVL3::enemiesMove() {
    enemy.move(speed, 0);
    enemySprite.move(speed, 0);
}


void EnemiesLVL3::generateRandomPosition(sf::RenderWindow &window) {
    float x = rand() % window.getSize().x;
    float y = (rand() % window.getSize().y / 2) ;
    enemy.setPosition(x, y);
}

sf::Vector2f EnemiesLVL3::getCenterPosForShot() {
    sf::Vector2f shotpos = sf::Vector2f(enemy.getPosition().x + (enemy.getSize().x / 2), enemy.getPosition().y + (enemy.getSize().y / 2));
    return shotpos;
}


