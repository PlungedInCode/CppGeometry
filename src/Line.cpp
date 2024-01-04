#include "Line.hpp"

// Ax + By + C = 0;
Line::Line() : A(0), B(0), C(0){};

//* Two points
Line::Line(const Point& start, const Point& end) {
  if (Utils::isEqual(start.x, end.x)) {
    A = 1;
    B = 0;
    C = -start.x;
  } else if (Utils::isEqual(start.y, end.y)) {
    A = 0;
    B = 1;
    C = -start.y;
  } else {
    A = (start.y - end.y) / (start.x - end.x);
    B = -1;
    C = (start.x * end.y - end.x * start.y) / (start.x - end.x);
  }
}

//* Slope and shift
Line::Line(const double slope, const double intercept)
    : A(slope), B(-1), C(intercept) {}

//* Point and slope
Line::Line(const Point& point, const double slope)
    : A(slope), B(-1), C(point.y - A * point.x) {}

Line::~Line() {}

bool Line::operator==(const Line& other) const {
  return Utils::isEqual(A, other.A) && Utils::isEqual(B, other.B) &&
         Utils::isEqual(C, other.C);
}

bool Line::operator!=(const Line& other) const { return !(*this == other); }

std::ostream& operator<<(std::ostream& out, const Line& line) {
  out << line.A << "x +" << line.B << "y + " << line.C;
  return out;
}

Point lineIntersection(const Line& line1, const Line& line2) {
  double x, y;
  if (Utils::isEqual(line1.B, 0.0)) {
    x = -line1.C / line1.A;
    y = (-line2.C - line2.A * x) / line2.B;
  } else if (Utils::isEqual(line1.A, 0.0)) {
    y = -line1.C / line1.B;
    x = (-line2.C - line2.B * y) / line2.A;
  } else {
    x = (line1.B * line2.C - line2.B * line1.C) /
        (line2.B * line1.A - line2.A * line1.B);
    y = (-line1.C - line1.A * x) / line1.B;
  }
  if (Utils::isEqual(x, 0.0)) x = fabs(x);
  if (Utils::isEqual(y, 0.0)) y = fabs(y);
  return Point(x, y);
}