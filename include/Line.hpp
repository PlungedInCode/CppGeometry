#pragma once

#include "Point.hpp"


class Line {
public:
    Line(const Point& start, const Point& end);
    Line(const double slope, const double intercept);
    Line(const Point& point, const double slope);
    ~Line();
    
    double getSlope() const;
    double getIntercept() const;

    bool operator==(const Line& other) const;
    bool operator!=(const Line& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Line& line);

private:
    // y = slope * x + intercept or x = intercept (if line is vertical)
    double slope_;
    double intercept_;
    bool vertical_;
};