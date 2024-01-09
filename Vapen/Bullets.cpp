//
// Created by Henrik Ravnborg on 2023-11-25.
//

#include "Bullets.h"
#include <random>
#include "iostream"
using namespace std;



void Bullets::draw(sf::RenderWindow &window) {
    bulletSprite.setPosition(bullet.getPosition().x, bullet.getPosition().y);
    window.draw(bulletSprite);
}
void Bullets::update() {
    bullet.move(speedVector.x, speedVector.y);
}
float Bullets::getSpeed() const {
    return speed;
}
void Bullets::setSpeed(float speed) {
    this->speed = speed;
}
void Bullets::setSize(float sizex, float sizey) {
    SizeX = sizex;
    SizeY = sizey;
}
sf::RectangleShape &Bullets::getBullet() {
    return bullet;
}
sf::Sprite &Bullets::getBulletSprite() {
    return bulletSprite;
}
sf::Texture &Bullets::getBulletTexture() {

}
Bullets &Bullets::getBulletObject() {
    return *this;
}
void Bullets::loadTexture() {

}
float Bullets::getdmg() {
    return 0;
}


Bullets::Bullets(float x, float y, float addPlayerSpeed) {
    this->speedVector = sf::Vector2f(0, -speed - addPlayerSpeed);
    this->bullet.setSize(sf::Vector2f(SizeX, SizeY));
    bullet.setPosition(x, y);
    Bullets::loadTexture();

}

void Bullets::explode() {


}

Bullets::Bullets(float x, float y, float playerX, float playerY) {
    calculateSpeed(playerX, playerY);
    bullet.setPosition(x, y);
    calculateSpeed(playerX, playerY);
    Bullets::loadTexture();

}
void Bullets::calculateSpeed(float playerX, float playerY) {
    //move to player vectors
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distributionDouble(-150, 150);
    double randomChance = distributionDouble(generator);
    float x = playerX - bullet.getPosition().x;
    float y = playerY - bullet.getPosition().y;
    x += randomChance;
    float length = sqrt(x * x + y * y);
    speedVector = sf::Vector2f((x / length) * 3 , (y / length) * 3);


}
