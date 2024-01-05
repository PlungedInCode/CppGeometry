#include "Polygon.hpp"

Polygon::Polygon() : vertices_() {}
Polygon::Polygon(const std::vector<Point>& vertices) : vertices_(vertices) {}

size_t Polygon::verticesCount() const { return vertices_.size(); }

std::vector<Point> Polygon::getVertices() const { return vertices_; }

int CrossProduct(const Point& p1, const Point& p2, const Point& p3) {
  double x1 = (p2.x) - (p1.x);
  double y1 = (p2.y) - (p1.y);
  double x2 = (p3.x) - (p1.x);
  double y2 = (p3.y) - (p1.y);

  return (x1 * y2 - y1 * x2);
}

bool Polygon::isConvex() const {
  size_t count = vertices_.size();
  if (count < 3) {
    return false;
  }
  double prev = 0, curr = 0;
  for (size_t i = 0; i < count; ++i) {
    curr = CrossProduct(vertices_[i], vertices_[(i + 1) % count],
                        vertices_[(i + 2) % count]);
    if (curr != 0) {
      if (curr * prev < 0) {
        return false;
      }
      prev = curr;
    }
  }
  return true;
}

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
    return 0.0;
  }

  double totalArea = 0.0;
  for (size_t i = 0; i < n; ++i) {
    totalArea += (vertices_[i].x * vertices_[(i + 1) % n].y -
                  vertices_[(i + 1) % n].x * vertices_[i].y);
  }

  return 0.5 * std::abs(totalArea);
}

bool Polygon::operator==(const Shape& other) const {
  auto* poly = dynamic_cast<const Polygon*>(&other);
  if (poly == nullptr || vertices_.size() != poly->vertices_.size()) {
    return false;
  }
  return (*this == *poly);
}
bool Polygon::operator==(const Polygon& other) const {
  if (vertices_.size() != other.vertices_.size()) {
    return false;
  }
  bool found = false;
  size_t start = 0;
  for (size_t i = 0; i < vertices_.size(); ++i) {
    if (vertices_[i] == other.vertices_[0]) {
      start = i;
      found = true;
      break;
    }
  }
  if (!found) {
    return false;
  }
  for (size_t i = 0; i < vertices_.size(); ++i) {
    size_t idx = (i + start >= vertices_.size()) ? i + start - vertices_.size()
                                                 : i + start;
    if (vertices_[idx] != other.vertices_[i]) {
      found = false;
      break;
    }
  }
  if (found) {
    return true;
  }
  for (size_t i = 1; i < vertices_.size(); ++i) {
    size_t idx = (start < i) ? start + vertices_.size() - i : start - i;
    if (vertices_[idx] != other.vertices_[i]) {
      return false;
    }
  }
  return true;
}
bool Polygon::operator!=(const Shape& other) const { return !(*this == other); }
bool Polygon::operator!=(const Polygon& other) const {
  return !(*this == other);
}

bool Polygon::isCongruentTo(const Shape& other) const {
  auto* poly = dynamic_cast<const Polygon*>(&other);
  if (poly == nullptr || vertices_.size() != poly->vertices_.size()) {
    return false;
  }
  std::vector<double> angles1(vertices_.size(), 0);
  std::vector<double> lengths1(vertices_.size(), 0);
  Vector first_vec{vertices_.back(), vertices_[0]};
  Vector cur_vec{vertices_[0], vertices_[1]};
  for (size_t i = 1; i < vertices_.size() - 1; ++i) {
    angles1[i - 1] =
        first_vec.vector_mult(cur_vec) / (first_vec.len() * cur_vec.len());
    lengths1[i - 1] = cur_vec.len();
    first_vec = cur_vec;
    cur_vec(vertices_[i], vertices_[i + 1]);
  }
  angles1[vertices_.size() - 2] =
      first_vec.vector_mult(cur_vec) / (first_vec.len() * cur_vec.len());
  lengths1[vertices_.size() - 2] = cur_vec.len();
  first_vec = cur_vec;
  cur_vec(vertices_.back(), vertices_[0]);
  angles1[vertices_.size() - 1] =
      first_vec.vector_mult(cur_vec) / (first_vec.len() * cur_vec.len());
  lengths1[vertices_.size() - 1] = cur_vec.len();

  std::vector<double> angles2(vertices_.size(), 0);
  std::vector<double> lengths2(vertices_.size(), 0);
  first_vec(poly->vertices_.back(), poly->vertices_[0]);
  cur_vec(poly->vertices_[0], poly->vertices_[1]);
  for (size_t i = 1; i < vertices_.size() - 1; ++i) {
    angles2[i - 1] =
        first_vec.vector_mult(cur_vec) / (first_vec.len() * cur_vec.len());
    lengths2[i - 1] = cur_vec.len();
    first_vec = cur_vec;
    cur_vec(poly->vertices_[i], poly->vertices_[i + 1]);
  }
  angles2[vertices_.size() - 2] =
      first_vec.vector_mult(cur_vec) / (first_vec.len() * cur_vec.len());
  lengths2[vertices_.size() - 2] = cur_vec.len();
  first_vec = cur_vec;
  cur_vec(poly->vertices_.back(), poly->vertices_[0]);
  angles2[vertices_.size() - 1] =
      first_vec.vector_mult(cur_vec) / (first_vec.len() * cur_vec.len());
  lengths2[vertices_.size() - 1] = cur_vec.len();

  for (size_t i = 0; i < vertices_.size(); ++i) {
    if (fabs(angles1[i] - angles2[0]) < Constants::EPSILON) {
      if (fabs(lengths1[i] - lengths2[0]) < Constants::EPSILON) {
        bool flag = false;
        for (size_t j = 1; j < vertices_.size(); ++j) {
          size_t idx =
              (i + j) >= vertices_.size() ? i + j - vertices_.size() : i + j;
          if (fabs(angles1[idx] - angles2[j]) > Constants::EPSILON ||
              fabs(lengths1[idx] - lengths2[j]) > Constants::EPSILON) {
            flag = true;
            break;
          }
        }
        if (!flag) {
          return true;
        }
      } else if (fabs(lengths1[i] - lengths2.back()) < Constants::EPSILON) {
        bool flag = false;
        for (size_t j = 1; j < vertices_.size(); ++j) {
          size_t idx =
              (i + j) >= vertices_.size() ? i + j - vertices_.size() : i + j;
          if (fabs(angles1[idx] - angles2[vertices_.size() - j]) >
                  Constants::EPSILON ||
              fabs(lengths1[idx] - lengths2[vertices_.size() - 1 - j]) >
                  Constants::EPSILON) {
            flag = true;
            break;
          }
        }
        if (!flag) {
          return true;
        }
      }
    }
  }
  return false;
}
bool Polygon::isSimilarTo(const Shape& other) const {
  auto* poly = dynamic_cast<const Polygon*>(&other);
  if (poly == nullptr || vertices_.size() != poly->vertices_.size()) {
    return false;
  }
  std::vector<double> angles1(vertices_.size(), 0);
  Vector first_vec{vertices_.back(), vertices_[0]};
  Vector cur_vec{vertices_[0], vertices_[1]};
  for (size_t i = 1; i < vertices_.size() - 1; ++i) {
    angles1[i - 1] =
        first_vec.vector_mult(cur_vec) / (first_vec.len() * cur_vec.len());
    first_vec = cur_vec;
    cur_vec(vertices_[i], vertices_[i + 1]);
  }
  angles1[vertices_.size() - 2] =
      first_vec.vector_mult(cur_vec) / (first_vec.len() * cur_vec.len());
  first_vec = cur_vec;
  cur_vec(vertices_.back(), vertices_[0]);
  angles1[vertices_.size() - 1] =
      first_vec.vector_mult(cur_vec) / (first_vec.len() * cur_vec.len());

  std::vector<double> angles2(vertices_.size(), 0);
  first_vec(poly->vertices_.back(), poly->vertices_[0]);
  cur_vec(poly->vertices_[0], poly->vertices_[1]);
  for (size_t i = 1; i < vertices_.size() - 1; ++i) {
    angles2[i - 1] =
        first_vec.vector_mult(cur_vec) / (first_vec.len() * cur_vec.len());
    first_vec = cur_vec;
    cur_vec(poly->vertices_[i], poly->vertices_[i + 1]);
  }
  angles2[vertices_.size() - 2] =
      first_vec.vector_mult(cur_vec) / (first_vec.len() * cur_vec.len());
  first_vec = cur_vec;
  cur_vec(poly->vertices_.back(), poly->vertices_[0]);
  angles2[vertices_.size() - 1] =
      first_vec.vector_mult(cur_vec) / (first_vec.len() * cur_vec.len());

  for (size_t i = 0; i < vertices_.size(); ++i) {
    if (fabs(angles1[i] - angles2[0]) < Constants::EPSILON) {
      bool flag = false;
      for (size_t j = 0; j < vertices_.size(); ++j) {
        size_t idx =
            (j + i >= vertices_.size()) ? j + i - vertices_.size() : j + i;
        if (fabs(angles1[idx] - angles2[j]) > Constants::EPSILON) {
          flag = true;
          break;
        }
      }
      if (!flag) {
        return true;
      }
    } else if (fabs(angles1[i] + angles2[0]) < Constants::EPSILON) {
      bool flag = false;
      for (size_t j = 1; j < vertices_.size(); ++j) {
        size_t idx = (i < j) ? i + vertices_.size() - j : i - j;
        if (fabs(angles1[idx] + angles2[j]) > Constants::EPSILON) {
          flag = true;
          break;
        }
      }
      if (!flag) {
        return true;
      }
    }
  }
  return false;
}

bool Polygon::containsPoint(const Point& point) const {
  size_t count = vertices_.size();
  if (count < 3) {
    return false;
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
    vertex.rotate(center, angle);
  }
}

void Polygon::reflex(const Point& center) {
  for (auto& vertex : vertices_) {
    vertex.reflex(center);
  }
}

void Polygon::reflect(const Line& axis) {
  for (Point& vertex : vertices_) {
    vertex.reflect(axis);
  }
}

void Polygon::scale(const Point& center, double coefficient) {
  for (Point& vertex : vertices_) {
    vertex.scale(center, coefficient);
  }
}

std::ostream& operator<<(std::ostream& out, const Polygon& polygon) {
  bool flag = false;
  out << "{";
  for (auto it : polygon.getVertices()) {
    if (flag) out << ", ";
    out << it;
    if (!flag) flag = true;
  }
  out << "}";
  return out;
}
