#include "Circle.hpp"

Circle::Circle(const Point& center, double radius)
    : Ellipse(center, center, 2 * radius), radius_(radius) {}

Circle::~Circle() {}

// Additional method specific to Circle
double Circle::radius() const { return radius_; }

// Override methods from Ellipse
// std::pair<Point, Point> Circle::focuses() const {
//     // For a circle, the focuses coincide with the center
//     return {center(), center()};
// }

// std::pair<Line, Line> Circle::directrices() const {
//     // Directrices of a circle are not defined, returning a placeholder
//     return {{0, 0}, {0, 0}};
// }

// double Circle::eccentricity() const {
//     // Eccentricity of a circle is always 0
//     return 0.0;
// }

// Point Circle::center() const {

// }

// Implement virtual methods from Shape class
double Circle::perimeter() const { return 2 * Constants::PI * radius_; }

double Circle::area() const { return Constants::PI * radius_ * radius_; }

// bool Circle::operator==(const Shape& another) const {
//     const Circle* otherCircle = dynamic_cast<const Circle*>(&another);

//     if (otherCircle) {
//         return center() == otherCircle->center() && radius_ ==
//         otherCircle->radius_;
//     }

//     return false;
// }

// bool Circle::isCongruentTo(const Shape& another) const {
//     const Circle* otherCircle = dynamic_cast<const Circle*>(&another);

//     if (otherCircle) {
//         return center() == otherCircle->center() && radius_ ==
//         otherCircle->radius_;
//     }

//     return false;
// }

// bool Circle::isSimilarTo(const Shape& another) const {
//     const Circle* otherCircle = dynamic_cast<const Circle*>(&another);

//     if (otherCircle) {
//         // Two circles are similar if they have the same center
//         return center() == otherCircle->center();
//     }

//     return false;
// }

// bool Circle::containsPoint(const Point& point) const {
//     // Implement point containment check logic for a circle
//     double distance = getDistance(center(), point);
//     return distance <= radius_;
// }

// void Circle::rotate(const Point& center, double angle) {
//     // Rotate the center of the circle
//     // center().rotate(center, angle);
// }

// void Circle::reflex(const Point& center) {
//     // Reflect the center of the circle
//     // center().reflex(center);
// }

// void Circle::reflex(const Line& axis) {
//     // Reflect the center of the circle with respect to the axis
//     // center().reflex(axis);
// }

void Circle::scale(const Point& center, double coefficient) {
    radius_ *= coefficient;
    Ellipse::scale(center, coefficient);
}

std::ostream& operator<<(std::ostream& out, const Circle& circle) {
  out << "{" << circle.center() << ", r = " << circle.radius() << "}" << std::endl;
  return out;
}