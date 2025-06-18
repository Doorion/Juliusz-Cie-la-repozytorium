#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Rock : public GameObject {
public:
    Rock(int x, int y);
    bool isSolid() const override;
    std::string getSymbol() const override;
    void draw(sf::RenderWindow& window) override;
    void update(float dt) override;

private:
    int x, y;
    sf::Texture texture;
    sf::Sprite sprite;
};
