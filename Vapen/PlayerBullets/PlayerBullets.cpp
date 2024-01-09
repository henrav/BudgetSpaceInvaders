//
// Created by Henrik Ravnborg on 2023-11-30.
//

#include "PlayerBullets.h"
#include <iostream>
using namespace std;

PlayerBullets::PlayerBullets(float x, float y, float addPlayerSpeed, float weaponSpeed, float dmg) : Bullets(x, y, addPlayerSpeed) {
    this->speed = weaponSpeed;
    this->speedVector = sf::Vector2f(0, -speed - addPlayerSpeed);
    this->bullet.setSize(sf::Vector2f(SizeX, SizeY));
    this->dmg = dmg;
    bullet.setPosition(x, y);
    PlayerBullets::loadTexture();
}

sf::RectangleShape &PlayerBullets::getBullet() {
    return Bullets::getBullet();
}

void PlayerBullets::loadTexture() {
    if (!playerBulletTexture.loadFromFile("/Users/henrikravnborg/CLionProjects/untitled3/Bilder/NormalPlayerShot.png", bullet.getTextureRect())) {
        cout << "Error loading bullet texture" << endl;
    }
    bulletSprite.setTexture(playerBulletTexture);

    // Get the original size of the sprite
    sf::FloatRect spriteSize = bulletSprite.getLocalBounds();

    // Calculate the scale factors
    float scaleX = SizeX / spriteSize.width;
    float scaleY = SizeY / spriteSize.height;

    // Set the scale
    bulletSprite.setScale(scaleX, scaleY);

    bulletSprite.setPosition(bullet.getPosition().x, bullet.getPosition().y);
}

void PlayerBullets::draw(sf::RenderWindow &window) {
    bulletSprite.setPosition(bullet.getPosition().x, bullet.getPosition().y);
    window.draw(bulletSprite);
}

void PlayerBullets::update() {
    bullet.move(speedVector.x, speedVector.y);
}

void PlayerBullets::calculateSpeed(float playerX, float playerY) {
    Bullets::calculateSpeed(playerX, playerY);
}
