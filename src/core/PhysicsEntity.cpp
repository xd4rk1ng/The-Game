#include "PhysicsEntity.hpp"
#include <raymath.h>
#include <iostream>

int PhysicsEntity::s_count = 0;

PhysicsEntity::PhysicsEntity(Atlas::SourceType source, PhysicsProperties props) : m_source(source),
                                                                                  m_props(props)
{
    s_count++;
    std::cout << "Entity loaded!" << std::endl;
    std::cout << "Physics Entities loaded: " << PhysicsEntity::getCount() << ' ' << std::endl;
}

PhysicsEntity::~PhysicsEntity()
{
    s_count--;
    std::cout << "Entity unloaded!" << std::endl;
    std::cout << "Physics Entities loaded: " << PhysicsEntity::getCount() << ' ' << std::endl;
}

int PhysicsEntity::getCount() { return s_count; }

void PhysicsEntity::update(float deltaT)
{
    m_props.velocity = Vector2Add(m_props.velocity, m_props.acceleration * deltaT);
    m_props.coordinates = Vector2Add(m_props.coordinates, m_props.velocity * deltaT);

    m_props.bearing += (float)m_props.rotationSpeed * deltaT;
}

void PhysicsEntity::draw()
{
    Rectangle destinationRectangle{m_props.coordinates.x, m_props.coordinates.y,
                                   m_props.size, m_props.size};
    Vector2 entityCenter{m_props.size / 2, m_props.size / 2};

    DrawTexturePro(Atlas::instance()->getTexture(),
                   Atlas::getSourceRectangle(m_source),
                   destinationRectangle,
                   entityCenter, m_props.bearing, WHITE);
}
