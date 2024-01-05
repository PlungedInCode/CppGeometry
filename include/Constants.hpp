#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <cmath>
#include <numbers>

namespace Constants {
  constexpr double PI = 3.141592653589793238462643383279502884;
  constexpr double PI_DEG = 180.0;
  constexpr double EPSILON = 1e-9;
}  // namespace Constants

namespace Utils {
  inline bool isEqual(const double x, const double y) {
    return std::fabs(x - y) <= Constants::EPSILON;
  }

  inline double degToRad(const double angle) {
    return (angle / Constants::PI_DEG) * Constants::PI;
  }
}  // namespace Utils

#endif  // CONSTANTS_HPP