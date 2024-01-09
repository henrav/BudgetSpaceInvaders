//
// Created by Henrik Ravnborg on 2023-11-15.
//

#ifndef HELLOSFML_KEYS_H
#define HELLOSFML_KEYS_H
#include <ctime>
#include <cmath>

#include <SFML/Graphics/RenderWindow.hpp>
#include "Spelaren//Player.h"
class Game;

class Keys {
private:
    static bool escapePressedLastFrame;



public:
    static void handleInput(Game &game);

};


#endif //HELLOSFML_KEYS_H
