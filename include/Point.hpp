#pragma once

#include "Constants.hpp"

#include <ostream>
#include <math.h>

class Line;

struct Point {
    double x, y;
    Point(const double x, const double y);
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    Point& operator+=(const Point& rhs);
    friend Point operator+(Point lhs, const Point& rhs);

    Point& operator-=(const Point& rhs);
    friend Point operator-(Point lhs, const Point& rhs);

    Point& operator*=(const double scalar);
    friend Point operator*(Point lhs, const double scalar);

    Point& operator/=(const double scalar);
    friend Point operator/(Point lhs, const double scalar);

    void reflex(const Point& center);
    void reflect(const Line& axis);

    void rotate(const Point& center, const double angle);

    void scale(const Point& center, const double coefficient);
    
    bool operator<(const Point& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Point& point);
};

double getDistance(const Point& p1, const Point& p2);
