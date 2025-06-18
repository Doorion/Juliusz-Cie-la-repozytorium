#include "Player.h"

Player::Player(int x, int y) : x_(x), y_(y), frameTime(0.1f), currentFrame(0) {
    try {
        loadTextures();
    } catch (const std::exception& e) {
        std::cerr << "Player initialization error: " << e.what() << std::endl;
        throw;
    }
    sprite.setPosition(x_ * 32.f, y_ * 32.f);
}

void Player::loadTextures() {
    if (!texture.loadFromFile("assets/player.png")) {
        throw std::runtime_error("Failed to load player texture");
    }
    sprite.setTexture(texture);
}

std::string Player::getSymbol() const {
    return "P";
}

bool Player::isSolid() const {
    return true;
}

void Player::update(float dt) {
    (void)dt; // Wyciszenie warningu o nieużywanym parametrze
    // Logika aktualizacji (np. animacja)
    frameTime -= dt;
    if (frameTime <= 0) {
        currentFrame = (currentFrame + 1) % 4;
        frameTime = 0.1f;
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::move(int dx, int dy) {
    x_ += dx;
    y_ += dy;
    sprite.setPosition(x_ * 32.f, y_ * 32.f);
}

int Player::getX() const {
    return x_;
}

int Player::getY() const {
    return y_;
}
