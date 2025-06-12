#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Player : public GameObject {
public:
    Player(int x, int y);

    bool isSolid() const override;
    std::string getSymbol() const override;

    void move(int dx, int dy);
    int getX() const;
    int getY() const;

    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    int x, y;
    float timeSinceLastFrame = 0.0f;
    float frameTime = 0.2f;
    int currentFrame = 0;

    std::vector<sf::Texture> textures;
    sf::Sprite sprite;

    void loadTextures();
};
