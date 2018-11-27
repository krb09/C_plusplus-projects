//Submitted by Kartik Rattan, 187001624
//Package delievery- Polymorphism
#pragma once
#ifndef PACKAGE_H
#define PACKAGE_H
#include<string>
using namespace std;
class package
{
public:
	package(double=0.0,double=0.0);					//constructor for package
	void setweight(double);							//series of get and set functions for package datamembers
	double getweight() const;

	void setcost_weight(double);
	double getcost_weight() const;

	void setname(string);
	string getname() const;

	void setaddress(string);
	string getaddress() const;

	void setcity(string);
	string getcity() const;

	void setstate(string);
	string getstate() const;

	void setzip(string);
	string getzip() const;

	//reciever information
	void r_setname(string);
	string r_getname() const;

	void r_setaddress(string);
	string r_getaddress() const;

	void r_setcity(string);
	string r_getcity() const;

	void r_setstate(string);
	string r_getstate() const;

	void r_setzip(string);
	string r_getzip() const;

	virtual double calculateCost();
	virtual string packagetype() const;

private:
	string name;						//string name, adress,city and state for a sender
	string address;
	string city;
	string state;
	string zip;							

	string r_name;						//string name, adress,city and state for a reciever
	string r_address;
	string r_city;
	string r_state;
	string r_zip;

	double weight;
	double cost_weight;
};
#endif // !PACKAGE_H
