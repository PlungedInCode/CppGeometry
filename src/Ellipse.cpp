#include "Ellipse.hpp"

using namespace Utils;


Ellipse::Ellipse(const Point& p1, const Point& p2, double len)
    : focus_1_(p1), focus_2_(p2), length_(len) {}

double Ellipse::perimeter() const {
  double c = Vector{focus_1_, focus_2_}.len() / 2;
  double a = length_ / 2;
  double perimeter_ = 4 * a * std::comp_ellint_2(c / a);
  return perimeter_;
}
double Ellipse::area() const { 
  double c = Vector{focus_1_, focus_2_}.len() / 2;
  double a = length_ / 2;
  double b = sqrt((length_ * length_ / 4) - c * c);
  double area_ = M_PI * a * b;
  return area_;
}

bool Ellipse::isCongruentTo(const Shape& other) const {
  auto* ell = dynamic_cast<const Ellipse*>(&other);
  if (ell == nullptr || fabs(ell->length_ - length_) > Constants::EPSILON) {
    return false;
  }
  if (fabs(Vector{focus_1_, focus_2_}.len() -
           Vector{ell->focus_1_, ell->focus_2_}.len()) < Constants::EPSILON) {
    return true;
  }
  return false;
}
bool Ellipse::isSimilarTo(const Shape& other) const {
  auto* ell = dynamic_cast<const Ellipse*>(&other);
  if (ell == nullptr) {
    return false;
  }
  double k = Vector{focus_1_, focus_2_}.len() /
             Vector{ell->focus_1_, ell->focus_2_}.len();
  if (fabs(length_ / ell->length_ - k) < Constants::EPSILON) {
    return true;
  }
  return false;
}
bool Ellipse::containsPoint(const Point& point) const {
  if (Vector{focus_1_, point}.len() + Vector{focus_2_, point}.len() <=
      length_) {
    return true;
  }
  return false;
}
std::pair<Point, Point> Ellipse::focuses() const { return {focus_1_, focus_2_}; }

double Ellipse::eccentricity() const {
  return Vector{focus_1_, focus_2_}.len() / length_;
}

std::pair<Line, Line> Ellipse::directrices() const {

  double majorAxisAngle =
      std::atan2(focus_2_.y - focus_1_.y, focus_2_.x - focus_1_.x);
  double minorAxisAngle = majorAxisAngle + M_PI / 2.0;
  Line directrix1(-std::sin(majorAxisAngle), std::cos(majorAxisAngle));
  Line directrix2(-std::sin(minorAxisAngle), std::cos(minorAxisAngle));

  return {directrix1, directrix2};
}

Point Ellipse::center() const {
  double centerX = (focus_1_.x + focus_2_.x) / 2.0;
  double centerY = (focus_1_.y + focus_2_.y) / 2.0;
  return Point(centerX, centerY);
}

bool Ellipse::operator==(const Shape& other) const {
  auto* ell = dynamic_cast<const Ellipse*>(&other);
  if (ell == nullptr) {
    return false;
  }
  return *this == *ell;
}
bool Ellipse::operator==(const Ellipse& other) const {
  if (other.length_ != length_) {
    return false;
  }
  if (other.focus_1_ == focus_1_ && other.focus_2_ == focus_2_) {
    return true;
  }
  if (other.focus_1_ == focus_2_ && other.focus_2_ == focus_1_) {
    return true;
  }
  return false;
}
bool Ellipse::operator!=(const Shape& other) const { return !(*this == other); }
bool Ellipse::operator!=(const Ellipse& other) const {
  return !(*this == other);
}

void Ellipse::rotate(const Point& center, double angle) {
  focus_1_.rotate(center, angle);
  focus_2_.rotate(center, angle);
}

void Ellipse::reflex(const Point& center) {
  focus_1_.reflex(center);
  focus_2_.reflex(center);
}

void Ellipse::reflect(const Line& axis) {
  focus_1_.reflect(axis);
  focus_2_.reflect(axis);
}

void Ellipse::scale(const Point& center, double coefficient) {
  focus_1_.scale(center, coefficient);
  focus_2_.scale(center, coefficient);
  length_ *= coefficient;
}

std::ostream& operator<<(std::ostream& out, const Ellipse& ellipse) {
  out << "{(" << ellipse.focus_1_ << " " << ellipse.focus_2_ << "), "
      << ellipse.length_ << "}";
  return out;
}