//
// Created by Henrik Ravnborg on 2023-11-28.
//

#ifndef UNTITLED3_POWERUPFIRERATELVL2_H
#define UNTITLED3_POWERUPFIRERATELVL2_H
#include "../../../PowerUp.h"


class PowerUpFireRatelvl2 : public PowerUp{
public:

    PowerUpFireRatelvl2();

    void increasePlayerStats() override;

    int getRarity() override;

    std::string getPowerUpName() override;

    std::string getPowerUpDescription() override;

    std::string getPowerUpValue() override;

    std::string getAfterSelectedText() override;

    int getAttackRate();

};


#endif //UNTITLED3_POWERUPFIRERATELVL2_H
