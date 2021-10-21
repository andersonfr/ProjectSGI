#include <iostream>
#include "../include/rectangle.h"
#include "../include/entity.h"
#include "../include/healthComponent.h"
#include "../include/movementComponent.h"
#include "../include/attackComponent.h"

int main(int argc, char** argv)
{
    Rectangle a {5.0f, 10.0f,5.0f, 10.0f};
    Rectangle b {8.0f, 8.0f,8.0f, 8.0f};
    Entity e {a};
    Entity c {b};

    c.AddComponent<HealthComponent>(new HealthComponent(120));
    c.AddComponent<AttackComponent>(new AttackComponent(1200));
    c.AddComponent<MovementComponent>(new MovementComponent(50.0f));
    
    e = c;

    auto cac = e.FindComponent<AttackComponent>();
    cac->SetAttackPower(900);
    std::cout<< "Copy of attack power "<< cac->GetAttackPower() << std::endl;

    for(const auto& cp : c.GetComponents())
    {
        auto hc = dynamic_cast<HealthComponent*>(cp.get());
        if(hc)
            std::cout<< "health points : " << hc-> GetHealth() << std::endl;
        auto ac = dynamic_cast<AttackComponent*>(cp.get());
        if(ac)
            std::cout<< "Attack Power  : " << ac-> GetAttackPower() << std::endl;
        
        auto mc = dynamic_cast<MovementComponent*>(cp.get());
        if(mc)
            std::cout<< "Speed value  : " << mc-> GetSpeed() << std::endl;
    }

    

    // if(e.m_rectangle.Intersects(c.m_rectangle))
    //     std::cout<<"Intersects"<<std::endl;  
    // else
    //     std::cout<<"Not Intersects"<<std::endl;
    return 0;
}