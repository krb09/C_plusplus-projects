// Kartik Rattan- 187001624
// Submitted on 21st September, 2018

#include "pch.h"
#include<iostream>
#include<time.h>               // To us the function time(0) for different seed values of rand
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<cmath>               // to include the sqrt function to calculate the distance

using namespace std;
int main()
{
	int itR;                                                                //number of iterations needed
	ofstream file;                                                          // generating an object file to open the file in the end and store the coordinates
	srand(static_cast<unsigned int>(time(0)));                              //Generating the seed value according to the time in the systems in  seconds
	double x_cor, y_cor;                                                     //Def the two coordinates DOUBLE IS USED TO MAKE THEM HAVE DECIMAL VALUES

// For x and y coordinate
	double pie;                                                                 // Def a variable pie
	do
	{
		cout << "Enter the number of iterations needed(should be greater than 100), you would be prompted again if the value is not close to the expected value: ";    // Prompt the user to enter the number of iterations or number of points generated
		cin >> itR;
		file.open("mytxt_x,ycor.txt");                                                // Generate and open a file and store the coordinates in it
		int counter = 0;                                                            // Defining a counter to track the number of points outside the circle of radius 1
		for (int i = 0; i < itR; i++)
		{
			x_cor = static_cast<double>(rand()) / (RAND_MAX);            //you have to make the range of the coordinates from (0,1), therefore divide by the max value
			y_cor = static_cast<double>(rand()) / (RAND_MAX);
			file << setprecision(5) << fixed << x_cor << ',' << y_cor << "\n";         // fixed to avoid scientific notation, set Prec to set the number of values after decimal point
			double radius = sqrt(((x_cor)*(x_cor)) + ((y_cor)*(y_cor)));     // The origin is (0,0) the distance b/w (x,y) and (0,0) is actually the radius
			if (radius > 1)                                             // If the radius is greater than 1, the points are outside the circle. COunter increases by one to keep track
			{
				counter = counter + 1;
			}
		}
		file.close();                                          // Close the file for security reasons
		pie = 4 * ((static_cast<double>(itR) - counter) / itR);   //Monte carlo method, pie = 4 times the number of points inside the circle/total number of points.

	} while (pie > static_cast<double>(3.16) || pie < static_cast<double>(3.12));     // to avoid random values and keeping the approximate value as close as possible to 3.14
	cout << "The value of Pie is: " << pie << "\n";
	return 0;
}

