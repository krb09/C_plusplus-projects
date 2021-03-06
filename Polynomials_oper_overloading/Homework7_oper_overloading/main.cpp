// Homework7_oper_overloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//	Rattan, Kartik- 187001624
// submitted on 2/11/2018

#include "pch.h"
#include <iostream>
#include "Polynomial_Kartik.h"
using namespace std;

int main()
{
	Polynomial p1;
	int term1;
	cout << "Enter number of polynomial terms for polynomial 1: \n";
	cin >> term1;
	while (term1 > 6)
	{
		cout << "Invalid number of terms. Enter the number of terms again: ";
		cin >> term1;
	}
	for (int i = 0; i < term1; i++)
	{
		int exp = 0;
		double coeff = 0.0;
		cout << "Enter the exponent: ";
		cin >> exp;
		cout << "Enter the coefficient: ";
		cin >> coeff;
		p1.setPoly(exp, coeff);
		cout << "\n";
	}
	cout << "Polynomial one: " << p1 << "\n";
	Polynomial p2;
	int term2;
	cout << "Enter number of polynomial terms for polynomial 2: \n";
	cin >> term2;
	while (term2 > 6)
	{
		cout << "Invalid number of terms. Enter the number of terms again: ";
		cin >> term2;
	}
	for (int i = 0; i < term2; i++)
	{
		int exp1 = 0;
		double coeff1 = 0.0;
		cout << "Enter the exponent: ";
		cin >> exp1;
		cout << "Enter the coefficient: ";
		cin >> coeff1;
		p2.setPoly(exp1, coeff1);
		cout << "\n";
	}
	cout << "Polynomial two: " << p2 << "\n";
	int choice;
	do
	{
		cout <<"1. The addition operator (+) to add two polynomials.\n"
			<< "2. The subtraction operator (-) to subtract two polynomials.\n"
			<< "3. The assignment operator to assign one polynomial to another.\n"
			<< "4. The multiplication operator (*) to multiply two polynomials.\n"
			<< "5. The addition assignment operator (+=).\n"
			<< "6. The subtraction assignment operator (-=).\n"
			<< "7. The multiplication assignment operator (*=).\n"
			<< "0. EXIT.\n";

		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			p1 + p2;
			break;
		}
		case 2:
			p1 - p2;
			break;
		case 3:
			p1 = p2;
			break;
		case 4:
			p1*p2;
			break;
		case 5:
			p1 += p2;
			break;
		case 6:
			p1 -= p2;
			break;
		case 7:
			p1 *= p2;
			break;
		case 0:
			break;
		}
	} while (choice != 0);
	return 0;
}