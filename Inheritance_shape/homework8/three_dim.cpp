#include "pch.h"
#include "three_dim.h"
#include <iostream>
using namespace std;

three_Dim::three_Dim(double a, double b, double c)
	:shapes_kartik(a, b)							//before the 3-D shape constructor, call the shapes constructor for x,y coord
{
	setz_cor(c);
}

void three_Dim::setz_cor(double c)
{
	z_cor = c;
}

double three_Dim::getz_cor() const
{
	return z_cor;
}

void three_Dim::print() const
{
	cout << "The centre of the 3-D shape is: " << "[" << getx_cor() << "," << gety_cor() <<","<<getz_cor()<< "] ";
}