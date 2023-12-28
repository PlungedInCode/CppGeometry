#include <iostream>
// #include <vector>
// #include "Shape.hpp"

#include "Line.hpp"
#include "Point.hpp"
#include "Polygon.hpp"

int main() {
  Point x(-10.232323, 23.2);
  Point y(2, 12.05);
  Line line(x, y);
  std::cout << line << std::endl;

  std::vector<Point> points = {{-1, -1}, {-2, -2}, {-3, -3}, {3, 3},
                               {2, 2},   {1, 1},   {0, 0}};
  std::vector<Point> pp = {{-3, -2}, {-1, -4}, {6, 1},
                           {3, 10},  {-4, 9},  {-3, -2}};

  Polygon withVec(points);
  std::vector<Point> pp1 = {{2, 2}, {-2, 2}, {-2, -2}, {2, -2}};
  Polygon ppp(pp1);
  std::cout << "Area of " << ppp
   << " -- " << ppp.area() << ", " << ppp.perimeter() << '\n';
  //           << ppp.isConvex() << " " << (ppp == withVec) << " " <<  std::endl;

  // Point z(0, 0);
  // ppp.rotate(z, 180.0);
  //   std::cout << "Area of Rotated " << ppp << " " << ppp.area() << ", " << ppp.perimeter()
  //           << ppp.isConvex() << " " << (ppp == withVec) << " " <<  std::endl;


  Polygon polygon(Point(0.0, 0.0), Point(1.0, 0.0), Point(1.0, 1.0),
                  Point(0.0, 1.0));

  std::cout << polygon << '\n' << std::endl;
}