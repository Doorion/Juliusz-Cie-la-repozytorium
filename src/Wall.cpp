#include "Wall.h"
#include <iostream>

Wall::Wall(int x_, int y_) : x(x_), y(y_) {
    if (!texture.loadFromFile("assets/wall.png")) {
        std::cerr << "Nie można załadować tekstury wall.png\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(x * 32, y * 32);
}

bool Wall::isSolid() const { return true; }

void Wall::update(float /*dt*/) {}

void Wall::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

std::string Wall::getSymbol() const {
    return "#";
}
