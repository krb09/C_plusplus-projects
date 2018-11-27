//Submitted by Kartik Rattan, 187001624
//Package delievery- Polymorphism
#include "pch.h"
#include "package_rattan.h"
#pragma once
#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

class OvernightPackage : public package
{
public:
	OvernightPackage(double=0.0, double=0.0, double = 0.0);		 //default constuctor
	void set_flatfee(double);				//set a flat fee for this service
	double get_flatfree() const;
	double calculateCost();
	string packagetype() const;

private:
	double flatfee_op;
};
#endif // !OVERNIGHTPACKAGE_H
