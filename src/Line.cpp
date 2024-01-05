#include "Line.hpp"

using namespace Utils;

Line::Line(const Point& start, const Point& end)
    : slope_((start.y - end.y) / (start.x - end.x)),
      intercept_(start.y - slope_ * start.x) {
  if (std::isinf(slope_)) {
    intercept_ = 0;
  }
}

Line::Line(const double slope, const double intercept)
    : slope_(slope), intercept_(intercept) {}

Line::Line(const Point& point, const double slope)
    : slope_(slope), intercept_(point.y - slope_ * point.x) {}

Line::~Line() {}

double Line::getSlope() const { return slope_; }

double Line::getIntercept() const { return intercept_; }

bool Line::operator==(const Line& other) const {
  return isEqual(slope_, other.slope_) && isEqual(intercept_, other.intercept_);
}

bool Line::operator!=(const Line& other) const { return !(*this == other); }

Point Line::intersect(const Line& other) const {
  double new_x = (intercept_ - other.intercept_) / (slope_ - other.slope_);
  double new_y = slope_ * new_x + intercept_;
  return {new_x, new_y};
}

std::ostream& operator<<(std::ostream& out, const Line& line) {
  out << "y = " << line.getSlope() << "x + " << line.getIntercept();
  return out;
}