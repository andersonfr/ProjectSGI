#pragma once

#include <rectangle.h>
#include <component.h>
#include <healthComponent.h>
#include <vector>
#include <memory>
#include <set>

class Component;

class Entity 
{
public:
    Entity();
    Entity(float x, float y, float width, float height) : Entity(Rectangle(x,y,width,height)){}
    Entity(const Rectangle& rect);
    ~Entity();
    Entity(const Entity& other);
    Entity& operator=(const Entity& other);

public:
    template<class T>
    void AddComponent(T* component);
    
    template<class T>
    T* FindComponent();
    
    std::vector<std::unique_ptr<Component>> & GetComponents() { return m_components;} 
    void Display();

public:
    unsigned int m_id;
    Rectangle m_rectangle;
    std::set<int> m_intersecteds;
private:
    std::vector<std::unique_ptr<Component>> m_components;
};

template<class T>
void Entity::AddComponent(T* component)
{
    m_components.push_back(std::move(std::unique_ptr<T>(component)));
}

template<class T>
T* Entity::FindComponent()
{
    for(auto& c: m_components)
    {
        T* tc = dynamic_cast<T*>(c.get());
        if(tc != nullptr)
            return tc;
    }

    return nullptr;
}