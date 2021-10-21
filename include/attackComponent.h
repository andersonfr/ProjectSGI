#pragma once
#include "component.h"


class AttackComponent : public Component
{
public:
    AttackComponent(unsigned attackPower) : m_attackPower(attackPower){}
    virtual ~AttackComponent() = default;

    unsigned int GetAttackPower() { return m_attackPower;}
    void SetAttackPower(unsigned int attackPower) { m_attackPower = attackPower;}

    AttackComponent* MakeClone() override { return new AttackComponent(m_attackPower);}
private:
    unsigned int  m_attackPower = 0;
};