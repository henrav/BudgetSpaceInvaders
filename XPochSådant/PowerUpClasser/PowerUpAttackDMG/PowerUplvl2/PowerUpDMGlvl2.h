//
// Created by Henrik Ravnborg on 2023-11-28.
//

#ifndef UNTITLED3_POWERUPDMGLVL2_H
#define UNTITLED3_POWERUPDMGLVL2_H


#include "../../../PowerUp.h"

class PowerUpDMGlvl2 : public PowerUp{
public:

        PowerUpDMGlvl2();

        void increasePlayerStats() override;

        int getRarity() override;

        std::string getPowerUpName() override;

        std::string getPowerUpDescription() override;

        std::string getPowerUpValue() override;

        std::string getAfterSelectedText() override;

        int getAttackDamage();

};


#endif //UNTITLED3_POWERUPDMGLVL2_H
