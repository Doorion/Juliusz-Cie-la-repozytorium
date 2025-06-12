#pragma once
#include "Object.h"

class Player : public Object {
public:
    Player();
    std::string getType() const override;
    void update(float deltaTime) override;

    void move(float dx, float dy);
    float getX() const;
    float getY() const;

private:
    float x, y; // pozycja gracza
    float speed; // prędkość w pikselach/sekundę
};
