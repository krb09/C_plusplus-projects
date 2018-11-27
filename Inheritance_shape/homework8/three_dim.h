#ifndef THREE_DIM_H
#define THREE_DIM_H
#include "Shapes_Kartik.h"
class three_Dim : public shapes_kartik						//inherits from class shapes
{
public:
	three_Dim(double = 0.0, double = 0.0, double = 0.0);
	void setz_cor(double);
	double getz_cor() const;
	void print() const;
private:
	double z_cor;				//extension of shapes. More extensive, contains a member data more than base class shapes
};
#endif