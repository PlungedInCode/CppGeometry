#pragma once

#include "Rectangle.hpp"
#include "Circle.hpp"

class Square : public Rectangle {
public:
    Square(const Point& point1, const Point& point2);
    ~Square();

    Circle circumscribedCircle() const;
    Circle inscribedCircle() const;


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