//Submitted by Kartik Rattan, 187001624
//Package delievery- Polymorphism
#include "pch.h"
#include "package_rattan.h"
#include<iostream>
#include<string>
using namespace std;

package::package(double wt, double c_wt)
{
	setweight(wt);
	setcost_weight(c_wt);
}
void package::setweight(double w)
{
	weight = (w < 0.0 ? 0.0 : w);
}
double package::getweight() const
{
	return weight;
}

void package::setcost_weight(double cw)
{
	cost_weight = (cw < 0.0 ? 0.0 : cw);
}
double package::getcost_weight() const
{
	return cost_weight;
}

void package::setname(string n)
{
	name = n;
}
string package::getname() const
{
	return name;
}

void package::setaddress(string a)
{
	address = a;
}
string package::getaddress() const
{
	return address;
}

void package::setcity(string c)
{
	city = c;
}
string package::getcity() const
{
	return city;
}

void package::setstate(string s)
{
	state = s;
}
string package::getstate() const
{
	return state;
}

void package::setzip(string z)
{
	zip = z;
}
string package::getzip() const
{
	return zip;
}
double package::calculateCost()
{
	double totalcost = getweight() * getcost_weight();
	return totalcost;
}
string package::packagetype() const
{
	return "Delivery Service: Standard Package";
}

//reciever information 

void package::r_setname(string n)
{
	r_name = n;
}
string package::r_getname() const
{
	return r_name;
}

void package::r_setaddress(string a)
{
	r_address = a;
}
string package::r_getaddress() const
{
	return r_address;
}

void package::r_setcity(string c)
{
	r_city = c;
}
string package::r_getcity() const
{
	return r_city;
}

void package::r_setstate(string s)
{
	r_state = s;
}
string package::r_getstate() const
{
	return r_state;
}

void package::r_setzip(string z)
{
	r_zip = z;
}
string package::r_getzip() const
{
	return r_zip;
}
