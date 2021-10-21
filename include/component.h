#pragma once
#include <memory>
#include <iostream>

class Component
{
public:
    virtual ~Component() = default;
    std::unique_ptr<Component> GetClone()  { return std::unique_ptr<Component>(MakeClone());}
    virtual void Display() =0;
protected:
    virtual Component* MakeClone() = 0;
};