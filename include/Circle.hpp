#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Ellipse.hpp"
#include "Point.hpp"

class Circle : public Ellipse {
 public:
  Circle(const Point& center, const double radius);
  ~Circle();

  double radius() const;

  friend std::ostream& operator<<(std::ostream& out, const Circle& circle);
};

#endif  // CIRCLE_HPP