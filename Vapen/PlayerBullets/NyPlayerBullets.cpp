//
// Created by Henrik Ravnborg on 2023-12-05.
//
#include "/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Effecter_Kulor_Och_Sådant/ExplosionListy.h"
#include "NyPlayerBullets.h"
using namespace std;

NyPlayerBullets::NyPlayerBullets(float posx, float posy, float speed, float dmg) {
    this-> speedVector = sf::Vector2f(0, -speed);
    this->bullet.setSize(sf::Vector2f(SizeX, SizeY));
    this->bullet.setPosition(posx, posy);
    this->damage = dmg;
    NyPlayerBullets::loadTexture();
}

void NyPlayerBullets::loadTexture() {
    if (!xdplayerBulletTexture.loadFromFile("/Users/henrikravnborg/CLionProjects/untitled3/Bilder/NormalPlayerShot.png", bullet.getTextureRect())) {
        cout << "Error loading bullet texture" << endl;
    }
    bulletSprite.setTexture(xdplayerBulletTexture);

    // Get the original size of the sprite
    sf::FloatRect spriteSize = bulletSprite.getLocalBounds();

    // Calculate the scale factors
    float scaleX = SizeX / spriteSize.width;
    float scaleY = SizeY / spriteSize.height;

    // Set the scale
    bulletSprite.setScale(scaleX, scaleY);

    bulletSprite.setPosition(bullet.getPosition().x, bullet.getPosition().y);
}

void NyPlayerBullets::draw(sf::RenderWindow &window) {
    bulletSprite.setPosition(bullet.getPosition().x, bullet.getPosition().y);
    window.draw(bulletSprite);
}

void NyPlayerBullets::setDamage(float damage) {
    this->damage = damage;
}

void NyPlayerBullets::setSpeed(float speed) {
    this->speed = speed;
}

void NyPlayerBullets::setSize(float sizex, float sizey) {
    this->SizeX = sizex;
    this->SizeY = sizey;
}

sf::RectangleShape &NyPlayerBullets::getBullet() {
    return bullet;
}

sf::Sprite &NyPlayerBullets::getBulletSprite() {
    return bulletSprite;
}

sf::Texture &NyPlayerBullets::getBulletTexture() {
    return bulletTexture;
}

sf::Vector2f &NyPlayerBullets::getSpeedVector() {
    return speedVector;
}
void NyPlayerBullets::updateBullet() {
    bullet.move(speedVector);
}

float NyPlayerBullets::getSizeY()  {
    return SizeY;
}

float NyPlayerBullets::getSizeX()  {
    return SizeX;
}

float NyPlayerBullets::getSpeed()  {
    return speed;
}

float NyPlayerBullets::getDamage()  {

    return damage;
}

void NyPlayerBullets::explodeAnimation() {
    ExplosionListy::addExplosion(bullet.getPosition().x, bullet.getPosition().y);
}







