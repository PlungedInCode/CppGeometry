#pragma once
#include <cmath>
#include <numbers>

namespace Constants {
    constexpr double PI = 3.141592653589793238462643383279502884;
    double EPSILON = 1e-7;
}

namespace Uitls {
    bool isEqual(const double x, const double y) {
        return std::abs(x - y) <= Constants:: EPSILON;
    }

    double degToRad(const double angle) {
        return (angle / 180.0) * Constants::PI;
    }
}