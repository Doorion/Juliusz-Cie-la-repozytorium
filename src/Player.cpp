#include "Player.h"
#include <iostream>

Player::Player(int x_, int y_) : x(x_), y(y_) {
    loadTextures();
    if (!textures.empty()) {
        sprite.setTexture(textures[0]);
    }
    sprite.setPosition(x * 32, y * 32); // Zakładamy kafelek 32x32
}

void Player::loadTextures() {
    std::vector<std::string> files = {
        "assets/gracz_lewo1.png",
        "assets/gracz_lewo2.png"
    };

    for (const auto& file : files) {
        sf::Texture texture;
        if (!texture.loadFromFile(file)) {
            std::cerr << "Błąd ładowania pliku: " << file << "\n";
        } else {
            textures.push_back(texture);
        }
    }
}

bool Player::isSolid() const {
    return false;
}

std::string Player::getSymbol() const {
    return "P";
}

void Player::move(int dx, int dy) {
    x += dx;
    y += dy;
    sprite.setPosition(x * 32, y * 32);
}

int Player::getX() const { return x; }
int Player::getY() const { return y; }

void Player::update(float dt) {
    timeSinceLastFrame += dt;
    if (timeSinceLastFrame >= frameTime && !textures.empty()) {
        timeSinceLastFrame = 0.0f;
        currentFrame = (currentFrame + 1) % textures.size();
        sprite.setTexture(textures[currentFrame]);
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
