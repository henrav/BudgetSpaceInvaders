//
// Created by Henrik Ravnborg on 2023-12-05.
//

#include "NyBullets.h"

using namespace std;

float NyBullets::getSizeY()  {
    cout << "NyBullets returna sizey" << endl;
    cout << '\n';
    return SizeY;
}

float NyBullets::getSizeX()  {
    cout << "NyBullets returna sizex" << endl;
    cout << '\n';
    return SizeX;
}

float NyBullets::getSpeed()  {
    cout << "NyBullets returna speed" << endl;
    cout << '\n';
    return speed;
}

float NyBullets::getDamage()  {
    cout << "NyBullets returna damage" << endl;
    cout << '\n';
    return damage;
}

void NyBullets::setDamage(float damage) {
cout << "error abstract thingy from NyBullets setDamage" << endl;
cout << '\n';
}

void NyBullets::setSpeed(float speed) {
cout << "error abstract thingy from NyBullets setSpeed" << endl;
cout << '\n';
}

void NyBullets::setSize(float sizex, float sizey) {
cout << "error abstract thingy from NyBullets setSize" << endl;
cout << '\n';
}

sf::RectangleShape &NyBullets::getBullet() {
cout << "error abstract thingy from NyBullets getBullet" << endl;
cout << '\n';
}

sf::Sprite &NyBullets::getBulletSprite() {
cout << "error abstract thingy from NyBullets getBulletSprite" << endl;
cout << '\n';
}

sf::Texture &NyBullets::getBulletTexture() {
cout << "error abstract thingy from NyBullets getBulletTexture" << endl;
cout << '\n';
}

sf::Vector2f &NyBullets::getSpeedVector() {
cout << "error abstract thingy from NyBullets getSpeedVector" << endl;
cout << '\n';
}



void NyBullets::updateBullet() {
    cout << "error abstract thingy from NyBullets updateBullet" << endl;
    cout << '\n';
}

void NyBullets::draw(sf::RenderWindow &window) {
    cout << "error abstract thingy from NyBullets draw" << endl;
    cout << '\n';

}

void NyBullets::loadTexture() {
    cout << "error abstract thingy from NyBullets loadTexture" << endl;
    cout << '\n';

}

void NyBullets::explodeAnimation() {

}




