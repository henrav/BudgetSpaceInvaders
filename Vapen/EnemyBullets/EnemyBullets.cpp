//
// Created by Henrik Ravnborg on 2023-11-30.
//

#include "EnemyBullets.h"
#include "iostream"
#include <random>
using namespace std;

sf::RectangleShape &EnemyBullets::getBullet() {
    return Bullets::getBullet();
}

void EnemyBullets::loadTexture() {
    if (!bulletTexture.loadFromFile(bulletTexturePath, bullet.getTextureRect())) {
        std::cout << "Error loading texture" << std::endl;
    }
    bulletSprite.setTexture(bulletTexture);

    // Get the original size of the sprite
    sf::FloatRect spriteSize = bulletSprite.getLocalBounds();

    // Calculate the scale factors
    float scaleX = SizeX / spriteSize.width;
    float scaleY = SizeY / spriteSize.height;

    // Set the scale
    bulletSprite.setScale(scaleX, scaleY);
    bulletSprite.rotate(180);

    bulletSprite.setPosition(bullet.getPosition().x, bullet.getPosition().y);
}

void EnemyBullets::draw(sf::RenderWindow &window) {
    bulletSprite.setPosition(bullet.getPosition().x, bullet.getPosition().y);
    window.draw(bulletSprite);
}

void EnemyBullets::update() {
    bullet.move(speedVector.x, speedVector.y);
}

void EnemyBullets::calculateSpeed(float playerX, float playerY) {
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

EnemyBullets::EnemyBullets(float x, float y, float playerX, float playerY) : Bullets(x, y, playerX, playerY) {
    this->SizeX = 50;
    this->SizeY = 50;
    this->bullet.setSize(sf::Vector2f(50, 50));
    this->speed = 3;
    this->EnemyBullets::loadTexture();
    this->EnemyBullets::calculateSpeed(playerX, playerY);
}
