#ifndef INHERITANCE_CIRCLE_H
#define INHERITANCE_CIRCLE_H

#include "Figure.h"
#include <cmath>
#include <string>

class Circle : public Figure
{
private:
    float m_radius;
    float m_area;
    float m_perimeter;

public:
    Circle(std::string name = "", float radius = 0);
    virtual ~Circle() {}
    virtual float Area() const;
    virtual float Perimeter() const;
    virtual void Info() const;
};

#endif //INHERITANCE_CIRCLE_H
