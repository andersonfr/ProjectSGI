#pragma once
#include "component.h"


class MovementComponent : public Component
{
public:
    MovementComponent(float speed) : m_speed(speed){}
    virtual ~MovementComponent() = default;

    float GetSpeed() { return m_speed;}
    void SetSpeed(float speed) { m_speed = speed;}

    MovementComponent* MakeClone() override { return new MovementComponent(m_speed);}
private:
    float m_speed = 0;
};