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

// // Implement virtual methods from Rectangle and Shape
// double Square::perimeter() const {
//     // Calculate the perimeter of the square
//     // double length = getVertex(0).distanceTo(getVertex(1));
//     double length = 0;
//     return 4 * length;
// }

// double Square::area() const {
//     // Calculate the area of the square
//     // double side = getVertex(0).distanceTo(getVertex(1));
//     double side = 0;
//     return side * side;
// }

// bool Square::operator==(const Shape& another) const {
//     const Square* otherSquare = dynamic_cast<const Square*>(&another);

//     if (otherSquare) {
//         // Compare square vertices for equality
//         // return getVertices() == otherSquare->getVertices();
//     }

//     return false;
// }

// bool Square::isCongruentTo(const Shape& another) const {
//     const Square* otherSquare = dynamic_cast<const Square*>(&another);

//     if (otherSquare) {
//         // Two squares are congruent if they have the same vertices
//         // return getVertices() == otherSquare->getVertices();
//     }

//     return false;
// }

// bool Square::isSimilarTo(const Shape& another) const {
//     const Square* otherSquare = dynamic_cast<const Square*>(&another);

//     if (otherSquare) {
//         // Two squares are similar if they have the same center
//         return center() == otherSquare->center();
//     }

//     return false;
// }

// bool Square::containsPoint(const Point& point) const {
//     // Implement point containment check logic for a square
//     return Rectangle::containsPoint(point);
// }

// void Square::rotate(const Point& center, double angle) {
//     // Rotate the vertices of the square
//     for (auto& vertex : getVertices()) {
//         // vertex.rotate(center, angle);
//     }
// }

// void Square::reflex(const Point& center) {
//     // Reflect the vertices of the square with respect to the center
//     for (auto& vertex : getVertices()) {
//         // vertex.reflex(center);
//     }
// }

// void Square::reflex(const Line& axis) {
//     // Reflect the vertices of the square with respect to the axis
//     for (auto& vertex : getVertices()) {
//         // vertex.reflex(axis);
//     }
// }

// void Square::scale(const Point& center, double coefficient) {
//     // Scale the vertices of the square and move its center accordingly
//     for (auto& vertex : getVertices()) {
//         // vertex.scale(center, coefficient);
//     }
// }