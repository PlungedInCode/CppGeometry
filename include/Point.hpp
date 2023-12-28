#pragma once

#include <ostream>
#include <math.h>

struct Point {
    double x, y;
    Point(const double x, const double y);
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Point& point);
};

// bool operator<(const Point& p1, const Point& p2);

double getDistance(const Point& p1, const Point& p2);