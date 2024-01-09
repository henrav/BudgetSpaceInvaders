//
// Created by Henrik Ravnborg on 2023-11-28.
//

#ifndef UNTITLED3_POWERUPBULLETSPEEDLVL2_H
#define UNTITLED3_POWERUPBULLETSPEEDLVL2_H


#include "../../../PowerUp.h"

class PowerUpBulletSpeedlvl2 : public PowerUp{
public:
    PowerUpBulletSpeedlvl2();

    void increasePlayerStats() override;

    int getRarity() override;

    std::string getPowerUpName() override;

    std::string getPowerUpDescription() override;

    std::string getPowerUpValue() override;

    std::string getAfterSelectedText() override;

    float getBulletSpeed();

};


#endif //UNTITLED3_POWERUPBULLETSPEEDLVL2_H
