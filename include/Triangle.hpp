#pragma once

#include "Circle.hpp"
#include "Polygon.hpp"

class Triangle : public Polygon {
 public:
  // Constructor
  Triangle(const Point& vertex1, const Point& vertex2, const Point& vertex3);
  ~Triangle();
  // Additional methods specific to Triangle
  Circle circumscribedCircle() const;
  Circle inscribedCircle() const;
  Point centroid() const;
  Point orthocenter() const;
  Line EulerLine() const;
  Circle ninePointsCircle() const;
};