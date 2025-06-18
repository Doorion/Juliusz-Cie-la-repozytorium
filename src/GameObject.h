#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class GameObject {
public:
    virtual std::string getSymbol() const = 0;
    virtual bool isSolid() const = 0;
    virtual void update(float dt) {}
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual ~GameObject() {}
};
