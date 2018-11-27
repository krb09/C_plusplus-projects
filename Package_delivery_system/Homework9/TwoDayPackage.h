//Submitted by Kartik Rattan, 187001624
//Package delievery- Polymorphism
#include "pch.h"
#include "package_rattan.h"
#pragma once
#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
class TwoDayPackage : public package
{
public:
	TwoDayPackage(double =0.0, double=0.0,double = 0.0);				//default constructor
	void set_flatfee(double);												//flat fee to use this service
	double get_flatfree() const;
	double calculateCost();
	string packagetype() const;

private:
	double flatfee_tdp;
};
#endif