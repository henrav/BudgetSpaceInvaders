//
// Created by Henrik Ravnborg on 2023-12-05.
//
#include "/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Effecter_Kulor_Och_Sådant/ExplosionListy.h"
#include "NyEnemyBullets.h"
using namespace std;
NyEnemyBullets::NyEnemyBullets(float posx, float posy, float playerx , float playery, float dmg) {
    this->damage = damage + dmg;
    this->bullet.setPosition(posx, posy);
    calculateSpeedandDirection(playerx, playery);
    this->bullet.setSize(sf::Vector2f(SizeX, SizeY));
    NyEnemyBullets::loadTexture();

}

void NyEnemyBullets::loadTexture() {
    if (!texture.loadFromFile("/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Effecter_Kulor_Och_Sådant/EnemyBullets.png", bullet.getTextureRect())) {
        std::cout << "Error loading texture" << std::endl;
    }
    bulletSprite.setTexture(texture);

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
void NyEnemyBullets::calculateSpeedandDirection(float playerx, float playery) {

        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        srand(seed);
        std::default_random_engine generator(seed);
        std::uniform_real_distribution<double> distributionDouble(-150, 150);
        double randomChance = distributionDouble(generator);
        float x = playerx - bullet.getPosition().x;
        float y = playery - bullet.getPosition().y;
        x += randomChance;
        float length = sqrt(x * x + y * y);
        speedVector = sf::Vector2f((x / length) * 3 , (y / length) * 3);

}


void NyEnemyBullets::draw(sf::RenderWindow &window) {
    bulletSprite.setPosition(bullet.getPosition().x, bullet.getPosition().y);
    window.draw(bulletSprite);
}

void NyEnemyBullets::setDamage(float damage) {
    this->damage = damage;
}

void NyEnemyBullets::setSpeed(float speed) {
    this->speed = speed;
}

void NyEnemyBullets::setSize(float sizex, float sizey) {
    this->SizeX = sizex;
    this->SizeY = sizey;
}

sf::RectangleShape &NyEnemyBullets::getBullet() {
    return bullet;
}

sf::Sprite &NyEnemyBullets::getBulletSprite() {
    return bulletSprite;
}


sf::Texture &NyEnemyBullets::getBulletTexture() {
    return bulletTexture;
}

sf::Vector2f &NyEnemyBullets::getSpeedVector() {
    return speedVector;
}

void NyEnemyBullets::updateBullet() {
    bullet.move(speedVector);
}

float NyEnemyBullets::getDamage() {
    return damage;
}

void NyEnemyBullets::explodeAnimation() {
    ExplosionListy::addExplosion(bullet.getPosition().x, bullet.getPosition().y);
}


