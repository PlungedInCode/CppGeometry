#include "Triangle.hpp"

Triangle::Triangle(const Point& vertex1, const Point& vertex2,
                   const Point& vertex3)
    : Polygon::Polygon(vertex1, vertex2, vertex3) {}

Triangle::~Triangle(){};

//* Additional methods specific to Triangle

Point Triangle::centerCircumscribedCircle() const {
  Vector v12{vertices_[1], vertices_[0]};
  Vector v23{vertices_[2], vertices_[1]};
  Vector v31{vertices_[0], vertices_[2]};
  double z = v12.x * v31.y - v12.y * v31.x;
  double z_1 =
      vertices_[0].x * vertices_[0].x + vertices_[0].y * vertices_[0].y;
  double z_2 =
      vertices_[1].x * vertices_[1].x + vertices_[1].y * vertices_[1].y;
  double z_3 =
      vertices_[2].x * vertices_[2].x + vertices_[2].y * vertices_[2].y;
  double z_x = z_3 * v12.y + z_1 * v23.y + z_2 * v31.y;
  double z_y = z_3 * v12.x + z_1 * v23.x + z_2 * v31.x;
  double new_x = -z_x / (2 * z);
  double new_y = z_y / (2 * z);
  return {new_x, new_y};
}
Circle Triangle::circumscribedCircle() const {
  Point center = centerCircumscribedCircle();
  return {center, Vector{center, vertices_[0]}.len()};
}
Circle Triangle::inscribedCircle() const {
  double l_1 = Vector{vertices_[1], vertices_[2]}.len();
  double l_2 = Vector{vertices_[0], vertices_[2]}.len();
  double l_3 = Vector{vertices_[0], vertices_[1]}.len();
  double new_y =
      (l_1 * vertices_[0].y + l_2 * vertices_[1].y + l_3 * vertices_[2].y) /
      (l_1 + l_2 + l_3);
  double new_x =
      (l_1 * vertices_[0].x + l_2 * vertices_[1].x + l_3 * vertices_[2].x) /
      (l_1 + l_2 + l_3);
  double rad = -(vertices_[1].x * vertices_[0].y + vertices_[0].x * new_y -
                 vertices_[0].y * new_x - vertices_[1].x * new_y -
                 vertices_[1].y * vertices_[0].x + vertices_[1].y * new_x) /
               sqrt(pow(vertices_[0].x - vertices_[1].x, 2) +
                    pow(vertices_[0].y - vertices_[1].y, 2));
  return {Point{new_x, new_y}, rad};
}

Point Triangle::centroid() const {
  auto vertices = Polygon::getVertices();
  double centerX = (vertices[0].x + vertices[1].x + vertices[2].x) / 3.0;
  double centerY = (vertices[0].y + vertices[1].y + vertices[2].y) / 3.0;

  return {centerX, centerY};
}

Point Triangle::orthocenter() const {
  double a1 = vertices_[2].x - vertices_[1].x,
         b1 = vertices_[2].y - vertices_[1].y;
  double c1 = vertices_[0].x * (vertices_[2].x - vertices_[1].x) +
              vertices_[0].y * (vertices_[2].y - vertices_[1].y);
  double a2 = vertices_[2].x - vertices_[0].x,
         b2 = vertices_[2].y - vertices_[0].y;
  double c2 = vertices_[1].x * (vertices_[2].x - vertices_[0].x) +
              vertices_[1].y * (vertices_[2].y - vertices_[0].y);
  double den = a1 * b2 - a2 * b1;
  double num_x = c1 * b2 - c2 * b1;
  double num_y = a1 * c2 - a2 * c1;
  return {num_x / den, num_y / den};
}

Line Triangle::EulerLine() const {
  Point orthocenter = Triangle::orthocenter();
  Point circumcenter = Triangle::circumscribedCircle().center();
  return Line(orthocenter, circumcenter);
}

Circle Triangle::ninePointsCircle() const {
  Circle circumscribed = circumscribedCircle();
  Point center = (orthocenter() + circumscribed.center()) * 0.5;
  return {center, circumscribed.radius() / 2};
}

std::ostream& operator<<(std::ostream& out, const Triangle& trig) {
  bool flag = false;
  out << "{";
  for (auto it : trig.getVertices()) {
    if (flag) out << ", ";
    out << it;
    if (!flag) flag = true;
  }
  out << "}";
  return out;
}