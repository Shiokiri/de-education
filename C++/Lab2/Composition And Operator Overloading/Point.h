#pragma once

class Point
{
private:
	double x, y;
public:
	Point() : x(0), y(0) {}
	Point(double startX, double startY) : x(startX), y(startY) {}
	void translate(double, double);
	double getX();
	double getY();
	double distanceTo(Point);
	bool isSameAs(Point);
	void print();
};