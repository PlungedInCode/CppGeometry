#include "Square.hpp"

Square::Square(const Point& first, const Point& second)
    : Rectangle(first, second, 1.0) {}
Circle Square::circumscribedCircle() {
  return {center(), Vector(vertices_[0], vertices_[2]).len() / 2};
}
Circle Square::inscribedCircle() {
  return {center(), Vector(vertices_[0], vertices_[1]).len() / 2};
}
std::ostream& operator<<(std::ostream& out, const Square& sq) {
  bool flag = false;
  out << "{";
  for (auto it : sq.getVertices()) {
    if (flag) out << ", ";
    out << it;
    if (!flag) flag = true;
  }
  out << "}";
  return out;
}
