#include "Player.h"
#include <iostream>

Player::Player() : x(0), y(0), speed(100.0f) {}

std::string Player::getType() const {
    return "Player";
}

void Player::update(float deltaTime) {
    // Przykład "animacji": automatyczne przesuwanie się gracza w prawo
    x += speed * deltaTime;
    std::cout << "Pozycja gracza: (" << x << ", " << y << ")\n";
}

void Player::move(float dx, float dy) {
    x += dx;
    y += dy;
}

float Player::getX() const { return x; }
float Player::getY() const { return y; }
