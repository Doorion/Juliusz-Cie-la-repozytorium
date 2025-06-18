#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Key : public GameObject {
public:
    Key(int x, int y);
    bool isSolid() const override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;
    std::string getSymbol() const override;
    
private:
    int x, y;
    sf::Texture texture;
    sf::Sprite sprite;
};
