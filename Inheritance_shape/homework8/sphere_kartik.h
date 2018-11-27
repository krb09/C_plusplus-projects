#pragma once
#ifndef SPHERE_H
#define SPEHER_H
#include "three_Dim.h"
class sphere : public three_Dim  //this inherits all the member from 3D shapes
{
public:
	sphere(double = 0.0, double = 0.0, double = 0.0, double = 0.0);
	void set_radius(double);
	double get_radius() const;
	double get_area() const;
	double get_volume() const;
	void print() const;
	~sphere();
private:
	double rad_sphere;
};
#endif // !SPHERE_H
