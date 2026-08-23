#pragma once
#include <unordered_map>
#include <raylib.h>
#include "PhysicsProperties.hpp"
#include "Atlas.hpp"

class PhysicsEntity
{
    static int s_count;

protected:
    PhysicsProperties m_props;
    const Atlas::SourceType m_source;

    PhysicsEntity(Atlas::SourceType source, PhysicsProperties props = {});
    virtual ~PhysicsEntity();

public:
    static int getCount();

    virtual void update(float deltaT);
    virtual void draw();
};
