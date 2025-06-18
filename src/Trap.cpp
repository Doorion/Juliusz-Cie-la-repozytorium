#include "Trap.h"
#include <iostream>

Trap::Trap(int x_, int y_, bool active_) : x(x_), y(y_), active(active_) {
    if (!textureActive.loadFromFile("assets/pułapka_aktywna.png")) {
        std::cerr << "Błąd ładowania aktywnej pułapki!\n";
    }
    if (!textureInactive.loadFromFile("assets/pułapka_nieaktywna.png")) {
        std::cerr << "Błąd ładowania nieaktywnej pułapki!\n";
    }

    sprite.setTexture(active ? textureActive : textureInactive);
    sprite.setPosition(x * 32, y * 32);
}

bool Trap::isSolid() const {
    return false;
}

void Trap::update(float dt) {
    timer += dt;
    if (timer > 1.0f) {
        active = !active;
        sprite.setTexture(active ? textureActive : textureInactive);
        timer = 0.f;
    }
}

void Trap::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

bool Trap::isActive() const {
    return active;
}

std::string Trap::getSymbol() const {
    return active ? "a" : "x";
}
