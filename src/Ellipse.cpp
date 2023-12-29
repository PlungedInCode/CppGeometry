#include "Ellipse.hpp"

Ellipse::Ellipse(const Point& focus1, const Point& focus2,
                 double sum_of_distances)
    : focus1_(focus1), focus2_(focus2), sum_of_distances_(sum_of_distances) {}

std::pair<Point, Point> Ellipse::focuses() const {
  return std::make_pair(focus1_, focus2_);
}

Ellipse::~Ellipse() {}

// std::pair<Line, Line> Ellipse::directrices() const {

// }

std::pair<Line, Line> Ellipse::directrices() const {
  // Implementation to calculate directrices
  // Assuming a simple case where directrices are vertical and horizontal lines
  // passing through the foci double distanceBetweenFoci = getDistance(focus1_,
  // focus2_);
  double halfDistance = sum_of_distances_ / 2.0;

  Point directrix1(focus1_.x, focus1_.y + halfDistance);
  Point directrix2(focus2_.x, focus2_.y - halfDistance);

  Line line1(focus1_, directrix1);
  Line line2(focus2_, directrix2);

  return std::make_pair(line1, line2);
}

double Ellipse::eccentricity() const {
  double distanceBetweenFoci = getDistance(focus1_, focus2_);
  return distanceBetweenFoci / (2 * sum_of_distances_);
}

Point Ellipse::center() const {
  double centerX = (focus1_.x + focus2_.x) / 2.0;
  double centerY = (focus1_.y + focus2_.y) / 2.0;
  return Point(centerX, centerY);
}

//* Implementation of Shape class methods
double Ellipse::perimeter() const {
  // An accurate calculation of ellipse perimeter involves elliptic integrals,
  // but for simplicity, we use an approximation here.
  // Note: This is an approximation and may not be suitable for all cases.
  double a = sum_of_distances_ / 2.0;
  double b = std::sqrt(a * a - getDistance(focus1_, focus2_) *
                                   getDistance(focus1_, focus2_) / 4.0);

  return 4.0 * (std::acos(0.0) *
                ((3 * (a + b)) - std::sqrt((3 * a + b) * (a + 3 * b))));
}

double Ellipse::area() const {
  double a = sum_of_distances_ / 2.0;
  double b = std::sqrt(a * a - getDistance(focus1_, focus2_) *
                                   getDistance(focus1_, focus2_) / 4.0);

  return std::acos(0.0) * a * b;
}

// bool Ellipse::operator==(const Shape& another) const {}
// bool Ellipse::isCongruentTo(const Shape& another) const {}
// bool Ellipse::isSimilarTo(const Shape& another) const {}

bool Ellipse::containsPoint(const Point& point) const {
  // Calculate the distance from the given point to each focus
  double distance1 = getDistance(point, focus1_);
  double distance2 = getDistance(point, focus2_);

  // Check if the sum of distances is approximately equal to the sum of
  // distances from the foci
  return std::abs(distance1 + distance2 - sum_of_distances_) < 1e-6;
}
void Ellipse::rotate(const Point& center, double angle) {
  // Translate the foci and the center of the ellipse to the origin
  Point translatedFocus1 = focus1_ - center;
  Point translatedFocus2 = focus2_ - center;
  // Point translatedCenter = this->center() - center;

  // Rotate the translated points
  double rotatedX1 = translatedFocus1.x * std::cos(angle) -
                     translatedFocus1.y * std::sin(angle);
  double rotatedY1 = translatedFocus1.x * std::sin(angle) +
                     translatedFocus1.y * std::cos(angle);

  double rotatedX2 = translatedFocus2.x * std::cos(angle) -
                     translatedFocus2.y * std::sin(angle);
  double rotatedY2 = translatedFocus2.x * std::sin(angle) +
                     translatedFocus2.y * std::cos(angle);

  // double rotatedCenterX = translatedCenter.x * std::cos(angle) -
  //                         translatedCenter.y * std::sin(angle);
  // double rotatedCenterY = translatedCenter.x * std::sin(angle) +
  //                         translatedCenter.y * std::cos(angle);

  // Translate back to the original position
  focus1_ = Point(rotatedX1 + center.x, rotatedY1 + center.y);
  focus2_ = Point(rotatedX2 + center.x, rotatedY2 + center.y);
}

void Ellipse::reflex(const Point& center) {
  focus1_ = 2 * center - focus1_;
  focus2_ = 2 * center - focus2_;
}

// void Ellipse::reflex(const Line& axis) {

// }

void Ellipse::scale(const Point& center, double coefficient) {
  // Scale the foci and the center of the ellipse with respect to the given
  // center
  focus1_ = center + coefficient * (focus1_ - center);
  focus2_ = center + coefficient * (focus2_ - center);
}

std::ostream& operator<<(std::ostream& out, const Ellipse& ellipse) {
  out << "{(" << ellipse.focus1_ << " " << ellipse.focus2_ << "), "
      << ellipse.sum_of_distances_ << "}" << std::endl;
  return out;
}