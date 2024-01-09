#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Spelaren//Player.h"
#include "Keys.h"
#include "Vapen/Weapon.h"

#include "CollisionDetector.h"
#include "MenuItems.h"
#include "Game.h"
/*
using namespace std;
bool gameIsRunning = true;
EnemySpawner enemySpawner = EnemySpawner();
sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Application");
Player player = Player(window);
Weapon weapon = Weapon(1000, 10, 1000, 150, 15);
sf::Text text;



int roundNR = 1;

void drawGameObjects(sf::RenderWindow& window, Player& player, EnemySpawner& enemySpawner) {
    text.setString("Round: " + to_string(roundNR));
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(100, 100);
    window.clear();
    player.draw(window);
    enemySpawner.drawEnemies(window);
    player.getWeapon().drawBullets(window);
    window.display();
}
static void setPlayerWeapon(){
    player.setWeapon(weapon);
}



void handleEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void handleInput(sf::RenderWindow& window, Player& player, bool &gameIsRunning, int round) {
    Keys keys = Keys();
    //keys.handleInput(window, player, gameIsRunning, round);
}


static void nextRound(){
    roundNR++;
    enemySpawner.removeEnemies();
    enemySpawner.spawnEnemies(window, roundNR);
}
static void checkVictory(EnemySpawner(&enemySpawner), sf::RenderWindow& window) {
    if (enemySpawner.getEnemies().empty()) {
        //MenuItems::victory(window, gameIsRunning, roundNR);
        cout << "You won the round" << endl;
        nextRound();
    }
}
static void restartLevel(){
    enemySpawner.removeEnemies();
    enemySpawner.spawnEnemies(window, roundNR);
}

void updateGameObjects(sf::RenderWindow& window, Player& player, EnemySpawner& enemySpawner) {
    player.getWeapon().updateBullets(window);
    if (enemySpawner.updateEnemies(window)){// if this returns true that means an enemy has made it all the way down
        gameIsRunning = false;
        MenuItems::gameOver(window, gameIsRunning, roundNR);
        cout << "You lost the round" << endl;
        restartLevel();
    }

}
static void startGame(){

    player.setWeapon(weapon);
    enemySpawner.spawnEnemies(window, roundNR);
    gameIsRunning = true;
}



int main() {
    startGame();
    window.setFramerateLimit(120);
    while (window.isOpen()) {
        checkVictory(enemySpawner, window);
        handleInput(window, player, gameIsRunning, roundNR);
        handleEvents(window);
        if (gameIsRunning){
            drawGameObjects(window, player, enemySpawner);
            checkVictory(enemySpawner, window);
            updateGameObjects(window, player, enemySpawner);
            CollisionDetector::collisionDetection(player.getWeapon(), enemySpawner);
        }
    }
}
*/

int main(){
    Game game = Game();
    game.startGame();
    return 0;

}
 /*
void static setGameIsRunning(bool &gameIsRunning) {
    gameIsRunning = gameIsRunning;
}

*/

