#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "Point.hpp"

struct Vector {
  double x, y;
  Vector(const double x = 0, const double y = 0);
  Vector(const Point& start, const Point& end);

  double len() const;
  double vector_mult(const Vector&) const;
  double sc_mult(const Vector&) const;
  double area(const Vector&) const;

  Vector operator*(double);
  Vector& operator*=(double);
  bool operator==(const Vector&) const;
  void operator()(const Point&, const Point&);

  friend std::ostream& operator<<(std::ostream& out, const Vector& v);
};

#endif  // VECTOR_HPP