#pragma once
#ifndef TWO_DIM_H
#define TWO_DIM_H
#include "Shapes_Kartik.h"
class two_dim : public shapes_kartik			//inherites from base class shapes_kartik (INHERITANCE)
{
public:
	two_dim(double=0.0, double=0.0);
	void print() const;
};
#endif // !TWO_DIM_H
