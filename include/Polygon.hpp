#pragma once

#include <algorithm>
#include <vector>
#include <set>

#include "Shape.hpp"
#include "Constants.hpp"

class Polygon : public Shape {
 public:
  
  Polygon(const std::vector<Point>& vertices);
  template <typename... Args>
  Polygon(const Args&... args) : vertices_({args...}) {} 
  virtual ~Polygon();

  size_t verticesCount() const;
  std::vector<Point> getVertices() const;

  bool isConvex() const;

  //* Shape's virtual methods
  double perimeter() const override;
  double area() const override;
  bool operator==(const Shape& other) const override;
  bool operator!=(const Shape& other) const override;
  bool isCongruentTo(const Shape& other) const override;
  bool isSimilarTo(const Shape& other) const override;
  bool containsPoint(const Point& point) const override;

  void rotate(const Point& center, const double angle) override;
  void reflex(const Point& center) override;
  void reflect(const Line& axis) override;
  void scale(const Point& center, const double coefficient) override;

  friend std::ostream& operator<<(std::ostream& out, const Polygon& polygon);

 private:
  std::vector<Point> vertices_;
};