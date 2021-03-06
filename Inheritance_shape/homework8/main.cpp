// homework8.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <iostream>
#include"triangle.h"
#include"circle.h"
#include"sphere_kartik.h"
#include"tetrahedron_kartik.h"
using namespace std;
int main()
{
	triangle t;
	circle c;
	sphere s;
	tetrahedron th;
	int choice;
	do
	{
		cout << "Select a shape:\n"
			<< "1. Circle\n"
			<< "2. Triangle\n"
			<< "3. Sphere\n"
			<< "4. Regular Tetrahedron\n"
			<< "0. Exit\n"
			<< "Enter you choice:";
		cin >> choice;
		double x;
		double y;
		double z;
		double len;
		switch (choice)
		{
		case 1:
			cout << "Enter the x-cordinate for the center of circle: ";
			cin >> x;
			c.setx_cor(x);
			cout << "Enter the y-cordinate for the center of circle: ";
			cin >> y;
			c.sety_cor(y);
			cout << "Enter the radius for the circle: ";
			cin >> len;
			c.set_rad(len);
			c.print();	
			cout << "The area of the circle is:" << c.get_area()<<" square units.\n";
			break;
		case 2:
			cout << "Enter the x-cordinate for the center of triangle: ";
			cin >> x;
			t.setx_cor(x);
			cout << "Enter the y-cordinate for the center of triangle: ";
			cin >> y;
			t.sety_cor(y);
			cout << "Enter the side for the triangle: ";
			cin >> len;
			t.set_side(len);
			t.print();
			cout<<"The area of the triangle is:"<<t.get_area() << " square units.\n";
			break;
		case 3:
			cout << "Enter the x-cordinate for the center of sphere: ";
			cin >> x;
			s.setx_cor(x);
			cout << "Enter the y-cordinate for the center of sphere: ";
			cin >> y;
			s.sety_cor(y);
			cout << "Enter the z-cordinate for the center of sphere: ";
			cin >> z;
			s.setz_cor(z);
			cout << "Enter the radius for the sphere: ";
			cin >> len;
			s.set_radius(len);
			s.print();
			cout << "The area of the sphere is:" << s.get_area() << " square units and the volume is:"<<s.get_volume()<<" cubic units.\n";
			break;
		case 4:
			cout << "Enter the x-cordinate for the center of tetrahedron: ";
			cin >> x;
			th.setx_cor(x);
			cout << "Enter the y-cordinate for the center of tetrahedron: ";
			cin >> y;
			th.sety_cor(y);
			cout << "Enter the z-cordinate for the center of tetrahedron: ";
			cin >> z;
			th.setz_cor(z);
			cout << "Enter the side for the tetrahedron: ";
			cin >> len;
			th.set_side(len);
			th.print();
			cout << "The area of the tetrahedron is:" << th.get_Area() << " square units and the volume is:" << th.get_Volume() << " cubic units.\n";
			break;
		case 0:
			break;
		}

	} while (choice != 0);
	return 0;
}
