#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream> // Dodane dla std::cerr

class Player : public GameObject {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    int x_;
    int y_;
    float frameTime;
    int currentFrame;

public:
    Player(int x, int y);
    ~Player() override = default;

    // Metody z GameObject
    std::string getSymbol() const override;
    bool isSolid() const override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

    // Własne metody
    void move(int dx, int dy);
    int getX() const;
    int getY() const;

private:
    void loadTextures();
};
