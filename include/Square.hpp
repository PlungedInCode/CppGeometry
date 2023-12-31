#pragma once

#include "Rectangle.hpp"
#include "Circle.hpp"

class Square : public Rectangle {
public:
    Square(const Point& point1, const Point& point2);
    ~Square();

    Circle circumscribedCircle() const;
    Circle inscribedCircle() const;

    friend std::ostream& operator<<(std::ostream& out, const Rectangle& rect);

private:

};