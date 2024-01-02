#pragma once

#include "Circle.hpp"
#include "Rectangle.hpp"

class Square : public Rectangle {
 public:
  Square(const Point& point1, const Point& point2);
  ~Square();

  Circle circumscribedCircle() const;
  Circle inscribedCircle() const;

  //   bool operator==(const Shape& other) const override;

  friend std::ostream& operator<<(std::ostream& out, const Rectangle& rect);

 private:
};