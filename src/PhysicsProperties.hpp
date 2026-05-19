#include <raylib.h>

struct PhysicsProperties{
    float mass;
    float size;
    Vector2 coordinates; // m
    Vector2 speed; // m/s
    Vector2 acceleration; // m/s^2
    int bearing; // degrees
    int rotationSpeed; // degrees/s    
};