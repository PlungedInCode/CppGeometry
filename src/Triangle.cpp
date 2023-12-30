#include "Triangle.hpp"
#include <cmath>

// Constructor
Triangle::Triangle(const Point& vertex1, const Point& vertex2, const Point& vertex3) : Polygon::Polygon(vertex1, vertex2, vertex3) {
    // Add vertices in traversal order
    // addVertex(vertex1);
    // addVertex(vertex2);
    // addVertex(vertex3);
}

// Additional methods specific to Triangle
Circle Triangle::circumscribedCircle() const {
    // Calculate the circumscribed circle of the triangle
    // Point A = getVertex(0);
    // Point B = getVertex(1);
    // Point C = getVertex(2);

    // double a = B.distanceTo(C);
    // double b = A.distanceTo(C);
    // double c = A.distanceTo(B);

    // double centerX = (a * A.x + b * B.x + c * C.x) / (a + b + c);
    // double centerY = (a * A.y + b * B.y + c * C.y) / (a + b + c);

    // double radius = A.distanceTo({centerX, centerY});


    // return Circle({centerX, centerY}, radius);
}

Circle Triangle::inscribedCircle() const {
    // Calculate the inscribed circle of the triangle
    // Point A = getVertex(0);
    // Point B = getVertex(1);
    // Point C = getVertex(2);

    // double a = B.distanceTo(C);
    // double b = A.distanceTo(C);
    // double c = A.distanceTo(B);

    // double centerX = (a * A.x + b * B.x + c * C.x) / (a + b + c);
    // double centerY = (a * A.y + b * B.y + c * C.y) / (a + b + c);

    // double radius = 2 * area() / perimeter();

    // return Circle({centerX, centerY}, radius);
}

Point Triangle::centroid() const {
    // Calculate the centroid of the triangle
    // double centerX = (getVertex(0).x + getVertex(1).x + getVertex(2).x) / 3.0;
    // double centerY = (getVertex(0).y + getVertex(1).y + getVertex(2).y) / 3.0;

    // return {centerX, centerY};
}

Point Triangle::orthocenter() const {
    // Calculate the orthocenter of the triangle
    // Point A = getVertex(0);
    // Point B = getVertex(1);
    // Point C = getVertex(2);

    // double a = B.distanceTo(C);
    // double b = A.distanceTo(C);
    // double c = A.distanceTo(B);

    // double numeratorX = a * a * (A.x - B.x + C.x) + b * b * (B.x - C.x + A.x) + c * c * (C.x - A.x + B.x);
    // double numeratorY = a * a * (A.y - B.y + C.y) + b * b * (B.y - C.y + A.y) + c * c * (C.y - A.y + B.y);
    // double denominator = 2 * (a * (B.y - C.y) + b * (C.y - A.y) + c * (A.y - B.y));

    // return {numeratorX / denominator, numeratorY / denominator};
}

Line Triangle::EulerLine() const {
    // Calculate the Euler line of the triangle
    // return Line(centroid(), circumscribedCircle().center());
}

Circle Triangle::ninePointsCircle() const {
    // Calculate the nine points circle of the triangle
    // Circle circumscribed = circumscribedCircle();
    // Circle inscribed = inscribedCircle();

    // Point center = (circumscribed.center() + inscribed.center()) / 2.0;
    // double radius = (circumscribed.radius() + inscribed.radius()) / 2.0;

    // return Circle(center, radius);
}

// Implement virtual methods from Polygon and Shape
double Triangle::perimeter() const {
    // Calculate the perimeter of the triangle
    // return getVertex(0).distanceTo(getVertex(1)) + getVertex(1).distanceTo(getVertex(2)) +
    //        getVertex(2).distanceTo(getVertex(0));
}

double Triangle::area() const {
    // Calculate the area of the triangle
    // Point A = getVertex(0);
    // Point B = getVertex(1);
    // Point C = getVertex(2);

    // return 0.5 * std::abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
}

bool Triangle::operator==(const Shape& another) const {
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&another);

    if (otherTriangle) {
        // Compare triangle vertices for equality
        // return getVertices() == otherTriangle->getVertices();
    }

    return false;
}

bool Triangle::isCongruentTo(const Shape& another) const {
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&another);

    if (otherTriangle) {
        // Two triangles are congruent if they have the same vertices
        // return getVertices() == otherTriangle->getVertices();
    }

    return false;
}

bool Triangle::isSimilarTo(const Shape& another) const {
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&another);

    if (otherTriangle) {
        // Two triangles are similar if they have the same centroid
        // return centroid() == otherTriangle->centroid();
    }

    return false;
}

bool Triangle::containsPoint(const Point& point) const {
    // Implement point containment check logic for a triangle
    return Polygon::containsPoint(point);
}

void Triangle::rotate(const Point& center, double angle) {
    // Rotate the vertices of the triangle
    // for (auto& vertex : getVertices()) {
    //     vertex.rotate(center, angle);
    // }
}

void Triangle::reflex(const Point& center) {
    // Reflect the vertices of the triangle with respect to the center
    // for (auto& vertex : getVertices()) {
    //     vertex.reflex(center);
    // }
}

void Triangle::reflex(const Line& axis) {
    // Reflect the vertices of the triangle with respect to the axis
    // for (auto& vertex : getVertices()) {
    //     vertex.reflex(axis);
    // }
}

void Triangle::scale(const Point& center, double coefficient) {
    // Scale the vertices of the triangle and move its center accordingly
    // for (auto& vertex : getVertices()) {
    //     vertex.scale(center, coefficient);
    // }
}
