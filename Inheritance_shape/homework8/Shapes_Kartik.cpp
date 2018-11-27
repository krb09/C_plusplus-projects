#include "pch.h"
#include "Shapes_Kartik.h"
#include <iostream>
using namespace std;
shapes_kartik::shapes_kartik(double a, double b)
{
	setx_cor(a);				//so that other classes use them efficiently
	sety_cor(b);				
}
void shapes_kartik::setx_cor(double a)
{
	x_cor = a;
}
void shapes_kartik::sety_cor(double b)
{
	y_cor = b;
}
double shapes_kartik::getx_cor() const
{
	return x_cor;
}
double shapes_kartik::gety_cor() const
{
	return y_cor;
}
void shapes_kartik::print() const
{
	cout << "The centre of the shape is: "<<"[" << getx_cor() << "," << gety_cor() << "]\n";
}