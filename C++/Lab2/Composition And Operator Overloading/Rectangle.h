#pragma once

#include "Point.h"

class Rectangle
{
private:
    Point upperLeftVertex;
    double height, width;
public:
    Rectangle(Point p1, Point p2) :
        upperLeftVertex(p1),
        height(p2.getY() - p1.getY()), width(p2.getX() - p1.getX()) {}
    Rectangle(Point p1, double height, double width) : 
        upperLeftVertex(p1),
        height(height), width(width) {}
    Point getUpperLeftVertex();
    double getWidth();
    double getHeight();
    double getArea();
    double getPerimeter();
    Point getCenter();
    void shift(double, double);
    bool contains(Point);
};