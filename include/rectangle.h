#pragma once

class Rectangle
{
    public:
        Rectangle();
        Rectangle(float x, float y, float width, float height);
        Rectangle(const Rectangle& other) = default;
        ~Rectangle() = default;
    public:
        bool Intersects(const Rectangle& other);
        bool Contains(const Rectangle& other);
        bool Contains(float x, float y);
    public:
        float m_x;
        float m_y;
        float m_width;
        float m_height;
};