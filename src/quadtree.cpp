#include "../include/quadtree.h"
#include "../include/entity.h"

Quadtree::Quadtree(int cap, float x, float y, float width, float height) :
    Quadtree(cap, Rectangle ( x, y, width, height))
{
    m_isDivided = false;
}

Quadtree::Quadtree(int cap, const Rectangle& rec) : m_capacity(cap) , m_boundary(rec)
{
    m_isDivided = false;
}

Quadtree::~Quadtree()
{
    //std::cout << "destroyed" << std::endl;    
}

bool Quadtree::Insert(Entity* entity)
{
    if(!m_boundary.Intersects(entity->m_rectangle))
        return false;

    if (m_entities.size() < m_capacity && !m_isDivided)
    {
        m_entities.push_back(entity);
        return true;
    }
    
    if (!m_isDivided)
        Subdivide();
    
    if (m_ne->Insert(entity)) return true;
    if (m_nw->Insert(entity)) return true;
    if (m_se->Insert(entity)) return true;
    if (m_sw->Insert(entity)) return true;

    return false;
}

std::vector<Entity*> Quadtree::Search(Rectangle range)
{
    std::vector<Entity*> result;
   
    if(!m_boundary.Intersects(range))
        return result;
    
    for(const auto& e : m_entities)
    {
        if(range.Intersects(e->m_rectangle))
            result.push_back(e);
    }

    if(m_isDivided)
    {
        auto ne = m_ne->Search(range);
        result.insert(result.end(), ne.begin() , ne.end());
        auto nw = m_nw->Search(range);
        result.insert(result.end(), nw.begin(), nw.end());
        auto se = m_se->Search(range);
        result.insert(result.end(), se.begin(), se.end());
        auto sw = m_sw->Search(range);
        result.insert(result.end(), sw.begin(), sw.end());
    }
    
    return result;
}

void Quadtree::Subdivide()
{
    float width = this->m_boundary.m_width;
    float height = this->m_boundary.m_height;
    
    float x = this->m_boundary.m_x;
    float y = this->m_boundary.m_y;

    m_nw = std::make_unique<Quadtree>(this->m_capacity, x, y + height/2, width /2, height/2);
    m_ne = std::make_unique<Quadtree>(this->m_capacity, x + width/2, y + height/2, width/2 , height/2);
    m_sw = std::make_unique<Quadtree>(this->m_capacity,  x, y, width/2, height/2);
    m_se = std::make_unique<Quadtree>(this->m_capacity, x + width/2, y, width/2 , height/2);

    m_isDivided = true;
}

void Quadtree::Display(std::vector<Rectangle> & recs) 
{
    if (!m_isDivided) 
    {
        recs.push_back(m_boundary);
        return;
    }

    m_ne->Display(recs);
    m_nw->Display(recs);
    m_se->Display(recs);
    m_sw->Display(recs);
}