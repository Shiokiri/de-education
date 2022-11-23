#include <iostream>

#include "Rectangle.h"

Point Rectangle::getUpperLeftVertex()
{
    return upperLeftVertex;
}

double Rectangle::getWidth()
{
    return width;
}

double Rectangle::getHeight()
{
    return height;
}

double Rectangle::getArea()
{
    return width * height;
}

double Rectangle::getPerimeter()
{
    return (width + height) * 2;
}

Point Rectangle::getCenter()
{
    return Point(upperLeftVertex.getX() + width / 2, upperLeftVertex.getY() - height / 2);
}

void Rectangle::shift(double x, double y)
{
    upperLeftVertex.translate(x, y);
}

bool Rectangle::contains(Point p)
{
    double x = p.getX(), y = p.getY();
    double rx = upperLeftVertex.getX(), ry = upperLeftVertex.getY();
    return x >= rx && x <= rx + width && y >= ry - height && y <= ry;
}