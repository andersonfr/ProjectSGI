#pragma once
#include <rectangle.h>
#include <memory>
#include <vector>


class Entity;

class Quadtree
{
public:
    Quadtree() : m_capacity(0), m_isDivided(false){}
    Quadtree(int cap, float x, float y, float width, float height);
    Quadtree(int cap, const Rectangle& rec);
    ~Quadtree();

public:
    bool Insert(Entity* entity);
    std::vector<Entity*> Search(Rectangle region); 
    void Display(std::vector<Rectangle>& recs);
private:
    void Subdivide();

private:
    int m_capacity;
    bool m_isDivided;
    Rectangle m_boundary;
    std::vector<Entity*> m_entities;

    std::unique_ptr<Quadtree> m_ne = nullptr;
    std::unique_ptr<Quadtree> m_nw = nullptr;
    std::unique_ptr<Quadtree> m_se = nullptr;
    std::unique_ptr<Quadtree> m_sw = nullptr;

};