#pragma once
#include <string>

class Object {
public:
    virtual ~Object() {}
    virtual std::string getType() const = 0;
    virtual void update(float deltaTime) = 0;
};
