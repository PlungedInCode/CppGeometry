#include "Point.hpp"

Point::Point(const double x, const double y) : x(x), y(y) {}

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other) const { 
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "("<< point.x << ", " << point.y << ")";
    return out;
}

// bool operator<(const Point& point1, const Point& point2) {
//     double len1 = point1.x * point1.x - point1.y * point1.y;
//     double len2 = point2.x * point2.x - point2.y * point2.y;

//     return len1 < len2;
// }

double getDistance(const Point& p1, const Point& p2) {
    double xx = p2.x - p1.x;
    double yy = p2.y - p1.y;
    return sqrt(xx * xx + yy * yy);
}