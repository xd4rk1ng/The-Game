#pragma once
#include <raylib.h>

struct PhysicsProperties
{
    float mass = 0;
    float size = 100;
    Vector2 coordinates{20, 20};  
    Vector2 velocity{0, 0};     
    Vector2 acceleration{0, 0}; 
    int bearing = 0;            
    int rotationSpeed = 0;      
};