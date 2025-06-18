#include "Key.h"
#include <iostream>

Key::Key(int x_, int y_) : x(x_), y(y_) {
    if (!texture.loadFromFile("assets/klucz.png")) {
        std::cerr << "Nie można załadować grafiki klucza!\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(x * 32, y * 32);
}

bool Key::isSolid() const {
    return false;
}

void Key::update(float /*dt*/) {
}

void Key::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

std::string Key::getSymbol() const {
    return "K";
}
