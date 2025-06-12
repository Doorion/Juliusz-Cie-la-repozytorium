#include "Player.h"

Player::Player(int x_, int y_) : x(x_), y(y_) {
    frames = { "P", "p" }; // animacja chodzenia: klatki
    frameTime = 0.3f;      // co ile sekund zmieniać
}

bool Player::isSolid() const {
    return false; // Gracz nie blokuje innych obiektów
}

void Player::move(int dx, int dy) {
    x += dx;
    y += dy;
}

int Player::getX() const { return x; }
int Player::getY() const { return y; }
