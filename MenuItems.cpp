//
// Created by Henrik Ravnborg on 2023-11-16.
//

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <SFML/System/Sleep.hpp>
#include "MenuItems.h"
#include "XPochSådant/PowerUpClasser/PowerUpAttackDMG/PowerUplvl1/PowerUpFireRatelvl1.h"
#include "XPochSådant/PowerUpClasser/PowerUpAttackDMG/PowerUplvl1/PowerUpDMGlvl1.h"
#include "XPochSådant/PowerUpClasser/PowerUpAttackDMG/PowerUpGenerator.h"


using namespace std;
bool needNewPowerUps = true; // Add this before your main loop

bool MenuItems::hasWindowOpen = false;

bool MenuItems::pause(Game &game) {
    return false;
}

int MenuItems::mainMenu(Game &game) {
        game.getWindow().clear();
        game.drawGameObjects();
        game.setGameIsRunning(false);
        sf::Font font;
        if (!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial Unicode.ttf")) {
            // Handle font loading error
            std::cerr << "Failed to load font." << std::endl;
            return -1; // or handle the error in an appropriate way
        }

        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(Menu_larger);
        text.setFillColor(sf::Color::White);
        while (!game.isGameIsRunning()) {
            bool powerUpsGenerated = false;
            bool levelUpComplete = false;
            sf::Event event;
            while (game.getWindow().pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    game.getWindow().close();
                    return 0;
                }
            }



            int mouseX = sf::Mouse::getPosition(game.getWindow()).x;
            int mouseY = sf::Mouse::getPosition(game.getWindow()).y;

            for (int i = 0; i < MainMenuSize; i++) {
                text.setString(mainmenu[i]);
                text.setPosition(game.getWindow().getSize().x / 2 - 200, game.getWindow().getSize().y - game.getWindow().getSize().y + 50 + i * MainMenu_larger);

                sf::FloatRect textBounds = text.getGlobalBounds();
                if (textBounds.contains(static_cast<float>(mouseX), static_cast<float>(mouseY))) {
                    text.setFillColor(sf::Color::Red);
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        if (i == 0) {
                            game.setPaused(false);
                            resume(game);
                        } else if (i == 1) {
                            game.getWindow().close();
                            return 0;
                        } else if (i == 2) {
                            game.setPaused(false);
                            restart(game);
                        } else if (i == 3) {
                            game.setPaused(false);
                            restartLevel(game);
                        }
                    }
                } else {
                    text.setFillColor(sf::Color::White);
                }

                game.getWindow().draw(text);
            }
            game.getWindow().display();
        }
    return 0;
    }


void MenuItems::resume(Game &game) {
    game.setGameIsRunning(true);

    // Add any additional actions needed when the game is resumed
    game.getWindow().clear();
    // Perform other setup or actions...
    game.getWindow().display();
}

void MenuItems::restart(Game &game) {
    game.restartGame();

    // Add any additional actions needed when the game is restarted
    game.getWindow().clear();
    // Perform other setup or actions...
    game.getWindow().display();
}

void MenuItems::restartLevel(Game &game) {
    game.restartLevel();


    // Add any additional actions needed when the level is restarted
    game.getWindow().clear();
    // Perform other setup or actions...
    game.getWindow().display();

}

int MenuItems::victory(Game &game) {
    game.getWindow().clear();
    game.drawGameObjects();
    game.setGameIsRunning(false);
    sf::Font font;
    if (!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial Unicode.ttf")) {
        // Handle font loading error
        std::cerr << "Failed to load font." << std::endl;
        return 0; // or handle the error in an appropriate way
    }
    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(Menu_larger);

    while (!game.isGameIsRunning()) {
        sf::Event event;
        while (game.getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                game.getWindow().close();
                return 0;
            }
        }
        game.getWindow().clear();
        game.drawBackground();

        int mouseX = sf::Mouse::getPosition(game.getWindow()).x;
        int mouseY = sf::Mouse::getPosition(game.getWindow()).y;

        for (int i = 0; i < victorySize; i++) {
            text.setString(victoryMenu[i]);
            text.setPosition(game.getWindow().getSize().x / 2 - 600, game.getWindow().getSize().y - game.getWindow().getSize().y + 300 + i * MainMenu_larger);

            sf::FloatRect textBounds = text.getGlobalBounds();
            if (textBounds.contains(static_cast<float>(mouseX), static_cast<float>(mouseY)) && i != 0) {
                text.setFillColor(sf::Color::Red);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (i == 1) {
                        game.nextRound();
                    } else if (i == 2) {
                        game.getWindow().close();
                        return 0;
                    }
                }
            } else {
                text.setFillColor(sf::Color::White);
            }


            game.getWindow().draw(text);
        }


        game.getWindow().display();
    }
    return 0;
}

int MenuItems::gameOver(Game &game) {
    game.getWindow().clear();
    game.drawGameObjects();
    game.setGameIsRunning(false);
    sf::Font font;
    if (!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial Unicode.ttf")) {
        // Handle font loading error
        std::cerr << "Failed to load font." << std::endl;
        return 0; // or handle the error in an appropriate way
    }
    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(Menu_larger);

    while (!game.isGameIsRunning()) {
        sf::Event event;
        while (game.getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                game.getWindow().close();
                return 0;
            }
        }
        game.getWindow().clear();
        game.drawBackground();

        int mouseX = sf::Mouse::getPosition(game.getWindow()).x;
        int mouseY = sf::Mouse::getPosition(game.getWindow()).y;

        for (int i = 0; i < loseSize; i++) {
            text.setString(losemenu[i]);
            text.setPosition(game.getWindow().getSize().x / 2 - 600, game.getWindow().getSize().y - game.getWindow().getSize().y + 300 + i * MainMenu_larger);

            sf::FloatRect textBounds = text.getGlobalBounds();
            if (textBounds.contains(static_cast<float>(mouseX), static_cast<float>(mouseY)) && i != 0) {
                text.setFillColor(sf::Color::Red);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (i == 1) {
                        restart(game);
                    } else if (i == 2) {
                        game.getWindow().close();
                    }
                }
            } else {
                text.setFillColor(sf::Color::White);
            }


            game.getWindow().draw(text);
        }



        game.getWindow().display();
    }
    return 0;

}

int MenuItems::levelUpMenu(Game &game) {
    game.setHasMenuOpen(true);
    game.setGameIsRunning(false);
    sf::Font font;
    if (!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial Unicode.ttf")) {
        // Handle font loading error
        std::cerr << "Failed to load font." << std::endl;
        return 0; // or handle the error in an appropriate way
    }

    game.generateNewPowerUp();
    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(50);
    while (game.getLevelUp()) {
        std::vector<PowerUp *> PowerList = game.getPowerUpList();
        sf::Event event;
        while (game.getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                game.getWindow().close();
                return 0;
            }
        }
        game.getWindow().clear();
        game.drawBackground();

        int mouseX = sf::Mouse::getPosition(game.getWindow()).x;
        int mouseY = sf::Mouse::getPosition(game.getWindow()).y;

        for (int i = 0; i <= 4; i++) {
            if (i == 0){
                text.setString("level up");
                text.setPosition(game.getWindow().getSize().x / 2 - 400,
                                 game.getWindow().getSize().y - game.getWindow().getSize().y + 150);
                text.setFillColor(sf::Color::White);
                text.setCharacterSize(50);
                game.getWindow().draw(text);
                continue;
            }
            text.setCharacterSize(50);
            text.setString(PowerList[i-1]->getPowerUpName());

            text.setPosition(game.getWindow().getSize().x / 2 - 400,
                             game.getWindow().getSize().y - game.getWindow().getSize().y + 300 +
                             i * MainMenu_larger);

            sf::FloatRect textBounds = text.getGlobalBounds();
            if (textBounds.contains(static_cast<float>(mouseX), static_cast<float>(mouseY))) {
                text.setFillColor(sf::Color::Red);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (i == 1) {
                        PowerList[i -1]->increasePlayerStats();
                        game.getWindow().clear();
                        game.drawBackground();
                        game.increasePlayerLevel();
                        sf::Text text;
                        text.setFont(font);
                        text.setFillColor(sf::Color::White);
                        text.setString(PowerList[i -1]->getAfterSelectedText());
                        text.setPosition(game.getWindow().getSize().x / 2 - 400,
                                         game.getWindow().getSize().y - game.getWindow().getSize().y + 300 +
                                         i * MainMenu_larger);
                        text.setCharacterSize(50);
                        game.getWindow().draw(text);
                        game.getWindow().display();
                        sf::sleep(sf::milliseconds(1000));
                        game.generateNewPowerUp();
                        game.isPlayerDoneLeveling();
                    } else if (i == 2) {
                        PowerList[i -1]->increasePlayerStats();
                        game.getWindow().clear();
                        game.drawBackground();
                        game.increasePlayerLevel();
                        sf::Text text;
                        text.setFont(font);
                        text.setFillColor(sf::Color::White);
                        text.setString(PowerList[i -1]->getAfterSelectedText());
                        text.setPosition(game.getWindow().getSize().x / 2 - 400,
                                         game.getWindow().getSize().y - game.getWindow().getSize().y + 300 +
                                         i * MainMenu_larger);
                        text.setCharacterSize(50);
                        game.getWindow().draw(text);
                        game.getWindow().display();
                        sf::sleep(sf::milliseconds(1000));
                        game.generateNewPowerUp();
                        game.isPlayerDoneLeveling();
                    }else if (i == 3){
                        PowerList[i -1]->increasePlayerStats();
                        game.getWindow().clear();
                        game.drawBackground();
                        game.increasePlayerLevel();
                        sf::Text text;
                        text.setFont(font);
                        text.setFillColor(sf::Color::White);
                        text.setString(PowerList[i -1]->getAfterSelectedText());
                        text.setPosition(game.getWindow().getSize().x / 2 - 400,
                                         game.getWindow().getSize().y - game.getWindow().getSize().y + 300 +
                                         i * MainMenu_larger);
                        text.setCharacterSize(50);
                        game.getWindow().draw(text);
                        game.getWindow().display();
                        sf::sleep(sf::milliseconds(1000));
                        game.generateNewPowerUp();
                        game.isPlayerDoneLeveling();
                    }else if (i == 4){
                        PowerList[i -1]->increasePlayerStats();
                        game.getWindow().clear();
                        game.drawBackground();
                        game.increasePlayerLevel();
                        sf::Text text;
                        text.setFont(font);
                        text.setFillColor(sf::Color::White);
                        text.setString(PowerList[i -1]->getAfterSelectedText());
                        text.setPosition(game.getWindow().getSize().x / 2 - 400,
                                         game.getWindow().getSize().y - game.getWindow().getSize().y + 300 +
                                         i * MainMenu_larger);
                        text.setCharacterSize(50);
                        game.getWindow().draw(text);
                        game.getWindow().display();
                        sf::sleep(sf::milliseconds(1000));
                        game.generateNewPowerUp();
                        game.isPlayerDoneLeveling();
                    }
                }

            }else {
                text.setFillColor(sf::Color::White);
            }
            game.getWindow().draw(text);

        }

        game.getWindow().display();
    }


    return 0;
}

bool MenuItems::isHasWindowOpen() {
    return hasWindowOpen;
}







