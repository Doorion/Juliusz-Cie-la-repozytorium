#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Trap : public GameObject {
public:
    Trap(int x, int y, bool active);
    bool isSolid() const override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;
    std::string getSymbol() const override;

    bool isActive() const;

private:
    int x, y;
    bool active;
    float timer = 0.f;
    sf::Texture textureActive;
    sf::Texture textureInactive;
    sf::Sprite sprite;
};
