#include "Triangle.hpp"

#include <iostream>

#include <cmath>

// Constructor
Triangle::Triangle(const Point& vertex1, const Point& vertex2,
                   const Point& vertex3)
    : Polygon::Polygon(vertex1, vertex2, vertex3) {}

Triangle::~Triangle(){};

// Additional methods specific to Triangle
Circle Triangle::circumscribedCircle() const {
  auto vertices = Polygon::getVertices();
  Point A = vertices[0];
  Point B = vertices[1];
  Point C = vertices[2];

  auto d = 2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
  double a = (A.x * A.x + A.y * A.y);
  double b = (B.x * B.x + B.y * B.y);
  double c = (C.x * C.x + C.y * C.y);

  double center_x = (a * (B.y - C.y) +  b * (C.y - A.y) + c * (A.y - B.y)) / d;
  double center_y = (a * (C.x - B.x) +  b * (A.x - C.x) + c * (B.x - A.x)) / d;

  double radius = getDistance(A, {center_x, center_y});

  return Circle({center_x, center_y}, radius);
}

Circle Triangle::inscribedCircle() const {
  auto vertices = Polygon::getVertices();
  Point A = vertices[0];
  Point B = vertices[1];
  Point C = vertices[2];

  double a = getDistance(B, C);
  double b = getDistance(A, C);
  double c = getDistance(A, B);

  double centerX = (a * A.x + b * B.x + c * C.x) / (a + b + c);
  double centerY = (a * A.y + b * B.y + c * C.y) / (a + b + c);

  double radius = 2 * area() / perimeter();

  return Circle({centerX, centerY}, radius);
}

Point Triangle::centroid() const {
  auto vertices = Polygon::getVertices();
  double centerX = (vertices[0].x + vertices[1].x + vertices[2].x) / 3.0;
  double centerY = (vertices[0].y + vertices[1].y + vertices[2].y) / 3.0;

  return {centerX, centerY};
}

// Point Triangle::orthocenter() const {
//   auto vertices = Polygon::getVertices();
//   Point A = vertices[0];
//   Point B = vertices[1];
//   Point C = vertices[2];

//   double a = getDistance(B, C);
//   double b = getDistance(A, C);
//   double c = getDistance(A, B);

//   double numeratorX = a * a * (A.x - B.x + C.x) + b * b * (B.x - C.x + A.x) +
//                       c * c * (C.x - A.x + B.x);
//   double numeratorY = a * a * (A.y - B.y + C.y) + b * b * (B.y - C.y + A.y) +
//                       c * c * (C.y - A.y + B.y);
//   double denom = 2 * (a * (B.y - C.y) + b * (C.y - A.y) + c * (A.y - B.y));

//   return {numeratorX / denom, numeratorY / denom};
// }
Point Triangle::orthocenter() const {
  Point circum_center = circumscribedCircle().center();
  Point centroid_p = this->centroid();
  double x = 3 * centroid_p.x - 2 * circum_center.x;
  double y = 3 * centroid_p.y - 2 * circum_center.y;
  return Point(x, y);
}


// Line Triangle::EulerLine() const {
//   // std::cout << centroid()
//   return Line(centroid(), circumscribedCircle().center());
// }

Line Triangle::EulerLine() const {
  // Calculate the Euler line of the triangle
  Point orthocenter = Triangle::orthocenter();
  Point circumcenter = Triangle::circumscribedCircle().center();
  std::cout << orthocenter << " " << circumcenter << std::endl;
  return Line(orthocenter, circumcenter);
}

Circle Triangle::ninePointsCircle() const {
  Circle circumscribed = circumscribedCircle();
  Circle inscribed = inscribedCircle();

  Point center = (circumscribed.center() + inscribed.center()) / 2.0;
  double radius = (circumscribed.radius() + inscribed.radius()) / 2.0;

  return Circle(center, radius);
}