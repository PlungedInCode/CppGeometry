#include "Point.hpp"

#include "Line.hpp"
#include "Vector.hpp"

using namespace Utils;

Point::Point(const double x, const double y) : x(x), y(y) {}

bool Point::operator==(const Point& other) const {
  return isEqual(x, other.x) && isEqual(y, other.y);
}

bool Point::operator!=(const Point& other) const { return !(*this == other); }

Point& Point::operator+=(const Point& rhs) {
  this->x += rhs.x;
  this->y += rhs.y;
  return *this;
}

Point operator+(Point lhs, const Point& rhs) {
  lhs += rhs;
  return lhs;
}

Point& Point::operator-=(const Point& rhs) {
  this->x -= rhs.x;
  this->y -= rhs.y;
  return *this;
}

Point operator-(Point lhs, const Point& rhs) {
  lhs -= rhs;
  return lhs;
}

Point& Point::operator*=(const double scalar) {
  this->x *= scalar;
  this->y *= scalar;
  return *this;
}

Point operator*(Point lhs, const double scalar) {
  lhs *= scalar;
  return lhs;
}

Point& Point::operator/=(const double scalar) {
  this->x /= scalar;
  this->y /= scalar;
  return *this;
}

Point operator/(Point lhs, const double scalar) {
  lhs /= scalar;
  return lhs;
}

void Point::reflect(const Line& line) {
  Point line1{0, line.getIntercept()};
  Vector s{1, line.getSlope()};
  double len = s.len();
  Vector f{line1, *this};
  double coef = 2 * f.vector_mult(s) /
                (len * sqrt(1 + line.getSlope() * line.getSlope()));
  this->x += (-line.getSlope()) * coef;
  this->y += coef;
}

void Point::reflex(const Point& center) {
  this->x = 2 * center.x - x;
  this->y = 2 * center.y - y;
}

void Point::rotate(const Point& center, double angle) {
  Point translated = *this - center;
  angle = Constants::PI * angle / 180;
  double rotatedX =
      translated.x * std::cos(angle) - translated.y * std::sin(angle);
  double rotatedY =
      translated.x * std::sin(angle) + translated.y * std::cos(angle);

  this->x = rotatedX + center.x;
  this->y = rotatedY + center.y;
}

void Point::scale(const Point& center, const double coefficient) {
  Point translated = *this - center;
  Point scaled = translated * coefficient;
  this->x = center.x + scaled.x;
  this->y = center.y + scaled.y;
}

double getDistance(const Point& p1, const Point& p2) {
  double xx = p2.x - p1.x;
  double yy = p2.y - p1.y;
  double distance = sqrt(xx * xx + yy * yy);
  return distance;
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
  out << "(" << point.x << ", " << point.y << ")";
  return out;
}