#pragma once
#include "component.h"


class HealthComponent : public Component
{
public:
    HealthComponent() = default;
    HealthComponent(int health) : m_health(health){}
    virtual ~HealthComponent() = default;
   
    int GetHealth() { return m_health; }
    void SetHealth(int health) { m_health = health;}
    void Display() override  { std::cout << "Health points  " << m_health << std::endl; }
    
protected:
    HealthComponent* MakeClone() override { return new HealthComponent(m_health);}
private:
    int m_health = 0;
};
