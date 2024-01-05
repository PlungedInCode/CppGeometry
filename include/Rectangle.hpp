#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Point.hpp"
#include "Polygon.hpp"
// #include "Constants.hpp"

class Rectangle : public Polygon {
 public:
  Rectangle(const Point& first, const Point& second, double coef);
  Rectangle(const Point& first, const Point& second, int coef = 1);
  Rectangle(const std::vector<Point>&);

  Point center() const;
  std::pair<Line, Line> diagonals() const;

  friend std::ostream& operator<<(std::ostream& out, const Rectangle& rect);
};

#endif  // RECTANGLE_HPP