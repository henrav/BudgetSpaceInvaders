//
// Created by Henrik Ravnborg on 2023-11-15.
//

#include "Enemies.h"
#include "Enemies.h"
#include <iostream>
#include <random>


using namespace std;



sf::Vector2f Enemies::getPosition() {
    return {Enemies::enemy.getPosition().x, Enemies::enemy.getPosition().y};
}

void Enemies::takeDamage(float damage) {
    health -= damage;
}

void Enemies::setPostion(sf::RenderWindow &window) {


}

float Enemies::getSpeed() const {
    return speed;
}

void Enemies::setSpeed(int speed) {
    this->speed = speed;
}

void Enemies::moveDown() {
    enemy.move(0, 50);

}

void Enemies::enemiesMove() {

}

sf::Rect<float> Enemies::getGlobalBounds() {
    return enemy.getGlobalBounds();
}

int Enemies::getHealth() {
    return health;
}

int Enemies::generateRandomSpeed() {
    speed = rand() % 5 + 1;
}

int Enemies::getXP() {
    return xp;
}

void Enemies::draw(sf::RenderWindow &window) {

}

void Enemies::loadTexture() {

}

void Enemies::generateRandomPosition(sf::RenderWindow &window) {
    float x = rand() % window.getSize().x;
    float y = (rand() % window.getSize().y / 2) ;
    enemy.setPosition(x, y - 150);
}

double Enemies::generatexp(int playerLevel) {
    double lvl = playerLevel;
    return (0.1 * lvl) + 1;
}
float Enemies::getDamage() {
    return damage;
}

void Enemies::shoot( sf::Vector2f playerPosition) {
    cout << "Enemy main class shoot" << endl;

}



/*
 if (baseFireRate < clock.getElapsedTime().asMilliseconds()) {
        weapon.shoot(float(enemy.getPosition().x), float(enemy.getPosition().y), playerPosition.x,
                          playerPosition.y);
        clock.restart();
    }
 */
void Enemies::generateRandomFireRate() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distributionDouble(5000, 15000);
    double randomChance = distributionDouble(generator);
    this->baseFireRate = randomChance;

}

Enemies::Enemies() {


}











