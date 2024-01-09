//
// Created by Henrik Ravnborg on 2023-11-15.
//

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include "Keys.h"
#include "MenuItems.h"



bool Keys::escapePressedLastFrame = false;

void Keys::handleInput(Game &game) {
    if (game.isGameIsRunning() && !game.getWonRound()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            game.getPlayer().move(-game.getPlayer().getSpeed(), 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            game.getPlayer().move(game.getPlayer().getSpeed(), 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            game.getPlayer().move(0, -game.getPlayer().getSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            game.getPlayer().move(0, game.getPlayer().getSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            game.getPlayer().shootWeapon();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !escapePressedLastFrame) {
        //MenuItems::pause(window, gameIsRunning);
        game.setPaused(true);
        MenuItems::mainMenu(game);
    }
    escapePressedLastFrame = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);

}

