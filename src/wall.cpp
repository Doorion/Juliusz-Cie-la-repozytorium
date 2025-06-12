#include "Wall.h"

Wall::Wall(int x, int y) {
    texture.loadFromFile("assets/Wall.png");
    sprite.setTexture(texture);
    sprite.setPosition(static_cast<float>(x * 20), static_cast<float>(y * 20)); // 20 = rozmiar kafelka
}

bool Wall::isSolid() const {
    return true;
}

void Wall::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}
