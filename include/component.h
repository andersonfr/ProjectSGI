#pragma once
#include <memory>
#include <iostream>

class Component
{
public:
    virtual ~Component() = default;
    std::unique_ptr<Component> GetClone()  { return std::unique_ptr<Component>(MakeClone());}
public:
    virtual Component* MakeClone() = 0;

};