#pragma once

#include "Circle.hpp"
#include "Polygon.hpp"

class Triangle : public Polygon {
 public:
  // Constructor
  Triangle(const Point& vertex1, const Point& vertex2, const Point& vertex3);

  // Additional methods specific to Triangle
  Circle circumscribedCircle() const;
  Circle inscribedCircle() const;
  Point centroid() const;
  Point orthocenter() const;
  Line EulerLine() const;
  Circle ninePointsCircle() const;

  // Override methods from Polygon and Shape
  double perimeter() const override;
  double area() const override;
  bool operator==(const Shape& another) const override;
  bool isCongruentTo(const Shape& another) const override;
  bool isSimilarTo(const Shape& another) const override;
  bool containsPoint(const Point& point) const override;
  void rotate(const Point& center, double angle) override;
  void reflex(const Point& center) override;
  void reflex(const Line& axis) override;
  void scale(const Point& center, double coefficient) override;
};