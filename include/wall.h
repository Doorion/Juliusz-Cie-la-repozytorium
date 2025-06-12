#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Wall : public GameObject {
public:
    Wall(int x, int y);

    bool isSolid() const override;
    void draw(sf::RenderWindow& window) const override;

private:
    sf::Texture texture;
    sf::Sprite sprite;
};
