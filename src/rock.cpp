#include "Rock.h"

Rock::Rock() {
    frames = { "R" }; 
}

bool Rock::isSolid() const {
    return true;
}
