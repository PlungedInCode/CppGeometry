#pragma once

#include "Geometry.hpp"

#include <iostream>



void testPointClass() {
  std::cout << "Test Point class:\n";

  Point p1(1.0, 2.0);
  Point p2(3.0, 4.0);

  std::cout << "p1: " << p1 << "\n";
  std::cout << "p2: " << p2 << "\n";
  std::cout << "p1 == p2 " << (p1 == p2) << "\n";
  std::cout << "p1 != p2 " << (p1 != p2) << "\n";
  p1 *= 2.0;
  p2 /= 3;
  std::cout << p1 + p2 << " " << p1 - p2 << " " << p1 * 5 << " " << p2 / 5
            << '\n';
  std::cout << "d = " << getDistance(p1, p2) << "\n\n";

  Point p3(1, 1);
  Point p4(4, 7);
  std::cout << "p3 : " << p3 << std::endl;
  p3.rotate(p4, 90);
  std::cout << "Rotated p3 " << p4 << " : " << p3 << std::endl;

  Point p5(1, 1);
  Point p6(-1, 0);
  std::cout << "p5 : " << p5 << std::endl;
  p5.reflex(p6);
  std::cout << "Reflexed p5 " << p6 << " :  " << p5 << std::endl;

  Point p7(1, 1);
  Point p8(2, 2);
  Line line(p7, p8);
  Point p9(3, 0);
  std::cout << "p9 : " << p9 << std::endl;
  p9.reflex(line);
  std::cout << "Reflexed line :  " << line << " :  " << p9 << std::endl;

  Point center(1, 0);
  Point p10(1, 1);
  double scale = 5;
  std::cout << "p10 : " << p10 << std::endl;
  p10.scale(center, scale);
  std::cout << "Scaled :  " << center << " :  " << p10 << std::endl;

  std::cout << std::endl;
}

void testLineClass() {
  Point p1(1.0, 2.0);
  Point p2(3.0, -.0);
  Point p3(9.0, 6.0);

  Line line1(p1, p2);
  Line line2(p2, p3);
  Line line3(1.0, -3.0);
  Line line4(p2, 1.5);

  std::cout << "Test Line class:\n";
  std::cout << "line1: " << line1 << "\n";
  std::cout << "line2: " << line2 << "\n";
  std::cout << "line3: " << line3 << "\n";
  std::cout << "line4: " << line3 << "\n";

  std::vector<Line> lines = {line1, line2, line3, line4};
  for (auto it : lines) {
    for (auto jt : lines) {
      std::cout << it << " <==> " << jt << " - " << (it == jt) << " !"
                << (it != jt) << std::endl;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void testPolygonRectangle() {
  Point p1(-3, 2);
  Point p2(1, 2);
  Point p3(1, -1);
  Point p4(-3, -1);

  Polygon poly(p1, p2, p3, p4);
  Polygon poly2(p2, p3, p4, p1);
  std::cout << "Poly " << poly << " " << poly.verticesCount() << " Convex - "
            << poly.isConvex() << std::endl;
  for (auto it : poly.getVertices()) {
    std::cout << it << " ";
  }
  std::cout << std::endl;
  std::cout << "Perimeter " << poly.perimeter() << std::endl;
  std::cout << "Area " << poly.area() << std::endl;
  std::cout << "Poly2 " << poly2 << " " << poly2.verticesCount() << " Convex - "
            << poly2.isConvex() << std::endl;
  std::cout << " == " << (poly2 == poly) << std::endl;
  std::cout << "IsConguruent " << poly.isCongruentTo(poly2) << std::endl;
  std::cout << "IsSimilarTo " << poly.isSimilarTo(poly2) << std::endl;
  Point pt1(0, 0), pt2(10, 10);
  std::cout << pt1 << " contains? " << poly.containsPoint(pt1) << std::endl;
  std::cout << pt2 << " contains? " << poly.containsPoint(pt2) << std::endl;

  Point center(0, 0);
  double angle = 90;
  poly.rotate(center, angle);
  std::cout << "Rotated to " << angle << " from " << center << " Poly " << poly
            << std::endl;

  poly.reflex(center);
  std::cout << "Reflex  from " << center << " Poly " << poly << std::endl;

  Point center2(1, 1);
  Line line(center, center2);
  poly.reflex(line);
  std::cout << "Reflexed  from " << line << " Poly " << poly << std::endl;

  double scale = 5;
  poly.scale(center, scale);
  std::cout << "Scaled to " << scale << " from " << center << " Poly " << poly
            << std::endl;
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
  std::cout << "Poly " << poly << " " << poly.verticesCount() << " Convex - "
            << poly.isConvex() << std::endl;
  for (auto it : poly.getVertices()) {
    std::cout << it << " ";
  }
  std::cout << std::endl;
  std::cout << "Perimeter " << poly.perimeter() << std::endl;
  std::cout << "Area " << poly.area() << std::endl;
  std::cout << "Poly2 " << poly2 << " " << poly2.verticesCount() << " Convex - "
            << poly2.isConvex() << std::endl;
  std::cout << " == " << (poly2 == poly) << std::endl;
  std::cout << "IsConguruent " << poly.isCongruentTo(poly2) << std::endl;
  std::cout << "IsSimilarTo " << poly.isSimilarTo(poly2) << std::endl;
  Point pt1(0, 0), pt2(10, 10);
  std::cout << pt1 << " contains? " << poly.containsPoint(pt1) << std::endl;
  std::cout << pt2 << " contains? " << poly.containsPoint(pt2) << std::endl;

  Point center(0, 0);
  double angle = 90;
  poly.rotate(center, angle);
  std::cout << "Rotated to " << angle << " from " << center << " Poly " << poly
            << std::endl;

  poly.reflex(center);
  std::cout << "Reflex  from " << center << " Poly " << poly << std::endl;

  Point center2(1, 1);
  Line line(center, center2);
  poly.reflex(line);
  std::cout << "Reflex  from " << line << " Poly " << poly << std::endl;

  double scale = 5;
  poly.scale(center, scale);
  std::cout << "Scaled to " << scale << " from " << center << " Poly " << poly
            << std::endl;
}

void testEllipseClass() {
  Point p1(1.0, 2.0);
  Point p2(3.0, 4.0);

  Ellipse ellipse(p1, p2, 7.0);
  Ellipse ellipse2(p1 + p2, p2 - p1, 7.0);

  std::cout << "Test Ellipse class:\n";
  std::cout << "Ellipse eccentricity: " << ellipse.eccentricity() << "\n";
  std::cout << "Ellipse focuses: " << ellipse.focuses().first << ", "
            << ellipse.focuses().second << "\n\n";
  auto directrices = ellipse.directrices();
  std::cout << "Directruces : " << directrices.first << ", "
            << directrices.second << std::endl;
  std::cout << "Center " << ellipse.center() << std::endl;

  std::cout << std::endl;
  std::cout << "Perimeter " << ellipse.perimeter() << std::endl;
  std::cout << "Area " << ellipse.area() << std::endl;
  std::cout << " == " << (ellipse2 == ellipse) << std::endl;
  std::cout << "IsConguruent " << ellipse.isCongruentTo(ellipse2) << std::endl;
  std::cout << "IsSimilarTo " << ellipse.isSimilarTo(ellipse2) << std::endl;
  Point pt1(2, 3), pt2(15, 15);
  std::cout << pt1 << " contains? " << ellipse.containsPoint(pt1) << std::endl;
  std::cout << pt2 << " contains? " << ellipse.containsPoint(pt2) << std::endl;

  Point center(0, 0);
  double angle = 90;
  ellipse.rotate(center, angle);
  std::cout << "Rotated to " << angle << " from " << center << " ellipse "
            << ellipse << std::endl;

  ellipse.reflex(center);
  std::cout << "Reflex  from " << center << " ellipse " << ellipse << std::endl;

  Point center2(1, 1);
  Line line(center, center2);
  ellipse.reflex(line);
  std::cout << "Reflex  from " << line << " ellipse " << ellipse << std::endl;

  double scale = 5;
  ellipse.scale(center, scale);
  std::cout << "Scaled to " << scale << " from " << center << " ellipse "
            << ellipse << std::endl;
}

void testCircleClass() {
  Point center(1.0, 1.0);
  Circle circle(center, 5.0);
  Circle circle2(center * 2, 5.0);

  std::cout << "Test Circle class:\n";
  std::cout << "Circle radius: " << circle.radius() << std::endl;

  std::cout << "Circle eccentricity: " << circle.eccentricity() << "\n";
  std::cout << "circle focuses: " << circle.focuses().first << ", "
            << circle.focuses().second << "\n\n";

  auto directrices = circle.directrices();
  std::cout << "Directruces : " << directrices.first << ", "
            << directrices.second << std::endl;

  std::cout << "Center " << circle.center() << std::endl;

  std::cout << std::endl;
  std::cout << "Perimeter " << circle.perimeter() << std::endl;
  std::cout << "Area " << circle.area() << std::endl;
  std::cout << " == " << (circle2 == circle) << std::endl;
  std::cout << "IsConguruent " << circle.isCongruentTo(circle2) << std::endl;
  std::cout << "IsSimilarTo " << circle.isSimilarTo(circle2) << std::endl;
  Point pt1(2, 3), pt2(15, 15);
  std::cout << pt1 << " contains? " << circle.containsPoint(pt1) << std::endl;
  std::cout << pt2 << " contains? " << circle.containsPoint(pt2) << std::endl;

  center.x = 0;
  center.y = 0;
  double angle = 90;
  circle.rotate(center, angle);
  std::cout << "Rotated to " << angle << " from " << center << " circle "
            << circle << std::endl;

  circle.reflex(center);
  std::cout << "Reflex  from " << center << " circle " << circle << std::endl;

  Point center2(1, 1);
  Line line(center, center2);
  circle.reflex(line);
  std::cout << "Reflex  from " << line << " circle " << circle << std::endl;

  double scale = 5;
  circle.scale(center, scale);
  std::cout << "Scaled to " << scale << " from " << center << " circle "
            << circle << std::endl;
}

void testRectangleClass() {
  Point p1(1.0, 2.0);
  Point p2(3.0, -1.0);

  Point p3(3.0, 3.0);
  Point p4(4.0, 8.0);

  Rectangle rect(p1, p2);
  Rectangle rect1(p3, p4);

  std::cout << "Rectangle class " << std::endl;
  std::cout << rect << std::endl;
  std::cout << "Center - " << rect.center() << std::endl;
  std::cout << "Perimeter - " << rect.perimeter() << std::endl;
  std::cout << "Area - " << rect.area() << std::endl;
  std::cout << "Operator ==" << (rect == rect1) << std::endl;
  std::cout << "IsCongruent -" << rect.isCongruentTo(rect1) << std::endl;
  std::cout << "IsSimilar - " << rect.isSimilarTo(rect1) << std::endl;
  Point pt1(2, 0.5), pt2(10, 10);

  std::cout << pt1 << " contains? " << rect.containsPoint(pt1) << std::endl;
  std::cout << pt2 << " contains? " << rect.containsPoint(pt2) << std::endl;

  Point center(0, 0);

  double angle = 90;
  rect.rotate(center, angle);
  std::cout << "Rotated to " << angle << " from " << center << " rect " << rect
            << std::endl;

  rect.reflex(center);
  std::cout << "Reflex  from " << center << " rect " << rect << std::endl;

  Point center2(1, 1);
  Line line(center, center2);
  rect.reflex(line);
  std::cout << "Reflex  from " << line << " rect " << rect << std::endl;

  double scale = 5;
  rect.scale(center, scale);
  std::cout << "Scaled to " << scale << " from " << center << " rect " << rect
            << std::endl;
}

void testSquareClass() {
  Point p1(-2, -2);
  Point p2(2, 2);

  Square square(p1, p2);
  Square square1(p1 - p2, p1 + p2);

  std::cout << "Square class " << std::endl;
  std::cout << square << std::endl;
  std::cout << "CircumscribedCircle"
            << " " << square.circumscribedCircle() << std::endl;
  std::cout << "InscribedCircle"
            << " " << square.inscribedCircle() << std::endl;

  std::cout << "IsConvex - " << square.isConvex() << std::endl;
  std::cout << "Center - " << square.center() << std::endl;
  std::cout << "Diagonals - " << square.diagonals().first << " "
            << square.diagonals().second << std::endl;
  std::cout << "Perimeter - " << square.perimeter() << std::endl;
  std::cout << "Area - " << square.area() << std::endl;
  std::cout << "Operator ==" << (square == square1) << std::endl;
  std::cout << "IsCongruent -" << square.isCongruentTo(square1) << std::endl;
  std::cout << "IsSimilar - " << square.isSimilarTo(square1) << std::endl;
  Point pt1(2, 2), pt2(10, 10);

  std::cout << pt1 << " contains? " << square.containsPoint(pt1) << std::endl;
  std::cout << pt2 << " contains? " << square.containsPoint(pt2) << std::endl;

  Point center(0, 0);

  double angle = 90;
  square.rotate(center, angle);
  std::cout << "Rotated to " << angle << " from " << center << " square "
            << square << std::endl;

  square.reflex(center);
  std::cout << "Reflex  from " << center << " square " << square << std::endl;

  Point center2(1, 1);
  Line line(center, center2);
  square.reflex(line);
  std::cout << "Reflex  from " << line << " square " << square << std::endl;

  double scale = 5;
  square.scale(center, scale);
  std::cout << "Scaled to " << scale << " from " << center << " square "
            << square << std::endl;
}

void testTriangleClass() {
  Point p1(-2.0, -2.0);
  Point p2(0, 2.0);
  Point p3(2, -2.0);

  Triangle triangle(p1, p2, p3);
  Triangle triangle2(p1 * 2, p2 * 2, p3 * 2);

  std::cout << "Trinagle " << triangle << " " << triangle.verticesCount()
            << " Convex - " << triangle.isConvex() << std::endl;
  for (auto it : triangle.getVertices()) {
    std::cout << it << " ";
  }
  std::cout << std::endl;

  std::cout << "Test Triangle class:\n";
  std::cout << "Triangle circumscribed circle center: "
            << triangle.circumscribedCircle() << "\n";
  std::cout << "Triangle inscribedCircle circle center: "
            << triangle.inscribedCircle() << "\n";
  std::cout << "Triangle centroid: " << triangle.centroid() << "\n";
  std::cout << "Triangle orthocenter: " << triangle.orthocenter() << "\n";
  std::cout << "Triangle Euler line: " << triangle.EulerLine() << "\n";
  std::cout << "Triangle nine points circle center: "
            << triangle.ninePointsCircle().center() << "\n\n";

  std::cout << "Perimeter " << triangle.perimeter() << std::endl;
  std::cout << "Area " << triangle.area() << std::endl;
  std::cout << "triangle2 " << triangle2 << " " << triangle2.verticesCount()
            << " Convex - " << triangle2.isConvex() << std::endl;
  std::cout << " == " << (triangle2 == triangle) << std::endl;
  std::cout << "IsConguruent " << triangle.isCongruentTo(triangle2)
            << std::endl;
  std::cout << "IsSimilarTo " << triangle.isSimilarTo(triangle2) << std::endl;
  Point pt1(0, 0), pt2(10, 10);
  std::cout << pt1 << " contains? " << triangle.containsPoint(pt1) << std::endl;
  std::cout << pt2 << " contains? " << triangle.containsPoint(pt2) << std::endl;

  Point center(0, 0);
  double angle = 90;
  triangle.rotate(center, angle);
  std::cout << "Rotated to " << angle << " from " << center << " triangle "
            << triangle << std::endl;

  triangle.reflex(center);
  std::cout << "Reflex  from " << center << " triangle " << triangle
            << std::endl;

  Point center2(1, 1);
  Line line(center, center2);
  triangle.reflex(line);
  std::cout << "Reflex  from " << line << " triangle " << triangle << std::endl;

  double scale = 5;
  triangle.scale(center, scale);
  std::cout << "Scaled to " << scale << " from " << center << " triangle "
            << triangle << std::endl;
}

void runTests() {
  testPointClass();
  std::cout << "======================TEST0======================" << std::endl;
  testLineClass();
  std::cout << "======================TEST1======================" << std::endl;
  testPolygonRectangle();
  std::cout << "======================TEST2======================" << std::endl;
  testPolygonClass();
  std::cout << "======================TEST3======================" << std::endl;
  testEllipseClass();
  std::cout << "======================TEST4======================" << std::endl;
  testCircleClass();
  std::cout << "======================TEST5======================" << std::endl;
  testRectangleClass();
  std::cout << "======================TEST6======================" << std::endl;
  testSquareClass();
  std::cout << "=======================TEST7=====================" << std::endl;
  testTriangleClass();
  std::cout << "=======================TEST8=====================" << std::endl;
}
