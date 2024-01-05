#ifndef TRINAGLE_HPP
#define TRINAGLE_HPP

#include <cmath>
#include <ostream>

#include "Circle.hpp"
#include "Polygon.hpp"

class Triangle : public Polygon {
 public:
  Triangle(const Point& vertex1, const Point& vertex2, const Point& vertex3);
  ~Triangle();

  Circle circumscribedCircle() const;
  Circle inscribedCircle() const;
  Point centroid() const;
  Point orthocenter() const;
  Line EulerLine() const;
  Circle ninePointsCircle() const;

  Point centerCircumscribedCircle() const;

  friend std::ostream& operator<<(std::ostream& out, const Triangle& trig);
};

#endif  // TRINAGLE_HPP