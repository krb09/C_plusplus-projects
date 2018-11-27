#include "pch.h"
#include<iostream>
#include "circle.h"
using namespace std;

circle::circle(double a, double b, double r)
	:two_dim(a,b)
{
	set_rad(r);
}

void circle::set_rad(double r)
{
	radius = (r < 0.0 ? 0.0 : r);				//check the radius if its positive or not
}
double circle::get_rad() const
{
	return radius;
}
double circle::get_area() const
{
	return (3.14159*get_rad()*get_rad());
}
void circle::print() const
{
	cout << "The circle has a center:" << "[" << getx_cor() << "," << gety_cor() << "] and a radius:" << get_rad() << "units\n"; //using get functions, it is easier to use the private members of class 2D
}