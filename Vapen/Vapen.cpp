//
// Created by Henrik Ravnborg on 2023-12-05.
//

#include "Vapen.h"
#include "../Spelaren/Player.h"


int Vapen::getFireRate() const {
    return fireRate;
}

float Vapen::getDmg() {
    return baseDamage;
}

void Vapen::clearBullets() {

}

std::vector<Bullets> &Vapen::getBullets() {
}

int Vapen::getPlayerFireRate() const {
    int a = baseFireRate;
    int totalFireRate = fireRate + Player::getExtraFireRateStatic();
    // Use a logarithmic function to calculate the fire rate
    // The constant 10 is just an example, you can adjust it to get the curve you want
    int reduction = static_cast<int>((std::log(totalFireRate) + 1) * 110);
    // cout << "totalFireRate = " + to_string(totalFireRate) << endl;
    // Ensure that the fire rate never goes below 50 and above the maximum fire rate reduction
    return baseFireRate - reduction;
}

int Vapen::getEnemyFireRate() {
    return 500;
}
