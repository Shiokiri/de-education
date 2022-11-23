#include <cmath>
#include <iostream>

#include "Point.h"

using std::cin;
using std::cout;
using std::endl;

void Point::translate(double xshift, double yshift)
{
    x += xshift;
    y += yshift;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

double Point::distanceTo(Point p)
{
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}

bool Point::isSameAs(Point other)
{
    return x == other.x && y == other.y;
}

void Point::print()
{
    cout << "Point:(" << x << "," << y << ")" << endl;
}