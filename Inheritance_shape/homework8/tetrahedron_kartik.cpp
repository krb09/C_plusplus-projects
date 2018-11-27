#include "pch.h"
#include "tetrahedron_kartik.h"
#include <iostream>
using namespace std;

tetrahedron::tetrahedron(double a, double b, double c, double s)
	:three_Dim(a,b,c)
{
	set_side(s);
}
void tetrahedron::set_side(double sd)
{
	side = (sd < 0 ? 0.0 : sd);
}
double tetrahedron::get_side() const
{
	return side;
}
double tetrahedron::get_Area() const
{
	return (static_cast<double>(sqrt(3)) * get_side() * get_side());
}
double tetrahedron::get_Volume() const
{
	return ((get_side() * get_side() * get_side()) / static_cast<double>((6 * sqrt(2))));
}
void tetrahedron::print() const
{
	cout << "The tetrahedron has a center:" << "[" << getx_cor() << "," << gety_cor() << "," << getz_cor() << "] and a side:" << get_side() << "units\n";
}
tetrahedron::~tetrahedron()
{

}