#ifndef LINE_HPP
#define LINE_HPP

#include "Constants.hpp"
#include "Point.hpp"
class Line {
 public:
  Line();
  Line(const Point& start, const Point& end);
  Line(const double slope, const double intercept);
  Line(const Point& point, const double slope);
  ~Line();

  double getSlope() const;
  double getIntercept() const;

  Point intersect(const Line& other) const;

  bool operator==(const Line& other) const;
  bool operator!=(const Line& other) const;

  friend std::ostream& operator<<(std::ostream& out, const Line& line);

 private:
  double slope_;
  double intercept_;
};

#endif  // LINE_HPP