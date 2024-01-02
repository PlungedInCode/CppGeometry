#include "Square.hpp"

Square::Square(const Point& point1, const Point& point2)
    : Rectangle::Rectangle(point1, point2) {}

Square::~Square() {}

Circle Square::circumscribedCircle() const {
  Point center = Rectangle::center();
  auto vertices = Rectangle::getVertices();
  double radius = std::abs(getDistance(vertices[0], vertices[2])) / 2;
  return Circle(center, radius);
}

Circle Square::inscribedCircle() const {
  Point center = Rectangle::center();
  auto vertices = Rectangle::getVertices();
  double radius = std::abs(getDistance(vertices[0], vertices[1])) / 2;
  return Circle(center, radius);
}