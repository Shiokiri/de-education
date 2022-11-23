#include <iostream>

#include "Rectangle.h"
#include "MyComplex.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    //Point
    cout << "--- test class Point ---" << endl;
    cout << endl;
    Point p1(1.3, 1.7);
    cout << "p1:"; p1.print();
    cout << "p1.getX():" << p1.getX() << endl;
    cout << "p1.getY():" << p1.getY() << endl;
    cout << "p1.distanceTo(Point(3.7, 3.2)):" << p1.distanceTo(Point(3.7, 3.2)) << endl;
    cout << "p1.isSameAs(Point(1.3, 1.7)):" << p1.isSameAs(Point(1.3, 1.7)) << endl;
    cout << "p1.isSameAs(Point(1.2, 2.4)):" << p1.isSameAs(Point(1.2, 2.4)) << endl;
    cout << "p1.translate(2, -3)......" << endl; p1.translate(2, -3);
    cout << "p1:"; p1.print();
    cout << endl;
    //Rectangle
    cout << "-- test class Rectangle ---" << endl;
    cout << endl;
    Rectangle r1(p1, 2.7, 2.2);
    cout << "r1.getWidth():" << r1.getWidth() << endl;
    cout << "r1.getHeight():" << r1.getHeight() << endl;
    cout << "r1.getArea():" << r1.getArea() << endl;
    cout << "r1.getPerimeter():" << r1.getPerimeter() << endl;
    cout << "r1.getUpperLeftVertex():"; r1.getUpperLeftVertex().print();
    cout << "r1.getCenter():"; r1.getCenter().print();
    cout << "r1.shift(4.5, 6.7)......" << endl;  r1.shift(4.5, 6.7);
    cout << "r1.getUpperLeftVertex():"; r1.getUpperLeftVertex().print();
    cout << "r1.contains(Point(2.3, 8.7)):" << r1.contains(Point(2.3, 8.7)) << endl;
    cout << "r1.contains(Point(7.9, 5.3)):" << r1.contains(Point(7.9, 5.3)) << endl;
    cout << endl;
    //MyComplex
    cout << "--- test class MyComplex ---" << endl;
    cout << endl;
    MyComplex c1(1.2, -1.5);
    MyComplex c2(7.6, 8.7);
    MyComplex c3(2.5, 0);

    cout << "c1:" << c1 << endl;
    cout << "c2:" << c2 << endl;
    cout << "c3:" << c3 << endl;

    cout << "c1 + c2:" << c1 + c2 << endl;
    cout << "c1 - c2:" << c1 - c2 << endl;
    cout << "c1 * c2:" << c1 * c2 << endl;
    cout << "c1 / c2:" << c1 / c2 << endl;

    c1 += c2;
    cout << "c1 += c2:" << c1 << endl;
    c1 -= c2;
    cout << "c1 -= c2:" << c1 << endl;
    c1 *= c2;
    cout << "c1 *= c2:" << c1 << endl;
    c1 /= c2;
    cout << "c1 /= c2:" << c1 << endl;

    c1++;
    cout << "c1++:" << c1 << endl;
    c1--;
    cout << "c1--:" << c1 << endl;
    ++c1;
    cout << "++c1:" << c1 << endl;
    --c1;
    cout << "--c1:" << c1 << endl;

    cout << "c1 == c2:" << (c1 == c2) << endl;
    cout << "c1 != c2:" << (c1 != c2) << endl;
    cout << "c1 == 1.2-1.5i:" << (c1 == MyComplex(1.2, -1.5)) << endl;
    cout << "c1 != 1.2-1.5i:" << (c1 != MyComplex(1.2, -1.5)) << endl;
    
    MyComplex c4;
    cin >> c4; // -1.5+1i
    cout << "input:" << c4 << endl;
    cin >> c4; // 1.5+0i
    cout << "input:" << c4 << endl;
    cin >> c4; // 1.5+5.6i
    cout << "input:" << c4 << endl;
    cin >> c4; // 1.5-7.2i
    cout << "input:" << c4 << endl;
    cin >> c4; // 0+0i
    cout << "input:" << c4 << endl;

    cout << endl;
}