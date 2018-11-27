#include "pch.h"
#include "sphere_kartik.h"
#include <iostream>
using namespace std;
sphere::sphere(double a, double b, double c, double r)
	:three_Dim(a,b,c)
{
	set_radius(r);
}

void sphere::set_radius(double rad)
{
	rad_sphere = (rad < 0.0 ? 0.0 : rad);
}
double sphere::get_radius() const
{
	return rad_sphere;
}
double sphere::get_area() const
{
	return (4 * 3.14159*get_radius()*get_radius());
}
double sphere::get_volume() const
{
	return ((4 * 3.14159 * get_radius() * get_radius() * get_radius()))/3;
}
void sphere::print() const
{
	cout << "The sphere has a center:" << "[" << getx_cor() << "," << gety_cor() << "," << getz_cor() << "] and a radius:" << get_radius() << "units\n";

}
sphere::~sphere()
{

}