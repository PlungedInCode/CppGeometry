#pragma once

#include "Point.hpp"
#include "Ellipse.hpp"

class Circle : public Ellipse {
public:
    Circle(const Point& center, const double radius);
    ~Circle();

    double radius() const;

    //* Ellipse class methods
    std::pair<Point, Point> focuses() const override;
    std::pair<Line, Line> directrices() const override;
    double eccentricity() const override;
    Point center() const override;

    //* Shape class methods
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
    // Point center_;
    double radius_;
};