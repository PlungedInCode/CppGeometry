#include "Rectangle.hpp"

Rectangle::Rectangle(const Point& point1, const Point& point2)
    : Polygon::Polygon(Point(point1.x, point1.y), Point(point2.x, point1.y),
                       Point(point2.x, point2.y), Point(point1.x, point2.y)) {}
Rectangle::~Rectangle() {};

// Additional methods specific to Rectangle
Point Rectangle::center() const {
  // Calculate the center of the rectangle
  // double centerX = (getVertex(0).x + getVertex(2).x) / 2.0;
  // double centerY = (getVertex(0).y + getVertex(2).y) / 2.0;

  // return {centerX, centerY};
}

std::pair<Line, Line> Rectangle::diagonals() const {
  // Calculate the diagonals of the rectangle
  // return {Line(getVertex(0), getVertex(2)), Line(getVertex(1),
  // getVertex(3))};
}

// Implement virtual methods from Shape class
double Rectangle::perimeter() const {
  // Calculate the perimeter of the rectangle
  // double side1 = getVertex(0).distanceTo(getVertex(1));
  // double side2 = getVertex(1).distanceTo(getVertex(2));

  // return 2 * (side1 + side2);
}

double Rectangle::area() const {
  // Calculate the area of the rectangle
  // double side1 = getVertex(0).distanceTo(getVertex(1));
  // double side2 = getVertex(1).distanceTo(getVertex(2));

  // return side1 * side2;
}

bool Rectangle::operator==(const Shape& another) const {
  const Rectangle* otherRectangle = dynamic_cast<const Rectangle*>(&another);

  // if (otherRectangle) {
  //     // Compare rectangle vertices for equality
  //     return getVertices() == otherRectangle->getVertices();
  // }

  return false;
}

bool Rectangle::isCongruentTo(const Shape& another) const {
  const Rectangle* otherRectangle = dynamic_cast<const Rectangle*>(&another);

  // if (otherRectangle) {
  //     // Two rectangles are congruent if they have the same vertices
  //     return getVertices() == otherRectangle->getVertices();
  // }

  return false;
}

bool Rectangle::isSimilarTo(const Shape& another) const {
  const Rectangle* otherRectangle = dynamic_cast<const Rectangle*>(&another);

  // if (otherRectangle) {
  //     // Two rectangles are similar if they have the same center
  //     return center() == otherRectangle->center();
  // }

  return false;
}

bool Rectangle::containsPoint(const Point& point) const {
  // Implement point containment check logic for a rectangle
  return Polygon::containsPoint(point);
}

void Rectangle::rotate(const Point& center, double angle) {
  // Rotate the vertices of the rectangle
  // for (auto& vertex : getVertices()) {
  //     vertex.rotate(center, angle);
  // }
}

void Rectangle::reflex(const Point& center) {
  // Reflect the vertices of the rectangle with respect to the center
  // for (auto& vertex : getVertices()) {
  // vertex.reflex(center);
  // }
}

void Rectangle::reflex(const Line& axis) {
  // Reflect the vertices of the rectangle with respect to the axis
  // for (auto& vertex : getVertices()) {
  //     vertex.reflex(axis);
  // }
}

void Rectangle::scale(const Point& center, double coefficient) {
  // Scale the vertices of the rectangle and move its center accordingly
  // for (auto& vertex : getVertices()) {
  //     vertex.scale(center, coefficient);
  // }
}
