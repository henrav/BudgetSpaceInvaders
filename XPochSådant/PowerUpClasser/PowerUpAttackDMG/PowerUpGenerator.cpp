//
// Created by Henrik Ravnborg on 2023-11-27.
//

#include "PowerUpGenerator.h"
#include "PowerUplvl1/PowerUpDMGlvl1.h"
#include "PowerUplvl1/PowerUpFireRatelvl1.h"
#include "PowerUplvl1/PowerUpBulletSpeedlvl1.h"
#include "PowerUplvl2/PowerUpDMGlvl2.h"
#include "PowerUplvl2/PowerUpFireRatelvl2.h"
#include <iostream>
#include <ctime>
#include <random>
PowerUp *PowerUpGenerator::generatePowerUp(int lvl) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    double sigmoid = sigmoidExtraLuck(lvl);
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distributionDouble(1.0, 10.0);
    double randomChance = distributionDouble(generator) * 0.1 - sigmoid;
    if (randomChance >= 0.2){
        return generatePowerUplvl1();
    } else if (randomChance < 0.2){
        return generatePowerUplvl2();
    }
    else {
        return generatePowerUplvl1();
    }
}

PowerUp *PowerUpGenerator::generatePowerUplvl1() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distributionInt(1, 3);
    double randomChance = distributionInt(generator);
    if (randomChance == 1){
        return new PowerUpDMGlvl1();
    } else if (randomChance == 2){
        return new PowerUpFireRatelvl1();
    }
    else {
        return new PowerUpBulletSpeedlvl1();
    }


}

PowerUp *PowerUpGenerator::generatePowerUplvl2() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distributionInt(1, 2);
    double randomChance = distributionInt(generator);
    if (randomChance == 1){
        return new PowerUpDMGlvl2();
    } else if (randomChance == 2){
        return new PowerUpFireRatelvl2();
    }
    else {
        return new PowerUpBulletSpeedlvl1();
    }
}

double PowerUpGenerator::sigmoidExtraLuck(float PlayerLevel) {
    return 1 / (1.5 + exp(-0.1 * PlayerLevel)) - 0.4;
}
