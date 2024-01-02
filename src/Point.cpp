#include "Point.hpp"

#include <iostream>

#include "Line.hpp"

Point::Point(const double x, const double y) : x(x), y(y) {}

bool Point::operator==(const Point& other) const {
  return x == other.x && y == other.y;
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

void Point::reflex(const Line& axis) {
  double x0 = x, y0 = y;
  double slope = axis.getSlope(), intercept = axis.getIntercept();

  double x1 = slope * (slope * x0 + y0 - intercept) / (1 + slope * slope);
  double y1 = slope * x1 + intercept;

  x = 2 * x1 - x0;
  y = 2 * y1 - y0;
}

void Point::reflex(const Point& center) {
  x = 2 * center.x - x;
  y = 2 * center.y - y;
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

std::ostream& operator<<(std::ostream& out, const Point& point) {
  out << "(" << point.x << ", " << point.y << ")";
  return out;
}

double getDistance(const Point& p1, const Point& p2) {
  double xx = p2.x - p1.x;
  double yy = p2.y - p1.y;
  double distance = sqrt(xx * xx + yy * yy);
  return distance;
}

bool Point::operator<(const Point& other) const {
  double len1 = this->x * this->x + this->y * this->y;
  double len2 = other.x * other.x + other.y * other.y;
  return len1 < len2;
}