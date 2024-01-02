#include "Ellipse.hpp"

Ellipse::Ellipse(const Point& focus1, const Point& focus2,
                 double sum_of_distances)
    : focus1_(focus1), focus2_(focus2), sum_of_distances_(sum_of_distances) {}

Ellipse::~Ellipse() {}

std::pair<Point, Point> Ellipse::focuses() const {
  return std::make_pair(focus1_, focus2_);
}

std::pair<Line, Line> Ellipse::directrices() const {
  double majorAxisAngle =
      std::atan2(focus2_.y - focus1_.y, focus2_.x - focus1_.x);
  double minorAxisAngle = majorAxisAngle + M_PI / 2.0;

  Line directrix1(-std::sin(majorAxisAngle), std::cos(majorAxisAngle));
  Line directrix2(-std::sin(minorAxisAngle), std::cos(minorAxisAngle));

  return {directrix1, directrix2};
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
  double a = sum_of_distances_ / 2.0;
  double distance = getDistance(focus1_, focus2_);
  double b = std::sqrt(a * a - distance * distance / 4.0);

  return 4.0 * (std::acos(0.0) *
                ((3 * (a + b)) - std::sqrt((3 * a + b) * (a + 3 * b))));
}

double Ellipse::area() const {
  double a = sum_of_distances_ / 2.0;
  double distance = getDistance(focus1_, focus2_);
  double b = std::sqrt(a * a - distance * distance / 4.0);

  return std::acos(0.0) * a * b;
}

bool Ellipse::operator==(const Shape& another) const {
  const Ellipse* otherEllipse = dynamic_cast<const Ellipse*>(&another);

  if (otherEllipse) {
    return focus1_ == otherEllipse->focus1_ &&
           focus2_ == otherEllipse->focus2_ &&
           sum_of_distances_ == otherEllipse->sum_of_distances_;
  }

  return false;
}

// TODO: Research
bool Ellipse::isCongruentTo(const Shape& another) const {
  const Ellipse* otherEllipse = dynamic_cast<const Ellipse*>(&another);

  if (otherEllipse) {
    return focus1_ == otherEllipse->focus1_ &&
           focus2_ == otherEllipse->focus2_ &&
           sum_of_distances_ == otherEllipse->sum_of_distances_;
  }

  return false;
}

// TODO: Research
bool Ellipse::isSimilarTo(const Shape& another) const {
  const Ellipse* otherEllipse = dynamic_cast<const Ellipse*>(&another);

  if (otherEllipse) {
    return focus1_ == otherEllipse->focus1_ && focus2_ == otherEllipse->focus2_;
  }

  return false;
}

bool Ellipse::containsPoint(const Point& point) const {
  double eccentricity = this->eccentricity();
  double semiMajorAx = sum_of_distances_ / 2.0;
  double semiMinorAx = semiMajorAx * std::sqrt(1 - eccentricity * eccentricity);

  double normalizedX = (point.x - center().x) / semiMajorAx;
  double normalizedY = (point.y - center().y) / semiMinorAx;

  return (normalizedX * normalizedX + normalizedY * normalizedY) <= 1.0;
}

void Ellipse::rotate(const Point& center, double angle) {
  focus1_.rotate(center, angle);
  focus2_.rotate(center, angle);
}

void Ellipse::reflex(const Point& center) {
  focus1_.reflex(center);
  focus2_.reflex(center);
}

void Ellipse::reflex(const Line& axis) {
  focus1_.reflex(axis);
  focus2_.reflex(axis);
}

void Ellipse::scale(const Point& center, double coefficient) {
  focus1_.scale(center, coefficient);
  focus2_.scale(center, coefficient);
}

std::ostream& operator<<(std::ostream& out, const Ellipse& ellipse) {
  out << "{(" << ellipse.focus1_ << " " << ellipse.focus2_ << "), "
      << ellipse.sum_of_distances_ << "}" << std::endl;
  return out;
}