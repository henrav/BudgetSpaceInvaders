//
// Created by Henrik Ravnborg on 2023-11-28.
//

#ifndef UNTITLED3_POWERUPBULLETSPEEDLVL1_H
#define UNTITLED3_POWERUPBULLETSPEEDLVL1_H


#include "../../../PowerUp.h"

class PowerUpBulletSpeedlvl1 : public PowerUp{
public:
    PowerUpBulletSpeedlvl1();

    void increasePlayerStats() override;

    int getRarity() override;

    std::string getPowerUpName() override;

    std::string getPowerUpDescription() override;

    std::string getPowerUpValue() override;

    std::string getAfterSelectedText() override;

    float getBulletSpeed();

};


#endif //UNTITLED3_POWERUPBULLETSPEEDLVL1_H
