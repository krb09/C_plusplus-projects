//Kartik Rattan
//Submitted on 2nd October, 2018

#include "pch.h"
#include <iostream>
#include<iomanip>
#include<cmath>    // To include the pow method

using namespace std;
void insert(int[][10], int &, int &);						// PROTOTYPE DEFINATIONS
void display(int[][10], int, int);
void Addition(int[][10], int, int, int[][10], int, int);
void Subtraction(int[][10], int, int, int[][10], int, int);
void Multiplication(int[][10], int, int, int[][10], int, int);
int Determinant_3X3_only(int[][10],int &,int &);
int determinant3X3(int[]);						    // To calculate deter_value 3X3
int determinant2X2(int[]);                         // To calculate the cofactors
void Inverse(int[][10],int &,int &);
void Transpose(int[][10], int, int);
int row1, row2;      //row of the matrix,initiated to zero
int col1, col2;	  //Column of the matrix, initiated to zero
int main()
{
	int x[10][10]; // a 10X10 container matrix is formed
	int y[10][10];	
	int ID;        // ID for switch statements
	int row1, row2;      //row of the matrix,initiated to zero
	int col1, col2;	  //Column of the matrix, initiated to zero
	do
	{
		cout << "MENU:\n" << "Below is the list of available operations. Select the corresponding ID to perform an operation.\n\n";
		cout << "ID" << setw(12) << "OPERATION\n";		
		cout << setw(2) << "1   " << "Addition\n";
		cout << setw(2) << "2   " << "Subtraction\n";
		cout << setw(2) << "3   " << "Multiplication\n";
		cout << setw(2) << "4   " << "Determinant(3x3 ONLY!)\n";
		cout << setw(2) << "5   " << "Inverse(3x3 ONLY!)\n";
		cout << setw(2) << "6   " << "Transpose\n";
		cout << setw(2) << "9   " << "QUIT\n";
		cout << "Enter the ID: \n";
		cin >> ID;										 // Prompt the user to select an application 
		switch (ID)											// Switch network
		{
		case 1:
			insert(x, row1, col1);            // Prompt the user to enter a matrix
			display(x, row1, col1);			//display that matrix
			insert(y, row2, col2);
			display(y, row2, col2);
			Addition(x, row1, col1, y, row2, col2);
			cout << "\n\n\n";
			break;
		case 2:
			insert(x, row1, col1);
			display(x, row1, col1);
			insert(y, row2, col2);
			display(y, row2, col2);
			Subtraction(x, row1, col1, y, row2, col2);
			cout << "\n\n\n";
			break;
		case 3:
			insert(x, row1, col1);
			display(x, row1, col1);
			insert(y, row2, col2);
			display(y, row2, col2);
			Multiplication(x, row1, col1, y, row2, col2);
			cout << "\n\n\n";
			break;
		case 4:
			insert(x, row1, col1);
			Determinant_3X3_only(x,row1,col1);
			cout << "\n\n";
			break;
		case 5:
			insert(x, row1, col1);
				int inv_check;
				inv_check = Determinant_3X3_only(x,row1,col1);
				if (inv_check == 0)                                 // Inverse of a matrix with det=0 does not exist
				{
					cout << "Inverse cannot be calculated\n\n";
				}
				else
				{
					cout << "Step1: Transpose\n";
					Transpose(x, row1, col1);
					cout << "Step2: Cofactor and divison with determinant\n\n";
					Inverse(x,row1,col1);
					cout << "\n\n";
				}
			break;
		case 6:
			insert(x, row1, col1);
			display(x, row1, col1);
			Transpose(x, row1, col1);
			cout << "\n\n\n";
			break;
		}
	} while (ID != 9);							// To continue the matrix calculator until the user enter quits the application
	cout << "\n" << "Thank you for using Matrix Calculator" << "\n";
	return 0;
}
// INSERT 
void insert(int k[][10], int &a, int &b)     //Although named k, its actually a reference for array x, same for variable a and b
{
	cout << "Enter the number of rows required for the matrix_1: ";
	cin >> a;
	cout << "Enter the number of columns required for the matrix_1: ";
	cin >> b;
	cout << "Enter the elements for your matrix: \n";
	for (int i = 0; i < a; i++)
	{												// Inserting elements in the matrix using 2 for loops
		for (int j = 0; j < b; j++)
		{
			cin >> k[i][j];
		}
	}
}
//DISPLAY
void display(int k[][10], int a, int b)
{
	cout << "Matrix: \n";
	for (int i = 0; i < a; i++)							// Diplaying elements in the matrix using 2 for loops
	{
		for (int j = 0; j < b; j++)
		{
			cout << setw(3) << k[i][j];
		}
		cout << "\n";
	}
}
// ADITION FUNCTION
void Addition(int k1[][10], int a1, int b1, int k2[][10], int a2, int b2)
{
	if (a1 == a2 && b1 == b2)								//To check for equal dimensions
	{
		{
			for (int i = 0; i < a1; i++)
				for (int j = 0; j < b1; j++)
				{
					k1[i][j] = k1[i][j] + k2[i][j];
				}
		}
		cout << "Addition ";
		display(k1, a1, b1);
	}
	else
	{
		cout << "\nERROR: Addition cannot be computed. Make sure the dimensions are same.\n";
	}
}
//SUBTRACTION FUNCTION 
void Subtraction(int k1[][10], int a1, int b1, int k2[][10], int a2, int b2)
{
	if (a1 == a2 && b1 == b2)									//To check for equal dimensions
	{
		{
			for (int i = 0; i < a1; i++)
				for (int j = 0; j < b1; j++)
				{
					k1[i][j] = k1[i][j] - k2[i][j];
				}
		}
		cout << "Subtraction ";
		display(k1, a1, b1);
	}
	else
	{
		cout << "\nERROR: Subtraction cannot be computed. Make sure the dimensions are same.\n";
	}
}
//Multiplication FUNCTION 
void Multiplication(int k1[][10], int a1, int b1, int k2[][10], int a2, int b2)
{
	if (b1 == a2)							// for multiplication, number of columns in first should be equal to number of rows in second
	{
		int k[10][10] = { 0 };
		{
			for (int i = 0; i < a1; i++)     // I should be less than the row 1 
				for (int j = 0; j < b2; j++) //J should be less than the column 2
				{
					for (int p = 0; p < a2; p++)	 //K should be less than row 1
					{
						k[i][j] += (k1[i][p])*(k2[p][j]);
					}

				}
		}
		cout << "Multiplication ";
		display(k, a1, b2);
	}
	else
	{
		cout << "\nERROR: Multiplication cannot be computed. Make sure the dimensions are same.\n";
	}
}
//DETERMINANT FOR 3X3 ONLY
int Determinant_3X3_only(int det[][10], int &a, int &b)
{	
	if (a == 3 && b == 3) {
		int row = 0;							//Loop counter for each element
		int col = 0;							//Loop counter for each element
		int deter_temp[3];						

		int d = 0;								// counters for deter_temp arrays to move.
		do
		{
			int k = 0;
			int x[4] = { 0 };		//temp array to calculate 2X2 det
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
				{
					if (i != row && j != col)
					{
						x[k] = det[i][j];
						k = k + 1;
					}
				}
			deter_temp[d] = det[row][col] * determinant2X2(x);
			d = d + 1;
			col = col + 1;
		} while (col < 3);
		int temp = determinant3X3(deter_temp);
		cout << "DETERMINANT: " << determinant3X3(deter_temp) << "\n\n";
		return temp;
	}
	else
	{
		cout << "Determinant cannot be calculated, enter a 3X3 matrix next time.\n\n";
		return 0;
	}
}
//Determinant calculation_ supplement 1
int determinant2X2(int a[])
{
	int total = (a[0] * a[3]) - (a[1] * a[2]);
	return total;
}
//Determinant calculation2_supplement 2
int determinant3X3(int a[])
{
	int total = 0;
	for (int i = 0; i < 3; i++)
	{
		if (i == 1)
		{
			total = total - a[i];
		}
		else
			total = total + a[i];
	}
	return total;
}

//INVERSE of a 3X3 matrix only
void Inverse(int inv[][10],int &a,int &b)
{	
	if (a == 3 && b == 3) {
		int y[10][10];								//Array to store the cofactor of matrix						
		int row = 0;
		int col = 0;
		while (row < 3 && col < 3)
		{
			int k = 0;
			int x[4] = { 0 };		//temp array to calculate 2X2 det
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
				{
					if (i != row && j != col)
					{
						x[k] = inv[i][j];
						k = k + 1;
					}
				}
			y[row][col] = (pow(-1, (row + col)))*determinant2X2(x);
			if (col == 2)
			{
				col = 0;
				row = row + 1;
			}
			else
				col = col + 1;
		}
		int r1 = 3;
		int c1 = 3;
		int temp_1 = Determinant_3X3_only(inv, r1, c1);
		cout << "\nStep3: The inverse of the matrix is: \n\n";
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << setw(6) << fixed << setprecision(4) << (static_cast<double>(y[i][j])) / temp_1 << " ";						// Divide here by determinant to find the inverse
				if (j == 2)
					cout << "\n";
			}
		}
	}
	else
	{
		cout << "Inverse cannot be calculated, enter a 3X3 matrix next time.\n";
	}
}

//Transpose
void Transpose(int k1[][10], int a1, int b1)
{
	int temp[10][10];
	for (int i = 0; i < b1; i++)     // this is now your column. We are going column wise to each element
	{
		for (int j = 0; j < a1; j++)
		{
			{
				temp[i][j] = k1[j][i];    //j and I have interchanged to go not row by row, but col by col

			}

		}
	}
	cout << "Transpose ";
	display(temp, b1, a1);
}

