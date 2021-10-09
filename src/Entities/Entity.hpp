#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"

class Entity
{
private:
    Rectangle collider;

public:
    Entity(/* args */);
    ~Entity();
};

#endif