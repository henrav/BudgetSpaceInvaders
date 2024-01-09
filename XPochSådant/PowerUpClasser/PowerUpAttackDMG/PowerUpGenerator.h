//
// Created by Henrik Ravnborg on 2023-11-27.
//

#ifndef UNTITLED3_POWERUPGENERATOR_H
#define UNTITLED3_POWERUPGENERATOR_H


#include "../../PowerUp.h"

class PowerUpGenerator {
private:
    float lvl1 = 0.5;
    float lvl2 = 0.3;
    float lvl3 = 0.2;
    float lvl4 = 0.1;
    float lvl5 = 0.05;
public:
    PowerUpGenerator();

    static PowerUp *generatePowerUplvl1();

    static PowerUp *generatePowerUplvl2();

    float getLvl2() const;

    float getLvl3() const;

    float getLvl4() const;

    float getLvl5() const;

    static PowerUp *generatePowerUp(int lvl);
    static double sigmoidExtraLuck(float PlayerLevel);

};


#endif //UNTITLED3_POWERUPGENERATOR_H
