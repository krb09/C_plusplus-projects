#pragma once
#ifndef SHAPES_KARTIK_H
#define SHAPES_KARTIK_H
class shapes_kartik							//base class 1
{
public:
	shapes_kartik(double =0.0,double=0.0);			//default constructor
	void setx_cor(double);
	void sety_cor(double);
	double getx_cor() const;
	double gety_cor() const;;
	virtual void print() const;					//defined a virtual function to implement print function. POLYMORPHISM
private:
	double x_cor;
	double y_cor;
};
#endif // !SHAPES_KARTIK_H
