#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Line.hpp"
#include "Point.hpp"

class Shape {
 public:
  virtual double perimeter() const = 0;
  virtual double area() const = 0;
  virtual bool operator==(const Shape& other) const = 0;
  virtual bool operator!=(const Shape& other) const = 0;
  virtual bool isCongruentTo(const Shape& other) const = 0;
  virtual bool isSimilarTo(const Shape& other) const = 0;
  virtual bool containsPoint(const Point& point) const = 0;

  virtual void rotate(const Point& center, const double angle) = 0;
  virtual void reflex(const Point& center) = 0;
  virtual void reflect(const Line& axis) = 0;
  virtual void scale(const Point& center, const double coefficient) = 0;

  virtual ~Shape() = default;
};

#endif  // SHAPE_HPP