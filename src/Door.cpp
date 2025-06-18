#include "Door.h"
#include <iostream>

Door::Door(int x_, int y_) : x(x_), y(y_) {
    if (!texture.loadFromFile("assets/drzwi.png")) {
        std::cerr << "Nie można załadować drzwi: assets/drzwi.png\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(x * 32, y * 32);
}

bool Door::isSolid() const {
    return true;
}

void Door::update(float /*dt*/) {}

void Door::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

std::string Door::getSymbol() const {
    return "D";
}
