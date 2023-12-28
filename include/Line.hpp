#pragma once

#include "Point.hpp"

class Line {
public:
    Line(const Point& start, const Point& end);
    Line(const double slope, const double intercept);
    Line(const Point& point, const double slope);
    
    bool operator==(const Line& other) const;
    bool operator!=(const Line& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Line& line);

    ~Line();
private:
    double slope_;
    double intercept_;
    // y = slope * x + intercept
};