#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Circle.hpp"
#include "Rectangle.hpp"

class Square : public Rectangle {
 public:
  Square(const Point&, const Point&);
  Circle circumscribedCircle();
  Circle inscribedCircle();

  friend std::ostream& operator<<(std::ostream& out, const Square& sq);
};

#endif  // SQUARE_HPP