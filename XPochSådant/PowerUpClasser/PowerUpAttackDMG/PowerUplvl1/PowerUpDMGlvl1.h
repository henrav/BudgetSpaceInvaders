//
// Created by Henrik Ravnborg on 2023-11-27.
//

#ifndef UNTITLED3_POWERUPDMGLVL1_H
#define UNTITLED3_POWERUPDMGLVL1_H


#include "../../../PowerUp.h"

class PowerUpDMGlvl1 : public PowerUp{
private:



public:
    PowerUpDMGlvl1();

    void increasePlayerStats() override;

    int getRarity() override;

    std::string getPowerUpName() override;

    std::string getPowerUpDescription() override;

    std::string getPowerUpValue() override;

    std::string getAfterSelectedText() override;

    int getAttackDamage();




};


#endif //UNTITLED3_POWERUPDMGLVL1_H
