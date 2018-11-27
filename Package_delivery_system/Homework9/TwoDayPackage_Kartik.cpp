//Submitted by Kartik Rattan, 187001624
//Package delievery- Polymorphism
#include "pch.h"
#include "TwoDayPackage.h"
using namespace std; 

TwoDayPackage::TwoDayPackage(double wt, double c_wt, double ff)
	:package(wt,c_wt)					// define the constructor for base class package
{
	set_flatfee(ff);
}
void TwoDayPackage::set_flatfee(double ff)				//set a flat fee for using this service
{
	flatfee_tdp = (ff < 0.0 ? 0.0 : ff);
}
double TwoDayPackage::get_flatfree() const
{
	return flatfee_tdp;
}
double TwoDayPackage::calculateCost()				//redefine the calculate cost vistual function
{
	double total_cost_tdp = getweight()*getcost_weight() + flatfee_tdp;
	return total_cost_tdp;
}
string TwoDayPackage::packagetype() const				//display the name of the service type
{
	return "Delivery Service: Two Day Package";
}