#pragma once
#ifndef POLYNOMIAL_KARTIK_H
#define POLYNOMIAL_KARTIK_H
#include <iostream>
using namespace std;

class Polynomial
{
	friend ostream &operator<<(ostream &, const Polynomial &);	
public:
	Polynomial(int = 0, double = 0.0);
	void setPoly(int, double);
	void operator+(Polynomial&);
	void operator-(Polynomial&);
	void operator=(Polynomial&);
	void operator*(Polynomial&);
	void operator+=(Polynomial&);
	void operator-=(Polynomial&);
	void operator*=(Polynomial&);
	~Polynomial();

private:
	double poly[13] = { 0.0 };		//The polynomial can have decimal coeeficient, also, to include multiplication coeffcients, make it 13
	int exp;						//exp are always integers	
	double coeff;					//coeff can be double
};
#endif
