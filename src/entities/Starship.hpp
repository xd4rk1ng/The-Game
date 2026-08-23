#pragma once
#include <raylib.h>
#include "PhysicsEntity.hpp"

class Starship : public PhysicsEntity
{
private:
    Vector2 getThrustVector(float bearing, float thrust);

public:
    void update(float deltaT) override;

    Starship();
    ~Starship() override;
};
