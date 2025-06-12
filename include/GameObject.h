#pragma once
#include <string>


class GameObject {
public:
    virtual std::string getSymbol() const = 0;   
    virtual bool isSolid() const = 0;            
    virtual void update(float dt) {}             
    virtual ~GameObject() {}                      
};
