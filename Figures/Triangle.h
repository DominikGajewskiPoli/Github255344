#ifndef INHERITANCE_TRIANGLE_H
#define INHERITANCE_TRIANGLE_H

#include "Figure.h"
#include <cmath>

class Triangle : public Figure
{
private:
    float m_a;
    float m_b;
    float m_c;
    float m_area;
    float m_perimeter;

public:
    Triangle(string name = "", float a = 0, float b = 0, float c = 0);
    virtual ~Triangle() {}
    virtual float Area() const;
    virtual float Perimeter() const;
    virtual void Info() const;
};

#endif //INHERITANCE_TRIANGLE_H
