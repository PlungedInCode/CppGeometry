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


    // Implement virtual methods from Shape class
    double perimeter() const override;
    double area() const override;
    bool operator==(const Shape& another) const override;
    bool isCongruentTo(const Shape& another) const override;
    bool isSimilarTo(const Shape& another) const override;
    bool containsPoint(const Point& point) const override;
    void rotate(const Point& center, double angle) override;
    void reflex(const Point& center) override;
    void reflex(const Line& axis) override;
    void scale(const Point& center, double coefficient) override;
private:

};