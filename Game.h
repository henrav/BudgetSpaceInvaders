//
// Created by Henrik Ravnborg on 2023-11-17.
//

#ifndef UNTITLED3_GAME_H
#define UNTITLED3_GAME_H
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Spelaren//Player.h"
#include "Keys.h"
#include "Vapen/Weapon.h"
#include <thread>
#include "Bilder/Effecter_Kulor_Och_Sådant/ExplosionListy.h"

#include "MenuItems.h"
#include "XPochSådant/XpSpawner.h"

#include "CollisionDetector.h"
#include "XPochSådant/PowerUpClasser/PowerUpAttackDMG/PowerUpGenerator.h"






class Game {
private:
    bool gameIsRunning;
    bool roundWon = false;
    bool levelUp = false;
    bool hasClickedLevelUp = true;
    bool hasMenuOpen = false;
    bool gameWindowIsOpen = true;
    bool paused = false;
    bool levelUpMenuOpen = false;
    sf::Clock clock;
    std::vector<PowerUp*> powerUpList;
    sf::Clock framrateClock;
    float lastTime = 0;

    int playerLevel = 1;
    sf::RenderWindow window;
    Player player;
    sf::Text text;
    int roundNR;
    sf::Image backgroundImage;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::IntRect backgroundRect;

    void loadBackground();
    void handleEvents();
    void checkVictory();
    void updateGameObjects();

    void moveXpToHeroAfterWin();

    void checkPlayerEdge();


public:
    Game();
    void hasPlayerLevelUp();
    void isPlayerDoneLeveling();
    void run();
    void setGameWindowIsOpen(bool gameWindowIsOpen);
    bool getGameWindowIsOpen();
    void startGame();
    void restartLevel();
    void restartGame();
    void nextRound();
    void drawGameObjects();
    bool getWonRound();
    bool checkLevelUp();
    void wonRoundAnimation();
    void increasePlayerLevel();
    bool getHasClickedLevelUp();
    void setHasClickedLevelUp(bool hasClickedLevelUp);
    bool getHasMenuOpen();
    void setHasMenuOpen(bool hasMenuOpen);
    void drawBackground();
    sf::Sprite & getBackgroundSprite();
    void enableCheats();
    void generateNewPowerUp();
    std::vector<PowerUp*> &getPowerUpList();
    double nrOfLVL1Enemies(int roundNr);


    void setLevelUpMenuOpen(bool levelUpMenuOpen);
    bool getLevelUpMenuOpen();
    bool getLevelUp();


    bool isGameIsRunning();

    bool isRoundWon();

    bool isLevelUp();

    int &getPlayerLevel();

    sf::RenderWindow &getWindow();

    Player &getPlayer();


    sf::Text &getText();

    int getRoundNr();

    void setGameIsRunning(bool gameIsRunning);

    void setRoundWon(bool roundWon);

    void setLevelUp(bool levelUp);

    void setPlayerLevel(int playerLevel);

    void setPlayer(Player &player);


    void setText(sf::Text &text);

    void setRoundNr(int roundNr);
    void setPaused(bool paused);
    bool getPaused();


    void drawText();

    void callLevelUpMenu();

    void nextRoundVersion2DontUse();

    void drawExplosions();
};


#endif //UNTITLED3_GAME_H
