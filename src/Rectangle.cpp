#include "Rectangle.hpp"

Rectangle::Rectangle(const Point& first, const Point& second, double coef)
    : Polygon() {
  vertices_.push_back(first);
  Vector diag{first, second};
  double cos = 1 / sqrt(coef * coef + 1);
  double sin = sqrt(1 - cos * cos);
  double new_x =
      (second.x - first.x) * cos - (second.y - first.y) * sin + first.x;
  double new_y =
      (second.x - first.x) * sin + (second.y - first.y) * cos + first.y;
  Vector v{first, Point(new_x, new_y)};
  double sc = v.len() / diag.len();
  if (coef < 1) {
    sc *= coef;
  }
  vertices_.emplace_back(first.x + v.x * sc, first.y + v.y * sc);
  vertices_.push_back(second);
  vertices_.emplace_back(second.x - v.x * sc, second.y - v.y * sc);
}
Rectangle::Rectangle(const Point& first, const Point& second, int coef)
    : Rectangle(first, second, static_cast<double>(coef)) {}
Rectangle::Rectangle(const std::vector<Point>& points) : Polygon(points) {}

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
  bool flag = false;
  out << "{";
  for (auto it : rect.getVertices()) {
    if (flag) out << ", ";
    out << it;
    if (!flag) flag = true;
  }
  out << "}";
  return out;
}
