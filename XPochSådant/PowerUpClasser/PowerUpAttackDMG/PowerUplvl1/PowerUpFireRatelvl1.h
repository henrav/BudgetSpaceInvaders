//
// Created by Henrik Ravnborg on 2023-11-23.
//

#ifndef UNTITLED3_POWERUPFIRERATELVL1_H
#define UNTITLED3_POWERUPFIRERATELVL1_H


#include "../../../PowerUp.h"

class PowerUpFireRatelvl1 : public PowerUp {
private:

public:
    PowerUpFireRatelvl1();

    void increasePlayerStats() override;

    int getRarity() override;

    std::string getPowerUpName() override;

    std::string getPowerUpDescription() override;

    std::string getPowerUpValue() override;

    std::string getAfterSelectedText() override;

    int getAttackRate();




};


#endif //UNTITLED3_POWERUPFIRERATELVL1_H
