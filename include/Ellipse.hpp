#pragma once

#include "Shape.hpp"

class Ellipse : public Shape {
public:
    Ellipse(const Point& focus1, const Point& focus2, double sumOfDistances);
    virtual ~Ellipse();
    
    std::pair<Point, Point> focuses() const;
    std::pair<Line, Line> directrices() const;
    double eccentricity() const;
    Point center() const;

    //* Shape class methods
    double perimeter() const override;
    double area() const override;
    bool operator==(const Shape& another) const override;
    bool operator!=(const Shape& another) const override;
    bool isCongruentTo(const Shape& another) const override;
    bool isSimilarTo(const Shape& another) const override;
    bool containsPoint(const Point& point) const override;
    void rotate(const Point& center, double angle) override;
    void reflex(const Point& center) override;
    void reflect(const Line& axis) override;
    void scale(const Point& center, double coefficient) override;

    friend std::ostream& operator<<(std::ostream& out, const Ellipse& ellipse);

private:
    Point focus1_;
    Point focus2_;
    double sum_of_distances_;
};

