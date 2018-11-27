//Submitted by Kartik Rattan, 187001624
//Package delievery- Polymorphism
#include "pch.h"
#include "OvernightPackage.h"
using namespace std;

OvernightPackage::OvernightPackage(double wt, double c_wt, double ff)
	:package(wt,c_wt)													// define the constructor for base class package
{
	set_flatfee(ff);
}
void OvernightPackage::set_flatfee(double ff)							//set a flat fee for using this service
{
	flatfee_op = (ff < 0.0 ? 0.0 : ff);
}
double OvernightPackage::get_flatfree() const
{
	return flatfee_op;
}
double OvernightPackage::calculateCost()							//redefine the calculate cost vistual function
{
	double total_cost_op = getweight()*getcost_weight() + flatfee_op;
	return total_cost_op;
}
string OvernightPackage::packagetype() const									//display the name of the service type
{
	return "Delivery Service: Overnight Package";
}