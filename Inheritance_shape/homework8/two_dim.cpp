#include "pch.h"
#include "two_dim.h"
#include <iostream>
using namespace std;

two_dim::two_dim(double a, double b)
	:shapes_kartik(a, b)			//before 2d shapes constructor, the constructor for base class shapes is called setting X and Y
{

}
void two_dim::print() const
{
	cout << "The centre of the 2-D shape is: " << "[" << getx_cor() << "," << gety_cor() << "]";
}