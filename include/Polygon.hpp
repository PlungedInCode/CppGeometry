#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>

#include "Vector.hpp"
#include "Shape.hpp"

class Polygon : public Shape {
 public:
  Polygon();
  explicit Polygon(const std::vector<Point>& vertices);
  template <typename... Args>
  Polygon(const Args&... args) : vertices_({args...}) {}

  virtual ~Polygon() = default;

  size_t verticesCount() const;
  std::vector<Point> getVertices() const;

  bool isConvex() const;

  bool operator==(const Polygon& other) const;
  bool operator!=(const Polygon& other) const;

  //* Shape's virtual methods
  bool operator==(const Shape& other) const override;
  bool operator!=(const Shape& other) const override;
  double perimeter() const override;
  double area() const override;
  bool isCongruentTo(const Shape& other) const override;
  bool isSimilarTo(const Shape& other) const override;
  bool containsPoint(const Point& point) const override;

  void rotate(const Point& center, const double angle) override;
  void reflex(const Point& center) override;
  void reflect(const Line& axis) override;
  void scale(const Point& center, const double coefficient) override;

  friend std::ostream& operator<<(std::ostream& out, const Polygon& polygon);

 protected:
  std::vector<Point> vertices_;
};
#endif  // POLYGON_HPP