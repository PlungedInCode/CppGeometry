#include "Vector.hpp"

Vector::Vector(const Point& p1, const Point& p2)
    : x{p2.x - p1.x}, y{p2.y - p1.y} {}

Vector::Vector(double x, double y) : x{x}, y{y} {}

double Vector::len() const { return sqrt(x * x + y * y); }

double Vector::vector_mult(const Vector& v) const { return x * v.y - y * v.x; }

double Vector::sc_mult(const Vector& v) const { return x * v.x + y * v.y; }

double Vector::area(const Vector& v) const {
  double area = x * v.y - y * v.x;
  return (area >= 0) ? area : -area;
}

Vector Vector::operator*(double koef) { return {x * koef, y * koef}; }

Vector& Vector::operator*=(double koef) {
  x /= koef;
  y /= koef;
  return *this;
}

bool Vector::operator==(const Vector& v) const {
  return Point(x, y) == Point(v.x, v.y);
}

void Vector::operator()(const Point& p1, const Point& p2) {
  x = p2.x - p1.x;
  y = p2.y - p1.y;
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
  out << "{" << v.x << ", " << v.y << "}";
  return out;
}
