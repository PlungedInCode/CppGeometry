#include "Rectangle.hpp"

Rectangle::Rectangle(const Point& point1, const Point& point2)
    : Polygon::Polygon(point1, Point(point2.x, point1.y), point2,
                       Point(point1.x, point2.y)) {}

Rectangle::Rectangle(const Point& point1, const Point& point2, int ratio)
    : Polygon(chooseVerticesOrder(point1, point2, ratio)) {}

std::vector<Point> Rectangle::chooseVerticesOrder(const Point& point1,
                                                  const Point& point2,
                                                  int ratio) const {
  double distance1to2 = getDistance(point1, point2);
  double distanceRatio = distance1to2 / (1.0 + ratio);

  Point p1 = point1;
  Point p2 = point1 + Point(distanceRatio, 0);
  Point p3 = point2;
  Point p4 = point2 - Point(distanceRatio, 0);

  if (point1.x < point2.x) {
    return {p1, p2, p3, p4};
  } else {
    return {p2, p1, p4, p3};
  }
}

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

// bool Rectangle::operator==(const Shape& other) const {
//     const Rectangle* otherRectangle = dynamic_cast<const Rectangle*>(&other);

//     if (otherRectangle) {
//         return Polygon::operator==(*otherRectangle); // Compare sets of points
//     }

//     return false;
// }


std::ostream& operator<<(std::ostream& out, const Rectangle& rect) {
  out << "{";
  for (auto it : rect.getVertices()) {
    out << it << ", ";
  }
  out << "}";
  return out;
}