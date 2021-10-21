#include "../include/entity.h"
#include "../include/component.h"

Entity::Entity()
{
}

Entity::Entity(const Rectangle& rect)
{
    m_rectangle = rect;
}

Entity::Entity(const Entity& other)
{
    m_components.clear();
    for(const auto & c : other.m_components)
    {
         auto comp = c->GetClone();
         m_components.push_back(std::move(comp));
    }
}

Entity::~Entity()
{
    m_components.clear();
}

Entity & Entity::operator=(const Entity& other)
{
    m_components.clear();
    for(const auto & c : other.m_components)
    {
        auto comp = c->GetClone();
        m_components.push_back(std::move(comp));
    }
    return *this;
}