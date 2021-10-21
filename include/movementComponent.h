#pragma once
#include "component.h"


class MovementComponent : public Component
{
public:
    MovementComponent() = default;
    MovementComponent(float speed) : m_speed(speed){}
    virtual ~MovementComponent() = default;

    float GetSpeed() { return m_speed;}
    void SetSpeed(float speed) { m_speed = speed;}
    void Display() override  { std::cout << "speed points  " << m_speed << std::endl; }

protected:
    MovementComponent* MakeClone() override { return new MovementComponent(m_speed);}
private:
    float m_speed = 0;
};