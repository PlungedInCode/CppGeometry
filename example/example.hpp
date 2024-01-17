#include "Geometry.hpp"
#include "Logger.hpp"

void testPointClass() {
  LOG_DEBUG("Test Point classs:");

  Point p1(1.0, 2.0);
  Point p2(3.0, 4.0);

  LOG_DEBUG("p1: ", p1);
  LOG_DEBUG("p2: ", p2);
  LOG_DEBUG("p1 == p2 ", (p1 == p2));
  LOG_DEBUG("p1 != p2 ", (p1 != p2));
  p1 *= 2.0;
  p2 /= 3;
  LOG_DEBUG(p1 + p2, " ", p1 - p2, " ", p1 * 5, " ", p2 / 5);
  LOG_DEBUG("d = ", getDistance(p1, p2) );

  Point p3(1, 1);
  Point p4(4, 7);
  LOG_DEBUG("p3 : ", p3);
  p3.rotate(p4, 90);
  LOG_DEBUG("Rotated p3 ", p4, " : ", p3);

  Point p5(1, 1);
  Point p6(-1, 0);
  LOG_DEBUG("p5 : ", p5);
  p5.reflex(p6);
  LOG_DEBUG("Reflexed p5 ", p6, " :  ", p5);

  Point p7(1, 1);
  Point p8(2, 2);
  Line line(p7, p8);
  Point p9(3, 0);
  LOG_DEBUG("p9 : ", p9);
  p9.reflect(line);
  LOG_DEBUG("Reflexed line :  ", line, " :  ", p9);

  Point center(1, 0);
  Point p10(1, 1);
  double scale = 5;
  LOG_DEBUG("p10 : ", p10);
  p10.scale(center, scale);
  LOG_DEBUG("Scaled :  ", center, " :  ", p10);
}

void testLineClass() {
  Point p1(1.0, 2.0);
  Point p2(3.0, -1.0);
  Point p3(9.0, 6.0);

  Line line1(p1, p2);
  Line line2(p2, p3);
  Line line3(1.0, -3.0);
  Line line4(p2, 1.5);

  LOG_DEBUG("Test Line class:");
  LOG_DEBUG("line1: ", line1);
  LOG_DEBUG("line2: ", line2);
  LOG_DEBUG("line3: ", line3);
  LOG_DEBUG("line4: ", line3);

  std::vector<Line> lines = {line1, line2, line3, line4};
  for (auto it : lines) {
    for (auto jt : lines) {
      LOG_DEBUG(it, " <==> ", jt, " - ", (it == jt), " !", (it != jt));
    }
    LOG_DEBUG("\n");
  }
}

void testPolygonRectangle() {
  Point p1(-3, 2);
  Point p2(1, 2);
  Point p3(1, -1);
  Point p4(-3, -1);

  Polygon poly(p1, p2, p3, p4);
  Polygon poly2(p2, p3, p4, p1);

  LOG_DEBUG("Poly ", poly, " ", poly.verticesCount(), " Convex - ",
            poly.isConvex());
  LOG_DEBUG("Vertices:");
  for (auto it : poly.getVertices()) {
    LOG_DEBUG(it);
  }

  LOG_DEBUG("Perimeter ", poly.perimeter());
  LOG_DEBUG("Area ", poly.area());
  LOG_DEBUG("Poly2 ", poly2, " ", poly2.verticesCount(), " Convex - ",
            poly2.isConvex());
  LOG_DEBUG(" == ", (poly2 == poly));
  LOG_DEBUG("IsCongruent ", poly.isCongruentTo(poly2));
  LOG_DEBUG("IsSimilarTo ", poly.isSimilarTo(poly2));

  Point pt1(0, 0), pt2(10, 10);
  LOG_DEBUG(pt1, " contains? ", poly.containsPoint(pt1));
  LOG_DEBUG(pt2, " contains? ", poly.containsPoint(pt2));

  Point center(0, 0);
  double angle = 90;
  poly.rotate(center, angle);
  LOG_DEBUG("Rotated to ", angle, " from ", center, " Poly ", poly);

  poly.reflex(center);
  LOG_DEBUG("Reflex  from ", center, " Poly ", poly);

  Point center2(1, 1);
  Line line(center, center2);
  poly.reflect(line);
  LOG_DEBUG("Reflexed  from ", line, " Poly ", poly);

  double scale = 5;
  poly.scale(center, scale);
  LOG_DEBUG("Scaled to ", scale, " from ", center, " Poly ", poly);
}

void testPolygonClass() {
  Point p1(-4.0, 5.0);
  Point p2(3.0, 5.0);
  Point p3(3.0, 3.0);
  Point p4(6.0, 3.0);
  Point p5(6.0, -3.0);
  Point p6(2.0, -3.0);
  Point p7(2.0, -5.0);
  Point p8(-4.0, -5.0);

  Polygon poly(p1, p2, p3, p4, p5, p6, p7, p8);
  Polygon poly2(p2, p3, p4, p5, p6, p7, p8, p1);

  LOG_DEBUG("Poly ", poly, " ", poly.verticesCount(), " Convex - ",
            poly.isConvex());
  LOG_DEBUG("Vertices:");
  for (auto it : poly.getVertices()) {
    LOG_DEBUG(it);
  }

  LOG_DEBUG("Perimeter ", poly.perimeter());
  LOG_DEBUG("Area ", poly.area());
  LOG_DEBUG("Poly2 ", poly2, " ", poly2.verticesCount(), " Convex - ",
            poly2.isConvex());
  LOG_DEBUG(" == ", (poly2 == poly));
  LOG_DEBUG("IsCongruent ", poly.isCongruentTo(poly2));
  LOG_DEBUG("IsSimilarTo ", poly.isSimilarTo(poly2));

  Point pt1(0, 0), pt2(10, 10);
  LOG_DEBUG(pt1, " contains? ", poly.containsPoint(pt1));
  LOG_DEBUG(pt2, " contains? ", poly.containsPoint(pt2));

  Point center(0, 0);
  double angle = 90;
  poly.rotate(center, angle);
  LOG_DEBUG("Rotated to ", angle, " from ", center, " Poly ", poly);

  poly.reflex(center);
  LOG_DEBUG("Reflex  from ", center, " Poly ", poly);

  Point center2(1, 1);
  Line line(center, center2);
  poly.reflect(line);
  LOG_DEBUG("Reflex  from ", line, " Poly ", poly);

  double scale = 5;
  poly.scale(center, scale);
  LOG_DEBUG("Scaled to ", scale, " from ", center, " Poly ", poly);
}

void testEllipseClass() {
  Point p1(1.0, 2.0);
  Point p2(3.0, 4.0);

  Ellipse ellipse(p1, p2, 7.0);
  Ellipse ellipse2(p1 + p2, p2 - p1, 7.0);

  LOG_DEBUG("Test Ellipse class:");
  LOG_DEBUG("Ellipse eccentricity: ", ellipse.eccentricity());
  auto focuses = ellipse.focuses();
  LOG_DEBUG("Ellipse focuses: ", focuses.first, ", ", focuses.second);

  auto directrices = ellipse.directrices();
  LOG_DEBUG("Directrices : ", directrices.first, ", ", directrices.second);
  LOG_DEBUG("Center ", ellipse.center());

  LOG_DEBUG("Perimeter ", ellipse.perimeter());
  LOG_DEBUG("Area ", ellipse.area());
  LOG_DEBUG(" == ", (ellipse2 == ellipse));
  LOG_DEBUG("IsCongruent ", ellipse.isCongruentTo(ellipse2));
  LOG_DEBUG("IsSimilarTo ", ellipse.isSimilarTo(ellipse2));
  Point pt1(2, 3), pt2(15, 15);
  LOG_DEBUG(pt1, " contains? ", ellipse.containsPoint(pt1));
  LOG_DEBUG(pt2, " contains? ", ellipse.containsPoint(pt2));

  Point center(0, 0);
  double angle = 90;
  ellipse.rotate(center, angle);
  LOG_DEBUG("Rotated to ", angle, " from ", center, " ellipse ", ellipse);

  ellipse.reflex(center);
  LOG_DEBUG("Reflex  from ", center, " ellipse ", ellipse);

  Point center2(1, 1);
  Line line(center, center2);
  ellipse.reflect(line);
  LOG_DEBUG("Reflex  from ", line, " ellipse ", ellipse);

  double scale = 5;
  ellipse.scale(center, scale);
  LOG_DEBUG("Scaled to ", scale, " from ", center, " ellipse ", ellipse);
}

void testCircleClass() {
  Point center(1.0, 1.0);
  Circle circle(center, 5.0);
  Circle circle2(center * 2, 5.0);

  LOG_DEBUG("Test Circle class:");
  LOG_DEBUG("Circle radius: ", circle.radius());
  auto focuses = circle.focuses();
  LOG_DEBUG("Circle focuses: ", focuses.first, ", ", focuses.second);

  auto directrices = circle.directrices();
  LOG_DEBUG("Directrices : ", directrices.first, ", ", directrices.second);

  LOG_DEBUG("Center ", circle.center());

  LOG_DEBUG("Perimeter ", circle.perimeter());
  LOG_DEBUG("Area ", circle.area());
  LOG_DEBUG(" == ", (circle2 == circle));
  LOG_DEBUG("IsCongruent ", circle.isCongruentTo(circle2));
  LOG_DEBUG("IsSimilarTo ", circle.isSimilarTo(circle2));
  Point pt1(2, 3), pt2(15, 15);
  LOG_DEBUG(pt1, " contains? ", circle.containsPoint(pt1));
  LOG_DEBUG(pt2, " contains? ", circle.containsPoint(pt2));

  center.x = 0;
  center.y = 0;
  double angle = 90;
  circle.rotate(center, angle);
  LOG_DEBUG("Rotated to ", angle, " from ", center, " circle ", circle);

  circle.reflex(center);
  LOG_DEBUG("Reflex  from ", center, " circle ", circle);

  Point center2(1, 1);
  Line line(center, center2);
  circle.reflect(line);
  LOG_DEBUG("Reflex  from ", line, " circle ", circle);

  double scale = 5;
  circle.scale(center, scale);
  LOG_DEBUG("Scaled to ", scale, " from ", center, " circle ", circle);
}

void testRectangleClass() {
  Point p1(1.0, 2.0);
  Point p2(3.0, -1.0);

  Point p3(3.0, 3.0);
  Point p4(4.0, 8.0);

  Rectangle rect(p1, p2);
  Rectangle rect1(p3, p4);

  LOG_DEBUG("Rectangle class");
  LOG_DEBUG(rect);
  LOG_DEBUG("Center - ", rect.center());
  LOG_DEBUG("Perimeter - ", rect.perimeter());
  LOG_DEBUG("Area - ", rect.area());
  LOG_DEBUG("Operator == ", (rect == rect1));
  LOG_DEBUG("IsCongruent -", rect.isCongruentTo(rect1));
  LOG_DEBUG("IsSimilar - ", rect.isSimilarTo(rect1));
  Point pt1(2, 0.5), pt2(10, 10);

  LOG_DEBUG(pt1, " contains? ", rect.containsPoint(pt1));
  LOG_DEBUG(pt2, " contains? ", rect.containsPoint(pt2));

  Point center(0, 0);

  double angle = 90;
  rect.rotate(center, angle);
  LOG_DEBUG("Rotated to ", angle, " from ", center, " rect ", rect);

  rect.reflex(center);
  LOG_DEBUG("Reflex  from ", center, " rect ", rect);

  Point center2(1, 1);
  Line line(center, center2);
  rect.reflect(line);
  LOG_DEBUG("Reflex  from ", line, " rect ", rect);

  double scale = 5;
  rect.scale(center, scale);
  LOG_DEBUG("Scaled to ", scale, " from ", center, " rect ", rect);
}

void testSquareClass() {
  Point p1(-2, -2);
  Point p2(2, 2);

  Square square(p1, p2);
  Square square1(p1 - p2, p1 + p2);

  LOG_DEBUG("Square class");
  LOG_DEBUG(square);
  LOG_DEBUG("CircumscribedCircle", " ", square.circumscribedCircle());
  LOG_DEBUG("InscribedCircle", " ", square.inscribedCircle());
  LOG_DEBUG("IsConvex - ", square.isConvex());
  LOG_DEBUG("Center - ", square.center());
  auto diagonals = square.diagonals();
  LOG_DEBUG("Diagonals - ", diagonals.first, " ", diagonals.second);
  LOG_DEBUG("Perimeter - ", square.perimeter());
  LOG_DEBUG("Area - ", square.area());
  LOG_DEBUG("Operator == ", (square == square1));
  LOG_DEBUG("IsCongruent -", square.isCongruentTo(square1));
  LOG_DEBUG("IsSimilar - ", square.isSimilarTo(square1));
  Point pt1(2, 2), pt2(10, 10);

  LOG_DEBUG(pt1, " contains? ", square.containsPoint(pt1));
  LOG_DEBUG(pt2, " contains? ", square.containsPoint(pt2));

  Point center(0, 0);

  double angle = 90;
  square.rotate(center, angle);
  LOG_DEBUG("Rotated to ", angle, " from ", center, " square ", square);

  square.reflex(center);
  LOG_DEBUG("Reflex  from ", center, " square ", square);

  Point center2(1, 1);
  Line line(center, center2);
  square.reflect(line);
  LOG_DEBUG("Reflex  from ", line, " square ", square);

  double scale = 5;
  square.scale(center, scale);
  LOG_DEBUG("Scaled to ", scale, " from ", center, " square ", square);
}

void testTriangleClass() {
  Point p1(-2.0, -2.0);
  Point p2(0, 2.0);
  Point p3(2, -2.0);

  Triangle triangle(p1, p2, p3);
  Triangle triangle2(p1 * 2, p2 * 2, p3 * 2);

  LOG_DEBUG("Trinagle ", triangle, " ", triangle.verticesCount(), " Convex - ",
            triangle.isConvex());

  LOG_DEBUG("Vertices:");
  for (auto it : triangle.getVertices()) {
    LOG_DEBUG(it);
  }

  LOG_DEBUG("Test Triangle class:");
  LOG_DEBUG("Triangle circumscribed circle center: ",
            triangle.circumscribedCircle());
  LOG_DEBUG("Triangle inscribedCircle circle center: ",
            triangle.inscribedCircle());
  LOG_DEBUG("Triangle centroid: ", triangle.centroid());
  LOG_DEBUG("Triangle orthocenter: ", triangle.orthocenter());
  LOG_DEBUG("Triangle Euler line: ", triangle.EulerLine());
  LOG_DEBUG("Triangle nine points circle center: ",
            triangle.ninePointsCircle().center());

  LOG_DEBUG("Perimeter ", triangle.perimeter());
  LOG_DEBUG("Area ", triangle.area());
  LOG_DEBUG("triangle2 ", triangle2, " ", triangle2.verticesCount(),
            " Convex - ", triangle2.isConvex());
  LOG_DEBUG(" == ", (triangle2 == triangle));
  LOG_DEBUG("IsConguruent ", triangle.isCongruentTo(triangle2));
  LOG_DEBUG("IsSimilarTo ", triangle.isSimilarTo(triangle2));

  Point pt1(0, 0), pt2(10, 10);
  LOG_DEBUG(pt1, " contains? ", triangle.containsPoint(pt1));
  LOG_DEBUG(pt2, " contains? ", triangle.containsPoint(pt2));

  Point center(0, 0);
  double angle = 90;
  triangle.rotate(center, angle);
  LOG_DEBUG("Rotated to ", angle, " from ", center, " triangle ", triangle);

  triangle.reflex(center);
  LOG_DEBUG("Reflex  from ", center, " triangle ", triangle);

  Point center2(1, 1);
  Line line(center, center2);
  triangle.reflect(line);
  ;
  LOG_DEBUG("Reflex  from ", line, " triangle ", triangle);

  double scale = 5;
  triangle.scale(center, scale);
  LOG_DEBUG("Scaled to ", scale, " from ", center, " triangle ", triangle);
}

void CompareTest() {
  Point pt1(-2, -2);
  Point pt2(2, 2);
  std::vector<Point> pts = {pt1, pt2};
  Rectangle rect(pts);
  Square square(pt2, pt1);
  Polygon poly(pt1, Point(pt2.x, pt1.y), pt2, Point(pt1.x, pt2.y));
  LOG_DEBUG("Rectangle ", rect);
  LOG_DEBUG("Square ", square);
  LOG_DEBUG("Polygon ", poly);
  LOG_DEBUG("Polygon == Rectangle ", (poly == rect));
  LOG_DEBUG("Polygon == Square ", (poly == square));
  LOG_DEBUG("Square == Rectangle ", (square == rect));
}

void runTests() {
  Logger::SetLogLevel(kTrace);
  LOG_INFO("======================TEST0======================");
  testPointClass();
  LOG_INFO("======================TEST1======================");
  testLineClass();
  LOG_INFO("======================TEST2======================");
  testPolygonRectangle();
  LOG_INFO("======================TEST3======================");
  testPolygonClass();
  LOG_INFO("======================TEST4======================");
  testEllipseClass();
  LOG_INFO("======================TEST5======================");
  testCircleClass();
  LOG_INFO("======================TEST6======================");
  testRectangleClass();
  LOG_INFO("=======================TEST7=====================");
  testSquareClass();
  LOG_INFO("=======================TEST8=====================");
  testTriangleClass();
  LOG_INFO("=======================TEST9=====================");
  CompareTest();
}