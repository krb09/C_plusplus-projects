#pragma once
#ifndef TETRAHEDRON_KARTIK_H
#define TETRAHEDRON_KARTIK_H
#include "three_dim.h"
class tetrahedron : public three_Dim
{
public:
	tetrahedron(double = 0.0, double = 0.0, double = 0.0, double = 0.0);
	void set_side(double);
	double get_side() const;
	double get_Area() const;
	double get_Volume() const;
	void print() const;
	~tetrahedron();
private:
	double side;
};
#endif