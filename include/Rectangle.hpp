#pragma once

#include "Point.hpp"
#include "Polygon.hpp"

class Rectangle : public Polygon {
public:
    Rectangle(const Point& point1, const Point& point2);
    Rectangle(const Point& point1, const Point& point2, int ratio);
    std::vector<Point> chooseVerticesOrder(const Point& point1, const Point& point2, int ratio) const;
    virtual ~Rectangle();

    Point center() const;
    std::pair<Line, Line> diagonals() const;

    // bool operator==(const Shape& other) const override;

    friend std::ostream& operator<<(std::ostream& out, const Rectangle& rect);

private:

};