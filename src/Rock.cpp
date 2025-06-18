#include "Rock.h"
#include <iostream>

Rock::Rock(int x_, int y_) : x(x_), y(y_) {
    if (!texture.loadFromFile("assets/kamien.png")) {
        std::cerr << "Nie można załadować grafiki kamienia!\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(x * 32, y * 32);
}

bool Rock::isSolid() const {
    return true;
}

std::string Rock::getSymbol() const {
    return "R";
}

void Rock::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Rock::update(float /*dt*/) {
    // Kamień się nie rusza — nic nie robimy
}
