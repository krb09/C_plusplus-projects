#include "pch.h"
#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "two_dim.h";
class triangle : public two_dim
{
public:
	triangle(double = 0.0, double = 0.0, double = 0.0);			//default constructor
	void set_side(double);
	double get_side() const;
	double get_area()const;
	void print() const;
private:
	double side;
};
#endif // !TRIANGLE_H
