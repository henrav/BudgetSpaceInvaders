//
// Created by Henrik Ravnborg on 2023-11-30.
//

#include "BulletExplosion.h"
#include <iostream>
using namespace std;

BulletExplosion::BulletExplosion(float posX, float posY) {
    this->posX = posX;
    this->posY = posY;
    this->rect = sf::IntRect(0, 0, 500, 500);
    loadTexture();
}

void BulletExplosion::setSize(float sizeX, float sizeY) {
    this->sizeX = sizeX;
    this->sizeY = sizeY;
}

void BulletExplosion::setPos(float posX, float posY) {
    this->posX = posX;
    this->posY = posY;
}




void BulletExplosion::setRect(sf::IntRect &rect) {
    this->rect = rect;
}

void BulletExplosion::draw(sf::RenderWindow &window) {
    switch (clock.getElapsedTime().asMilliseconds()) {
        case 0 ... 25:{
            window.draw(*sprites[0]);
            break;
        }
        case 26 ... 50:{
            window.draw(*sprites[1]);
            break;
        }
        case 51 ... 75:{
            window.draw(*sprites[2]);
            break;
        }
        case 76 ... 100:{
            window.draw(*sprites[3]);
            break;
        }
        case 101 ... 125:{
            window.draw(*sprites[4]);
            break;
        }
        case 126 ... 150:{
            window.draw(*sprites[5]);
            break;
        }
        case 151 ... 175:{
            window.draw(*sprites[6]);
            break;
        }
        case 176 ... 200:{
            window.draw(*sprites[7]);
            break;
        }
        case 201 ... 225:{
            window.draw(*sprites[8]);
            break;
        }
        case 226 ... 250:{
            window.draw(*sprites[9]);
            break;
        }
        case 251 ... 275:{
            window.draw(*sprites[10]);
            break;
        }
        default:{
            break;
        }

    }
}

void BulletExplosion::update() {

}

void BulletExplosion::loadTexture() {
    for (int i = 0; i <= 10; ++i) {
        auto *texture = new sf::Texture;
        auto *sprite = new sf::Sprite;
        switch (i) {
            case 0: {
                texture->loadFromFile(
                        "/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Effecter_Kulor_Och_Sådant/ExplosionerPictures/ExplosionNR2.png",
                        rect);
                sprite->setTexture(*texture);
                sprite->setPosition(posX, posY);
                sprites.push_back(sprite);
                textures.push_back(texture);
                break;
            }
            case 1: {
                texture->loadFromFile(
                        "/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Effecter_Kulor_Och_Sådant/ExplosionerPictures/ExplosionNR3.png",
                        rect);
                sprite->setTexture(*texture);
                sprite->setPosition(posX, posY);
                sprites.push_back(sprite);
                textures.push_back(texture);
                break;
            }
            case 2: {
                texture->loadFromFile(
                        "/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Effecter_Kulor_Och_Sådant/ExplosionerPictures/Explosionnr4.png",
                        rect);
                sprite->setTexture(*texture);
                sprite->setPosition(posX, posY);
                sprites.push_back(sprite);
                textures.push_back(texture);
                break;
            }
            case 3: {
                texture->loadFromFile(
                        "/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Effecter_Kulor_Och_Sådant/ExplosionerPictures/ExplosionNr5.png",
                        rect);
                sprite->setTexture(*texture);
                sprite->setPosition(posX, posY);
                sprites.push_back(sprite);
                textures.push_back(texture);
                break;
            }
            case 4: {
                texture->loadFromFile(
                        "/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Effecter_Kulor_Och_Sådant/ExplosionerPictures/Explosionnr6 (2).png",
                        rect);
                sprite->setTexture(*texture);
                sprite->setPosition(posX, posY);
                sprites.push_back(sprite);
                textures.push_back(texture);
                break;
            }
            case 5: {
                texture->loadFromFile(
                        "/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Effecter_Kulor_Och_Sådant/ExplosionerPictures/Explosionnr7 (2).png",
                        rect);
                sprite->setTexture(*texture);
                sprite->setPosition(posX, posY);
                sprites.push_back(sprite);
                textures.push_back(texture);
                break;
            }
            case 6: {
                texture->loadFromFile(
                        "/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Effecter_Kulor_Och_Sådant/ExplosionerPictures/Explosionnr8 (2).png",
                        rect);
                sprite->setTexture(*texture);
                sprite->setPosition(posX, posY);
                sprites.push_back(sprite);
                textures.push_back(texture);
                break;
            }
            case 7: {
                texture->loadFromFile(
                        "/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Effecter_Kulor_Och_Sådant/ExplosionerPictures/Explosionnr9 (2).png",
                        rect);
                sprite->setTexture(*texture);
                sprite->setPosition(posX, posY);
                sprites.push_back(sprite);
                textures.push_back(texture);
                break;
            }
            case 8: {
                texture->loadFromFile(
                        "/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Effecter_Kulor_Och_Sådant/ExplosionerPictures/Explosionnr10 (2).png",
                        rect);
                sprite->setTexture(*texture);
                sprite->setPosition(posX, posY);
                sprites.push_back(sprite);
                textures.push_back(texture);
                break;
            }
            case 9: {
                texture->loadFromFile(
                        "/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Effecter_Kulor_Och_Sådant/ExplosionerPictures/Explosionnr11 (2).png",
                        rect);
                sprite->setTexture(*texture);
                sprite->setPosition(posX, posY);
                sprites.push_back(sprite);
                textures.push_back(texture);
                break;
            }
            case 10: {
                texture->loadFromFile(
                        "/Users/henrikravnborg/CLionProjects/untitled3/Bilder/Effecter_Kulor_Och_Sådant/ExplosionerPictures/Explosionnr12(2).png",
                        rect);
                sprite->setTexture(*texture);
                sprite->setPosition(posX, posY);
                sprites.push_back(sprite);
                textures.push_back(texture);
                break;
            }
            default : {
                cout << "Error loading bullet explosion texture" << endl;
                break;
            }
        }
    }
}
sf::Clock &BulletExplosion::getClock() {
    return clock;
}





