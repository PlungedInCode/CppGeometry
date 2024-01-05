#include "Circle.hpp"

Circle::Circle(const Point& center, double radius)
    : Ellipse(center, center, 2 * radius) {}

Circle::~Circle() {}

double Circle::radius() const { return length_ / 2; }

std::ostream& operator<<(std::ostream& out, const Circle& circle) {
  out << "{" << circle.center() << ", r = " << circle.radius() << "}";
  return out;
}