#pragma once

#include "Point.hpp"
#include "Constants.hpp"
class Line {
public:
    Line();
    Line(const Point& start, const Point& end);
    Line(const double slope, const double intercept);
    Line(const Point& point, const double slope);
    ~Line();
    
    bool operator==(const Line& other) const;
    bool operator!=(const Line& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Line& line);

    // Ax + By + C = 0
    double A;
    double B;
    double C;
};

Point lineIntersection(const Line& a, const Line& b);