#include "Starship.hpp"
#include "raymath.h"
#include "PhysicsEntity.hpp"
#include "Atlas.hpp"

#include <iostream>

static constexpr float ROTATION_SPEED = 200.0f;
static constexpr float THRUST_ACCELERATION = 100.0f;

Vector2 Starship::getThrustVector(float bearing, float thrust)
{
    return Vector2Scale({sinf(bearing * DEG2RAD),
                         -cosf(bearing * DEG2RAD)},
                        thrust);
}

void Starship::update(float deltaT)
{
    bool isThrusting = IsKeyDown(KEY_W) || IsKeyDown(KEY_UP) || IsKeyDown(KEY_SPACE);
    bool isRotatingRight = IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT);
    bool isRotatingLeft = IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT);
    if (isThrusting || isRotatingLeft || isRotatingRight)
        std::cout << "Updating Starship at" << deltaT << "ms since last frame..." << std::endl;

    m_props.velocity += isThrusting
                            ? getThrustVector(m_props.bearing, THRUST_ACCELERATION * deltaT) // TODO
                            : Vector2Zero();
    int rotationDirection = (int)(isRotatingRight - isRotatingLeft);
    m_props.rotationSpeed = ((float)rotationDirection) * ROTATION_SPEED;
    std::cout << m_props.rotationSpeed << std::endl;

    PhysicsEntity::update(deltaT);
}

Starship::Starship() : PhysicsEntity(Atlas::SourceType::SPACESHIP) {}

Starship::~Starship() {}