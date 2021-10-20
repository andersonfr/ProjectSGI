#include "../include/rectangle.h"

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(float x, float y, float width, float height)
    : m_x(x), m_y(y), m_width(width), m_height(height)
{
}

bool Rectangle::Intersects(const Rectangle& other)
{
    return this->m_x < other.m_x + other.m_width &&
        other.m_x < this->m_x + this->m_width &&
        this->m_y < other.m_y + other.m_height &&
        other.m_y < this->m_y + this->m_height;
}

