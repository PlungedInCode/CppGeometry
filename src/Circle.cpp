#include "Circle.hpp"

Circle::Circle(const Point& center, double radius)
    : Ellipse(center, center, 2 * radius), radius_(radius) {}

Circle::~Circle() {}

//* Additional method specific to Circle
double Circle::radius() const { return radius_; }


//* Virtual methods from Shape class
double Circle::perimeter() const { return 2 * Constants::PI * radius_; }

double Circle::area() const { return Constants::PI * radius_ * radius_; }

void Circle::scale(const Point& center, double coefficient) {
    radius_ *= coefficient;
    Ellipse::scale(center, coefficient);
}

std::ostream& operator<<(std::ostream& out, const Circle& circle) {
  out << "{" << circle.center() << ", r = " << circle.radius() << "}" << std::endl;
  return out;
}