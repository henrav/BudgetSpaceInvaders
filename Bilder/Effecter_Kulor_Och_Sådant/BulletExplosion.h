//
// Created by Henrik Ravnborg on 2023-11-30.
//

#ifndef UNTITLED3_BULLETEXPLOSION_H
#define UNTITLED3_BULLETEXPLOSION_H


#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class BulletExplosion {
private:
    sf::Clock clock;
    std::vector<sf::Texture*> textures;
    std::vector<sf::Sprite*> sprites;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect rect;
    float sizeX = 0;
    float sizeY = 0;
    float posX = 0;
    float posY = 0;

public:

    void setSize(float sizeX, float sizeY);
    void setPos(float posX, float posY);
    void setTexture(sf::Texture &texture);
    void setSprite(sf::Sprite &sprite);
    void setRect(sf::IntRect &rect);
    void draw(sf::RenderWindow &window);
    void update();
    void loadTexture();
    void setSpriteTexture();
    void setSpriteRect();
    void setSpritePos();
    sf::Clock &getClock();

    BulletExplosion(float posX, float posY);
    BulletExplosion();

};


#endif //UNTITLED3_BULLETEXPLOSION_H
