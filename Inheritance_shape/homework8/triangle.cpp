#include "pch.h"
#include<iostream>
#include "triangle.h"
#include<cmath>
using namespace std;

triangle::triangle(double a, double b, double s)
	:two_dim(a, b)
{
	set_side(s);
}

void triangle::set_side(double s)
{
	side = (s < 0.0 ? 0.0 : s);
}
double triangle::get_side() const
{
	return side;
}
double triangle::get_area() const
{
	return (static_cast<double>(sqrt(3)/4)*get_side()*get_side());
}
void triangle::print() const
{
	cout << "The triangle has a center:" << "[" << getx_cor() << "," << gety_cor() << "] and a side:" << get_side()<<"units\n";
}