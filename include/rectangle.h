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

    public:
        float m_x;
        float m_y;
        float m_width;
        float m_height;
};