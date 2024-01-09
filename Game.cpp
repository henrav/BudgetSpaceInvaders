//
// Created by Henrik Ravnborg on 2023-11-17.
//
#include "Game.h"
#include "EnemySpawner.h"


using namespace std;
static sf::Font font;

Game::Game()
        : window(sf::VideoMode(1920, 1080), "SFML Application"), player(window)
        ,roundNR(1), gameIsRunning(true), playerLevel(1){
    loadBackground();
}




void Game::drawGameObjects() {
    window.clear();
    window.draw(backgroundSprite);
    drawText();
    window.draw(text);
    player.draw(window);
    ExplosionListy::drawAndUpdate(window);
    EnemySpawner::drawEnemies(window);
    player.getWeapon().drawBullets(window);
    EnemyVapen::drawBullets(window);
    XpSpawner::drawXP(window);
    window.display();
}

void Game::drawText(){
    sf::Text text;
    text.setFont(font);
    text.setString("Round: " + to_string(roundNR));
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(100, 100);
    window.draw(text);
}

void Game::handleEvents() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed){
            window.close();
        }

    }
}

void Game::nextRound() {
    roundWon = false;
    gameIsRunning = true;
    roundNR++;
    cout << roundNR << endl;
    EnemySpawner::removeEnemies();
    player.getWeapon().clearBullets();
    EnemySpawner::spawnEnemies(*this);
    XpSpawner::clearXPList();
}

void Game::checkVictory() {
    if (EnemySpawner::getEnemies().empty()) {
        roundWon = true;
    }
}
void Game::restartLevel() {
    gameIsRunning = true;
    EnemySpawner::removeEnemies();
    EnemySpawner::spawnEnemies(*this);
    XpSpawner::clearXPList();
    player.getWeapon().clearBullets();
}


void Game::updateGameObjects() {
    player.getWeapon().updateBullets();
    EnemyVapen::updateBullets();
    XpSpawner::moveXP(player);
    checkPlayerEdge();
    if (EnemySpawner::updateEnemies(window, *this)) {
        MenuItems::gameOver(*this);
        std::cout << "You lost the round" << std::endl;
        restartLevel();
    }
}
void Game::enableCheats(){
    cout << "Cheats enabled" << endl;
    Player::addExtraDmg(1000);
    Player::addExtraFireRate(1000);
    Player::addExtraBulletSpeed(30);
}

void Game::startGame() {
    font.loadFromFile("/System/Library/Fonts/Supplemental/Arial Unicode.ttf");
    roundNR = 1;
    EnemySpawner::spawnEnemies(*this);
    gameIsRunning = true;
    XpSpawner::clearXPList();
    player.getWeapon().clearBullets();
    //enableCheats();
    run();
}
void Game::nextRoundVersion2DontUse(){
    run();
}





void Game::run() {
    std::chrono::steady_clock::time_point roundStart = std::chrono::steady_clock::now();
    double accumilatedFPS = 0;
    double totalFrames = 0;
    double totalTimes = 0;
    sf::Thread drawThread(&Game::drawGameObjects, this);
    while (window.isOpen()) {
        if (clock.getElapsedTime().asSeconds() > 1.0 / 128.0) {
            drawThread.launch();
            drawThread.wait();
            Keys::handleInput(*this);
            handleEvents();
            if (gameIsRunning && !roundWon){
                updateGameObjects();
                checkVictory();
                CollisionDetector::collisionDetection(*this);
                CollisionDetector::collisionDetectionEnemyBullets(*this);
            }
            if (gameIsRunning && roundWon) {
                moveXpToHeroAfterWin();
            }
            if (levelUpMenuOpen){
                Keys::handleInput(*this);
                handleEvents();
                MenuItems::levelUpMenu(*this);
            }
            clock.restart();
        }
    }

}



void Game::restartGame() {
    gameIsRunning = true;
    roundNR = 1;
    EnemySpawner::removeEnemies();
    startGame();
}

void Game::moveXpToHeroAfterWin() {
    XP::setRealSpeed(10);
    drawGameObjects();
    player.getWeapon().updateBullets();
    XpSpawner::moveXP(player);
    hasPlayerLevelUp();
    if (XpSpawner::getXPList().empty() && levelUp){
        levelUpMenuOpen = true;
        gameIsRunning = false;
        roundWon = false;
    }
    hasPlayerLevelUp();
    if (XpSpawner::getXPList().empty() && !levelUp){
        XP::setRealSpeed(5);
        MenuItems::victory(*this);
    }
}

void Game::hasPlayerLevelUp() {
   if (player.getLevel() == playerLevel) {
            levelUp = false;
        }
        else {
       levelUp = true;
   }
}

bool Game::getWonRound() {
    return roundWon;
}

void Game::wonRoundAnimation() {

}



bool Game::isLevelUp() {
    return levelUp;
}

int &Game::getPlayerLevel() {
    return playerLevel;
}


Player &Game::getPlayer() {
    return player;
}



sf::Text &Game::getText() {
    return text;
}

int Game::getRoundNr() {
    return roundNR;
}

bool Game::isGameIsRunning() {
    return gameIsRunning;
}

bool Game::isRoundWon()  {
    return roundWon;
}

sf::RenderWindow &Game::getWindow() {
    return window;
}

void Game::setGameIsRunning(bool gameIsRunning) {
    Game::gameIsRunning = gameIsRunning;
}

void Game::setRoundWon(bool roundWon) {
    Game::roundWon = roundWon;
}

void Game::setLevelUp(bool levelUp) {
    Game::levelUp = levelUp;
}

void Game::setPlayerLevel(int playerLevel) {
    Game::playerLevel = playerLevel;
}

void Game::setPlayer(Player &player) {
    Game::player = player;
}



void Game::setText(sf::Text &text) {
    Game::text = text;
}

void Game::setRoundNr(int roundNr) {
    roundNR = roundNr;
}

void Game::increasePlayerLevel() {
    playerLevel++;
}

bool Game::getHasClickedLevelUp() {
    return hasClickedLevelUp;
}

void Game::setHasClickedLevelUp(bool hasClickedLevelUp) {
    Game::hasClickedLevelUp = hasClickedLevelUp;
}

bool Game::getHasMenuOpen() {
    return hasMenuOpen;
}

void Game::setHasMenuOpen(bool hasMenuOpen) {
    Game::hasMenuOpen = hasMenuOpen;
}

void Game::setGameWindowIsOpen(bool gameWindowIsOpen) {
    Game::gameWindowIsOpen = gameWindowIsOpen;

}

bool Game::getGameWindowIsOpen() {
    return gameWindowIsOpen;
}

void Game::checkPlayerEdge() {
    if (player.getShapePos().getPosition().x < 0) {
        player.setPosition(0, player.getShapePos().getPosition().y);
    }
    if (player.getShapePos().getPosition().x > window.getSize().x - player.getShapePos().getSize().x) {
        player.setPosition(window.getSize().x - player.getShapePos().getSize().x, player.getShapePos().getPosition().y);
    }
    if (player.getShapePos().getPosition().y < 0) {
        player.setPosition(player.getShapePos().getPosition().x, 0);
    }
    if (player.getShapePos().getPosition().y > window.getSize().y - player.getShapePos().getSize().y - player.getShapePos().getLocalBounds().height) {
        player.setPosition(player.getShapePos().getPosition().x, window.getSize().y - player.getShapePos().getSize().y -player.getShapePos().getLocalBounds().height);
    }

}

void Game::loadBackground() {
    backgroundRect.height = window.getSize().y;
    backgroundRect.width = window.getSize().x;
    if (!backgroundTexture.loadFromFile("/Users/henrikravnborg/CLionProjects/untitled3/Bilder/BakgrundsbildBlå.png", backgroundRect)) {
        cout << "Error loading background texture" << endl;
    }
    backgroundSprite.setTexture(backgroundTexture);
    float scaleX = window.getSize().x / backgroundSprite.getLocalBounds().width;
    float scaleY = window.getSize().y / backgroundSprite.getLocalBounds().height;
    backgroundSprite.setScale(scaleX, scaleY);
    backgroundSprite.setPosition(0, 0);
}

void Game::drawBackground() {
    window.draw(backgroundSprite);

}

sf::Sprite & Game::getBackgroundSprite() {
    return backgroundSprite;
}

void Game::setPaused(bool pause) {
    this->paused = pause;
}

bool Game::getPaused() {
    return paused;
}

void Game::setLevelUpMenuOpen(bool levelUpMenuOpen) {
    Game::levelUpMenuOpen = levelUpMenuOpen;

}

bool Game::getLevelUpMenuOpen() {
    return false;
}

void Game::isPlayerDoneLeveling() {
    if (player.getLevel() == playerLevel) {
        levelUp = false;
        levelUpMenuOpen = false;
        XP::setRealSpeed(5);
        MenuItems::victory(*this);
    }
    else {
        levelUp = true;
    }

}

bool Game::getLevelUp() {
    return levelUp;
}

void Game::generateNewPowerUp() {
    powerUpList.clear();
    for (int i = 0; i <= 4; i++) {
        powerUpList.push_back(PowerUpGenerator::generatePowerUp(player.getLevel()));
    }

}

std::vector<PowerUp *> &Game::getPowerUpList() {
    return powerUpList;
}

double Game::nrOfLVL1Enemies(int roundNr) {

}







