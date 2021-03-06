//Rattan, Kartik- 187001624
//Recursive program to find the square of number n to 1 alternatively

#include "pch.h"
#include <iostream>
using namespace std;

void custom_square(int);
int main()
{
	int n;
	cout << "Enter the number: ";			// Prompt user to enter a number
	cin >> n;
	custom_square(n);
}
//Recursive function
void custom_square(int a)
{
	if (a > 0)					// N should be a postive number
	{
		if (a == 1)
		{
			cout << a;
			return;											//base case 
		}
		else if (a % 2 == 0)			// If N is a postive number
		{
			custom_square(a - 1);			//Recursive Call, square of positive numbers held in activation record
			cout << "," << a * a;
		}
		else
		{
			cout << a * a << ",";			// for odd value, printed first
			custom_square(a - 1);			//Recursive Call
		}
	}
	else
		cout << "Not a positive number! ";
}