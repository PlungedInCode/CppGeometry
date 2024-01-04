#include "Polygon.hpp"

using namespace Utils;

//* Additional method specific to Polygon
Polygon::Polygon(const std::vector<Point>& vertices) : vertices_(vertices) {}

Polygon::~Polygon() {}

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

//* Virtual methods from Shape class

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

  return 0.5 * std::fabs(totalArea);
}

bool verticesVectorsEqual(std::vector<Point> lhs, std::vector<Point> rhs) {
  for (size_t j = 0; j < lhs.size() + 1; ++j) {
    bool equal = true;
    for (size_t i = 0; i < lhs.size(); ++i) {
      if (lhs[i] != rhs[i]) {
        equal = false;
        break;
      }
    }
    std::rotate(lhs.begin(), lhs.begin() + 1, lhs.end());
    if (equal) {
      return true;
    }
  }
  return false;
}

bool Polygon::operator==(const Shape& other) const {
  const auto otherPolygon = dynamic_cast<const Polygon*>(&other);

  if (!otherPolygon || this->verticesCount() != otherPolygon->verticesCount()) {
    return false;
  }

  std::vector<Point> thisCopy = this->getVertices();
  bool equal = verticesVectorsEqual(thisCopy, otherPolygon->getVertices());
  if (!equal) {
    std::reverse(thisCopy.begin(), thisCopy.end());
    equal = verticesVectorsEqual(thisCopy, otherPolygon->getVertices());
  }
  return equal;
}

bool Polygon::operator!=(const Shape& other) const { return !(*this == other); }

bool Polygon::isCongruentTo(const Shape& other) const {
  const auto otherPolygon = dynamic_cast<const Polygon*>(&other);

  if (!otherPolygon || this->verticesCount() != otherPolygon->verticesCount()) {
    return false;
  }
  std::vector<double> lhs_side_len, rhs_side_len;
  size_t N = this->verticesCount();
  for (size_t i = 0; i < N; ++i) {
    lhs_side_len.push_back(getDistance(vertices_[i], vertices_[(i + 1) % N]));
    rhs_side_len.push_back(getDistance(otherPolygon->vertices_[i],
                                       otherPolygon->vertices_[(i + 1) % N]));
  }

  bool is_equal = true;
  int match_index = -1, first_index = 0;
  double first_len = rhs_side_len[0];
  while (match_index < this->verticesCount()) {
    for (size_t i = first_index; i < verticesCount(); ++i) {
      if (isEqual(lhs_side_len[i], first_len)) {
        match_index = i;
        break;
      }
    }
    if (match_index == -1) {
      return false;
    }

    for (size_t i = 0; i < this->verticesCount(); ++i) {
      if (!isEqual(rhs_side_len[i], lhs_side_len[(match_index + i) % N])) {
        is_equal = false;
        break;
      }
    }
    if (is_equal) return true;

    bool is_equal = true;
    for (size_t i = 0; i < this->verticesCount(); ++i) {
      int j = match_index - i;
      if (match_index - i < 0) {
        j += N;
      }
      if (!isEqual(rhs_side_len[i], lhs_side_len[j])) {
        is_equal = false;
        break;
      }
    }
    if (is_equal) return true;
    first_index = match_index + 1;
    match_index = -1;
  }
  return is_equal;
}

bool Polygon::isSimilarTo(const Shape& other) const {
  const auto otherPolygon = dynamic_cast<const Polygon*>(&other);

  if (!otherPolygon) {
    return false;
  }
  double ratio = this->perimeter() / otherPolygon->perimeter();
  return Utils::isEqual(ratio * ratio, this->area() / otherPolygon->area());
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