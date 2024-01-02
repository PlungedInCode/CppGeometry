#include "Line.hpp"

//* Two points
// slope = (y2 - y1) / (x2 - x1)
// y = slope * (x2 - x1) + y1
Line::Line(const Point& start, const Point& end) {
  if (end.x - start.x != 0) {
    slope_ = (end.y - start.y) / (end.x - start.x);
    intercept_ = start.y - slope_ * start.x;
    vertical_ = false;
  } else {
    slope_ = 1;
    intercept_ = start.x;
    vertical_ = true;
  }
}

//* Slope and shift
// y = slope * x + intercept
Line::Line(const double slope, const double intercept)
    : slope_(slope), intercept_(intercept) {}

//* Point and slope
// y = slope * (x - x0) + y1
Line::Line(const Point& point, const double slope) : slope_(slope) {
  intercept_ = point.y - slope_ * point.x;
}

Line::~Line() {}

double Line::getSlope() const {
  if (vertical_)
    throw std::runtime_error("Vertical line doesn't have a defined slope.");
  return slope_;
}
double Line::getIntercept() const { return intercept_; }

bool Line::operator==(const Line& other) const {
  return slope_ == other.slope_ && intercept_ == other.intercept_;
}

bool Line::operator!=(const Line& other) const { return !(*this == other); }

std::ostream& operator<<(std::ostream& out, const Line& line) {
  out << (line.vertical_ ? "x = "
                         : "y = " + std::to_string(line.slope_) + " * x + ")
      << line.intercept_;
  return out;
}