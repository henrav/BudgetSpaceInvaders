//
// Created by Henrik Ravnborg on 2023-11-15.
//



#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(sf::RenderWindow &window) {
    this->player.setSize(sf::Vector2f(sizeX, sizeY));
    this->player.setFillColor(sf::Color::Green);
    this->weapon = PlayerVapen();
    loadTexture();
    setPostion(window);

}
void Player::loadTexture() {
    if (!playerTexture.loadFromFile("/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Player.png", player.getTextureRect())) {
        cout << "Error loading player texture" << endl;
    }
    playerSprite.setTexture(playerTexture);
    float scaleX = sizeX / playerSprite.getLocalBounds().width;
    float scaleY = sizeY / playerSprite.getLocalBounds().height;
    playerSprite.setScale(scaleX, scaleY);
    playerSprite.setPosition(player.getPosition().x, player.getPosition().y);
}

void Player::setPostion(sf::RenderWindow &window) {
    float x = window.getSize().x / 2 - 25;
    float y = window.getSize().y -100;
    player.move(x, y);
}

void Player::shoot() {

}


void Player::setWeapon(PlayerVapen vapen) {
    this->weapon = vapen;
}

void Player::shootWeapon() {
    weapon.shoot(player.getPosition().x, player.getPosition().y, extraBulletSpeed);
}

PlayerVapen & Player::getWeapon() {
    return weapon;
}

void Player::addXP(int xp) {
    this->xp += xp;
}
int Player::getXP() {
    return xp;
}

int Player::getLevel() {
    return this->playerLevel;
}


sf::RectangleShape Player::getShapePos() {
    return player;
}

void Player::increaseXP(double i) {
    this->xp += i;
    double totalxp = 10 + (0.08 * playerLevel * playerLevel);
    if (xp >= totalxp){
        levelUp();
    }
}

void Player::levelUp() {
    // Use a logarithmic function to calculate the XP needed for the next level
    // The constant 200 is just an example, you can adjust it to get the curve you want
    double totalxp = 10 + (0.08 * playerLevel * playerLevel);
    double xpToNextLvlLocal = totalxp - xp;
    if (xpToNextLvlLocal <= 0){
        xpToNextLvlLocal = xpToNextLvlLocal *-1;
        playerLevel ++;
        cout << "Level up! You are now level " + to_string(playerLevel) << endl;
        xp = 0;
        increaseXP(xpToNextLvlLocal);
    }
}
void Player::takeDamage(int dmg) {
    health -= dmg;
}
int Player::getHealth() {
    return health;
}

void Player::move(float x, float y) {
    player.move(x, y);
}

void Player::draw(sf::RenderWindow &window) {
    playerSprite.setPosition(player.getPosition().x, player.getPosition().y);
    window.draw(playerSprite);
}

float Player::getSpeed() const {
    return speed;
}

int Player::getExtraFireRate() const {
    return extraFireRate;
}
int Player::getExtraDmg() {
    return extraDmg;
}
float Player::getExtraSpeed() const{
    return extraBulletSpeed;
}
void Player::setExtraDmg(int extraDmg) {
    extraDmg = extraDmg;
}
void Player::setExtraFireRate(int extraFireRate) {
    extraFireRate = extraFireRate;
}
void Player::setExtraSpeed(float extraSpeed) {
   extraBulletSpeed = extraSpeed;
}

void Player::addExtraFireRate(int ExtraFireRate) {
    extraFireRate += ExtraFireRate;
}

void Player::addExtraDmg(int ExtraDmg) {
    extraDmg += ExtraDmg;
}

void Player::addExtraBulletSpeed(float ExtraBulletSpeed) {
    extraBulletSpeed += ExtraBulletSpeed;

}

int Player::getExtraDmgStatic() {
    return extraDmg;
}

int Player::getExtraFireRateStatic() {
    return extraFireRate;
}

float Player::getExtraBulletSpeedStatic() {
    return extraBulletSpeed;
}

void Player::setPosition(float i, float d) {
    player.setPosition(i, d);
}













