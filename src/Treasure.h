#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Treasure : public GameObject {
    std::string symbol;
    bool solid;
    sf::Sprite sprite;
    int posX, posY;  // Dodajemy pozycję

public:
    // Dodajemy konstruktor z parametrami x,y
    Treasure(int x, int y);

    std::string getSymbol() const override;
    bool isSolid() const override;
    void draw(sf::RenderWindow& window) override;
    void update(float dt) override;
};
