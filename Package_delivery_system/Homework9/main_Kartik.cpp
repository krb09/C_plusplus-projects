//Submitted by Kartik Rattan, 187001624
//Package delievery- Polymorphism

#include "pch.h"
#include <iostream>
#include<vector>
#include<string>
using namespace std; 
#include "package_rattan.h"			//include all the header files for different classes
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

void print(package *);

int main()
{
	vector<package *> array_ptr(3);  //define a vector of package pointer to move through different objects
	package base(5.5,5.0);
	TwoDayPackage der_1(3.0,5.0,10.0);
	OvernightPackage der_2(4.5,5.0,15.0);
	array_ptr[0] = &base;			//define each vector member as one of the object address
	array_ptr[1] = &der_1;
	array_ptr[2] = &der_2;
	cout << "Package delivery system\n";
	cout << "Cost for standard delivery = 5$\n";
	cout << "Additional cost for 2 day delivery = 10$\n";
	cout << "ADditional Cost for overnight delivery = 15$\n\n";

	base.setname("Scott Mckirgan");						//set the address for all the customers
	base.setaddress("0376-A Buell Apartments");
	base.setcity("Piscataway");
	base.setstate("New Jersey");
	base.setzip("00854");

	base.r_setname("Mareesh Kumar");
	base.r_setaddress("7 Bag End");
	base.r_setcity("Hobbiton");
	base.r_setstate("Shire");
	base.r_setzip("12345");

	der_1.setname("Kartik Rattan");
	der_1.setaddress("Number 4 Privet Drive");
	der_1.setcity(" Little Whinging");
	der_1.setstate("Surrey");
	der_1.setzip("58785");

	der_1.r_setname("Udayan Anand");
	der_1.r_setaddress("350 Johnson Apartments");
	der_1.r_setcity("Piscataway");
	der_1.r_setstate("New Jersey");
	der_1.r_setzip("58785");

	der_2.setname("Mareesh Kumar");
	der_2.setaddress("7 Bag End");
	der_2.setcity("Hobbiton");
	der_2.setstate("Shire");
	der_2.setzip("12345");

	der_2.r_setname("Bruce Wayne");
	der_2.r_setaddress("Wayne Manor");
	der_2.r_setcity("Gotham");
	der_2.r_setstate("DC CITY");
	der_2.r_setzip("77777");

	double total_cost=0.0;
	for (int i = 0; i < array_ptr.size(); i++)				//loop through the vector and rpint for each of the object
	{
		print(array_ptr[i]);
		total_cost = total_cost + array_ptr[i]->calculateCost();
	}
	cout << "The total amount is: " << total_cost<<"$\n\n";				//Display the total cost in the end
	return 0;
}
void print(package *p)					//function package to print the information. Pointer of type package used to access all the members
{
	cout<<"SENDER:"<< p->getname() << "\n"
		<< p->getaddress() << " "
		<< p->getcity() << "\n"
		<< p->getstate() << " "
		<< p->getzip() << "\n\n"
		<<"RECIEVER:"<< p->r_getname() << "\n"
		<< p->r_getaddress() << " "
		<< p->r_getcity() << "\n"
		<< p->r_getstate() << " "
		<< p->r_getzip() << "\n\n"
		<< p->packagetype() << "\n"
		<<"Weigth of the package: "<<p->getweight()<<"\n"
		<< "Cost for delivery: "<<p->calculateCost()<<"$\n"
		<< "X----------------------------------------------X\n\n";
}