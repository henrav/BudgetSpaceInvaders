//
// Created by Henrik Ravnborg on 2023-11-22.
//

#ifndef UNTITLED3_POWERUP_H
#define UNTITLED3_POWERUP_H


#include <SFML/Graphics/Text.hpp>
#include "../Spelaren/Player.h"

class PowerUp {
private:
protected:
    int attackDamage;
    int health;
    int speed;
    float bulletSpeed;
    std::string powerUpName;
    std::string powerUpDescription;
    std::string powerUpValue;
    std::string afterSelectedText;
    int attackRate;
    int rarity;
public:
    PowerUp();
    virtual void increasePlayerDMG();
    virtual void increasePlayerHealth();
    virtual void increasePlayerSpeed();
    virtual std::string getPowerUpName();
    virtual void increasePlayerStats();

    virtual std::string getPowerUpDescription();

    virtual std::string getPowerUpValue();

    virtual int getRarity();

    virtual std::string getAfterSelectedText();

    virtual void increasePlayerAttackRate();

    virtual void increasePlayerBulletSpeed();


};


#endif //UNTITLED3_POWERUP_H
