//
// Created by Henrik Ravnborg on 2023-11-16.
//

#ifndef UNTITLED3_MENUITEMS_H
#define UNTITLED3_MENUITEMS_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <list>
#include "Game.h"
#include "XPochSådant/PowerUp.h"

class MenuItems {
private:
    static bool hasWindowOpen;
    static const int MainMenuSize = 4;
    static const int loseSize = 3;
    static const int victorySize = 3;
    static const int MainMenu_larger = 140, Menu_larger = 100;
    static const int levelUpMenuSize = 3;
    static const int levelUpMenu_larger = 200;
    inline static const std::string levelUpMenuText[levelUpMenuSize] = {};
    inline static const std::string mainmenu[MainMenuSize] = {"Resume", "Quit", "Restart Game", "Restart Level"};
    inline static const std::string victoryMenu[victorySize] = {"You Won The Round","Next Level", "Quit"};
    inline static const std::string losemenu[loseSize] = {"You Lost The Round", "Restart Level", "Quit"};
    std::vector<PowerUp*> powerUps;


public:
    static bool isHasWindowOpen();
    static bool pause(Game &game);
    static void resume(Game &game);
    static void restart(Game &game);
    static void restartLevel(Game &game);
    static void quit(Game &game);
    static int victory(Game &game);
    void defeat(Game &game);
    void menu(Game &game);
    void play(Game &game);
    static int mainMenu(Game &game);
    static void generatePowerUp();


    static int gameOver(Game &game);

    static int levelUpMenu(Game &game);
};


#endif //UNTITLED3_MENUITEMS_H
