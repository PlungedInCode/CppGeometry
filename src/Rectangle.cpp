#include "Rectangle.hpp"

Rectangle::Rectangle(const Point& point1, const Point& point2)
    : Polygon::Polygon(point1, Point(point2.x, point1.y), point2,
                       Point(point1.x, point2.y)) {}

Rectangle::~Rectangle(){};

Point Rectangle::center() const {
  auto vertices = Polygon::getVertices();
  double centerX = (vertices[0].x + vertices[2].x) / 2.0;
  double centerY = (vertices[0].y + vertices[2].y) / 2.0;
  return {centerX, centerY};
}

std::pair<Line, Line> Rectangle::diagonals() const {
  auto vertices = Polygon::getVertices();

  Line diag1 = Line(vertices[0], vertices[2]);
  Line diag2 = Line(vertices[1], vertices[3]);

  return std::make_pair(diag1, diag2);
}

std::ostream& operator<<(std::ostream& out, const Rectangle& rect) {
  out << "{";
  for (auto it : rect.getVertices()) {
    out << it << ", ";
  }
  out << "}";
  return out;
}