#include "Triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle(string name, float a, float b, float c) : Figure(name)
{
    m_a = a;
    m_b = b;
    m_c = c;
    m_perimeter = m_a + m_b + m_c;

    float s = m_perimeter / 2;
    m_area = sqrt(s * (s - m_a) * (s - m_b) * (s - m_c));
}

float Triangle::Area() const
{
    return m_area;
}

float Triangle::Perimeter() const
{
    return m_perimeter;
}

void Triangle::Info() const
{
    cout << "Triangle: " << Name() << endl;
    cout << "Sides: " << m_a << ", " << m_b << ", " << m_c << endl;
    cout << "Area: " << m_area << endl;
    cout << "Perimeter: " << m_perimeter << endl;
}
