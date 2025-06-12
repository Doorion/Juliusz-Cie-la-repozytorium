#include "Wall.h"

Wall::Wall() {
    frames = { "#" }; 
}

bool Wall::isSolid() const {
    return true;
}
