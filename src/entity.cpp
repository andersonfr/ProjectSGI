#include <entity.h>
#include <component.h>

Entity::Entity()
{
    m_id = 0;
}

Entity::Entity(const Rectangle& rect)
{
    m_id = 0;
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

void Entity::Display()
{
    std::cout << "Entity pos (" << m_rectangle.m_x << ","<<m_rectangle.m_y << ")" << std::endl;

    for(const auto& cp : GetComponents())
    {
        cp->Display();
    }
}