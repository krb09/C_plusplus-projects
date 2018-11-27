#include "pch.h"
#include "Polynomial_Kartik.h"
#include <iostream>

using namespace std;

Polynomial::Polynomial(int pow, double base)
{
	setPoly(pow, base);
}

void Polynomial::setPoly(int pow, double base)
{
	poly[pow] = base;
}

ostream &operator<<(ostream &output, const Polynomial &a)
{
	int flag = 0;
	for (int i = 0; i < 13; i++)
	{
		if (a.poly[i] != 0.0 && flag == 0)
		{
			output << a.poly[i] << "x^" << i<<" ";
			flag = flag + 1;
		}
		else if(a.poly[i]!=0.0)
			output <<"+ "<< a.poly[i] << "x^" << i;
	}
	cout << "\n";
	return output;
}
void Polynomial::operator+(Polynomial &b)
{
	Polynomial result;
	for (int i = 0; i < 13; i++)
	{
		result.poly[i] = this->poly[i] + b.poly[i];
	}
	cout << "The addition of two polynomials give: ";
	cout << result;
}
void Polynomial::operator-(Polynomial &b)
{
	Polynomial result;
	for (int i = 0; i < 13; i++)
	{
		result.poly[i] = this->poly[i] - b.poly[i];
	}
	cout << "The addition of two polynomials give: ";
	cout << result;
}
void Polynomial::operator=(Polynomial& b)
{
	Polynomial result;
	for (int i = 0; i < 13; i++)
	{
		this->poly[i] = b.poly[i];
	}
	cout << "The assignment operator gives: ";
	cout << (*this);
}
void Polynomial::operator*(Polynomial &b)
{
	Polynomial result;
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 13; j++)
		{
			result.poly[i + j] += (this->poly[i])*(b.poly[j]);			//has to remember previous value also
		}
	cout << "The multiplication operator gives: ";
	cout << result;

}
void Polynomial::operator+=(Polynomial& b)
{
	Polynomial result;
	for (int i = 0; i < 13; i++)
	{
		this->poly[i] = this->poly[i] + b.poly[i];
	}
	cout << "The addition assignment operator gives: ";
	cout << (*this);
}
void Polynomial::operator-=(Polynomial& b)
{
	Polynomial result;
	for (int i = 0; i < 13; i++)
	{
		this->poly[i] = this->poly[i] - b.poly[i];
	}
	cout << "The subtraction assignment operator gives: ";
	cout << (*this);
}
void Polynomial::operator*=(Polynomial &b)
{
	Polynomial result;
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 13; j++)
		{
			result.poly[i + j] += (this->poly[i])*(b.poly[j]);	//has to remember previous value also
		}
	*this = result;
	cout << "The multiplication assignment operator gives: ";
	cout << (*this);
}

Polynomial::~Polynomial()
{
	cout << "Polynomial deleted\n";
}