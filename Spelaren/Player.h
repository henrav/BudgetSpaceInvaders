//
// Created by Henrik Ravnborg on 2023-11-15.
//

#ifndef HELLOSFML_PLAYER_H
#define HELLOSFML_PLAYER_H


#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "../Vapen/Weapon.h"
#include "../Vapen/PlayerWeapons.h"
#include "../Vapen/PlayerVapenTest/PlayerVapen.h"


static sf::Texture playerTexture;
class Weapon;


static int extraFireRate = 0;
static int extraDmg = 0;
static float extraBulletSpeed = 0;
class Player {
public:
    explicit Player(sf::RenderWindow &window);
    void move(float x, float y);
    void shoot();
    void setPostion(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
    float getSpeed() const;
    void setWeapon(PlayerVapen weapon);
    void shootWeapon();
    PlayerVapen & getWeapon();
    void addXP(int xp);
    int getXP();
    int getLevel();
    void levelUp();
    sf::RectangleShape getShapePos();
    double xpToLevelUp();
    void increaseXP(double i);
    void changeXspeed(float a);
    void changeYspeed(float a);
    int getExtraFireRate() const;
    void setExtraFireRate(int extraFireRate);
    static int getExtraDmg();
    void setExtraDmg(int extraDmg);
    float getExtraSpeed() const;
    void setExtraSpeed(float extraSpeed);
    static void addExtraFireRate(int extraFireRate);
    static void addExtraDmg(int extraDmg);
    static void addExtraBulletSpeed(float extraBulletSpeed);
    void loadTexture();
    static int getExtraFireRateStatic();
    static int getExtraDmgStatic();
    static float getExtraBulletSpeedStatic();
    void takeDamage(int dmg);
    int getHealth();


    void setPosition(float i, float d);

private:
    int playerLevel = 1;
    int health = 100;
    int totalXP = 0;
    float sizeX = 100;
    float sizeY = 100;
    double xp;
    float speed = 10;
    float xspeed;
    float yspeed;
    float xpos{};
    float ypos{};
    sf::RectangleShape player;
    sf::Sprite playerSprite;
    PlayerVapen weapon;



    void shootWeapon(Player &player);
};


#endif //HELLOSFML_PLAYER_H
