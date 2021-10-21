#include <rectangle.h>

Rectangle::Rectangle() : Rectangle(0.0f, 0.0f, 0.0f, 0.0f)
{
}

Rectangle::Rectangle(float x, float y, float width, float height)
    : m_x(x), m_y(y), m_width(width), m_height(height)
{
}

bool Rectangle::Intersects(const Rectangle& other)
{
    return (this->m_x < other.m_x + other.m_width) &&
        (this->m_x + this->m_width > other.m_x) &&
        (this->m_y < other.m_y + other.m_height) &&
        (this->m_y + this->m_height > other.m_y);
}

bool Rectangle::Contains(const Rectangle& other)
{
    return (other.m_x >= this->m_x) && (other.m_y >= this->m_y)
        && (other.m_x + other.m_width >= this->m_x)
        && (other.m_y <= this->m_y + this->m_height)
        && (other.m_x <= this->m_x + this->m_width)
        && (other.m_x + other.m_width <= this->m_x + this->m_width)
        && (other.m_y + other.m_height >= this->m_y)
        && (other.m_y + other.m_height <= this->m_y + this->m_height);
}

bool Rectangle::Contains(float x, float y)
{
    return 
        x > this->m_x && y > this->m_y &&
        x < this->m_x + this->m_width &&
        y < this->m_y + this->m_height;
}