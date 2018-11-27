#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include "two_dim.h";
class circle : public two_dim				//inherits from two_dim and thus from shapes as well
{
public:
	circle(double = 0.0, double = 0.0, double = 0.0);
	void set_rad(double);
	double get_rad() const;
	double get_area()const ;
	void print() const;
private:
	double radius;
};
#endif // !CIRCLE_H
