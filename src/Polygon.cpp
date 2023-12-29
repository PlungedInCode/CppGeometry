#include "Polygon.hpp"

//*-------------------------Shape---------------------------------------

double Polygon::perimeter() const {
  size_t count = vertices_.size();
  double perimeter = 0;
  for (size_t i = 0; i < count; ++i) {
    perimeter += getDistance(vertices_[i], vertices_[(i + 1) % count]);
  }
  return perimeter;
}

double Polygon::area() const {
  size_t n = vertices_.size();
  if (n < 3) {
    return 0.0;  // Area is not defined for polygons with less than 3 vertices_
  }

  double totalArea = 0.0;
  for (size_t i = 0; i < n; ++i) {
    totalArea += (vertices_[i].x * vertices_[(i + 1) % n].y -
                  vertices_[(i + 1) % n].x * vertices_[i].y);
  }

  return 0.5 * std::abs(totalArea);
}

// bool Polygon::operator==(const Shape& other) const {
  
// }
// bool Polygon::isCongruentTo(const Shape& other) const {}
// bool Polygon::isSimilarTo(const Shape& other) const {}

bool Polygon::containsPoint(const Point& point) const {
  size_t count = vertices_.size();
  if (count < 3) {
    return false;  // Containment is not defined for polygons with less than 3
                   // vertices
  }

  int crossings = 0;
  for (size_t i = 0; i < count; ++i) {
    const Point& p1 = vertices_[i];
    const Point& p2 = vertices_[(i + 1) % count];

    if ((p1.y <= point.y && p2.y > point.y) ||
        (p2.y <= point.y && p1.y > point.y)) {
      double xIntersection =
          (point.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;

      if (point.x < xIntersection) {
        ++crossings;
      }
    }
  }

  return crossings % 2 == 1;
}
void Polygon::rotate(const Point& center, const double angle) {
  for (auto& vertex : vertices_) {
    double new_x = center.x + (vertex.x - center.x) * std::cos(angle) -
                   (vertex.y - center.y) * std::sin(angle);
    double new_y = center.y + (vertex.x - center.x) * std::sin(angle) +
                   (vertex.y - center.y) * std::cos(angle);
    vertex = {new_x, new_y};
  }
}

void Polygon::reflex(const Point& center) {
  for (auto& vertex : vertices_) {
    vertex = {2 * center.x - vertex.x, 2 * center.y - vertex.y};
  }
}
// void Polygon::reflex(const Line& axis) {
//   // for (Point& vertex : vertices_) {
//   //   double distanceToAxis = axis.distanceToPoint(vertex);
//   //   Point projection = axis.projectPoint(vertex);
//   //   vertex = {2 * projection.x - vertex.x, 2 * projection.y - vertex.y};
//   // }
// }

void Polygon::scale(const Point& center, double coefficient) {
  for (Point& vertex : vertices_) {
    vertex = {center.x + coefficient * (vertex.x - center.x),
              center.y + coefficient * (vertex.y - center.y)};
  }
}

//*-------------------------Polygon---------------------------------------
Polygon::Polygon(const std::vector<Point>& vertices) : vertices_(vertices) {}

Polygon::~Polygon() {}

size_t Polygon::verticesCount() const { return vertices_.size(); }

std::vector<Point> Polygon::getVertices() const { return vertices_; }

int CrossProduct(std::tuple<Point, Point, Point> points) {
  double x1 = (std::get<1>(points).x) - (std::get<0>(points).x);
  double y1 = (std::get<1>(points).y) - (std::get<0>(points).y);
  double x2 = (std::get<2>(points).x) - (std::get<0>(points).x);
  double y2 = (std::get<2>(points).y) - (std::get<0>(points).y);

  return (x1 * y2 - y1 * x2);
}

bool Polygon::isConvex() const {
  size_t count = vertices_.size();
  if (count < 3) {
    return false;
  }
  double prev = 0, curr = 0;
  for (size_t i = 0; i < count; ++i) {
    std::tuple<Point, Point, Point> triple = {
        vertices_[i], vertices_[(i + 1) % count], vertices_[(i + 2) % count]};
    curr = CrossProduct(triple);
    if (curr != 0) {
      if (curr * prev < 0) {
        return false;
      }
      prev = curr;
    }
  }
  return true;
}

std::ostream& operator<<(std::ostream& out, const Polygon& polygon) {
  for (auto it : polygon.vertices_) {
    out << it << ", ";
  }
  return out;
}
