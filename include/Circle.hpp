#pragma once

#include "Point.hpp"
#include "Ellipse.hpp"
#include "Constants.hpp"

class Circle : public Ellipse {
public:
    Circle(const Point& center, const double radius);
    ~Circle();

    double radius() const;

    //* Shape class methods
    double perimeter() const override;
    double area() const override;
    void scale(const Point& center, double coefficient) override;

    friend std::ostream& operator<<(std::ostream& out, const Circle& circle);

private:
    double radius_;
};