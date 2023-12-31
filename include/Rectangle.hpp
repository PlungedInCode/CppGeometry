#pragma once

#include "Point.hpp"
#include "Polygon.hpp"

class Rectangle : public Polygon {
public:
    Rectangle(const Point& point1, const Point& point2);
    // Rectangle(const double coefficient);
    virtual ~Rectangle();

    Point center() const;
    std::pair<Line, Line> diagonals() const;

    friend std::ostream& operator<<(std::ostream& out, const Rectangle& rect);

private:

};