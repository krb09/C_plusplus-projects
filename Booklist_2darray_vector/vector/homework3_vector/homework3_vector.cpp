//Kartik Rattan	
//Submitted on 2nd october 2018

#include "pch.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void insert(vector<vector<int>>&);					// PROTOTYPE DEFINATIONS
void display(vector<vector<int>>&);
void Addition(vector<vector<int>>&, vector<vector<int>>&);
void Subtraction(vector<vector<int>>&, vector<vector<int>>&);
void Multiplication(vector<vector<int>>&, vector<vector<int>>&);
int Determinant_3X3_only(vector<vector<int>>&);
int determinant3X3(vector<int> &);								// To calculate deter_value 3X3
int determinant2X2(vector<int> &);								// To calculate cofactors
void Inverse(vector<vector<int>> &);
void Transpose(vector<vector<int>> &);

int main()
{
	int ID;         // ID for switch statements

	do {
		vector<vector<int>> matrix1;              //container vectors
		vector<vector< int >>matrix2;
		cout << "\nMENU:\n" << "Below is the list of available operations. Select the corresponding ID to perform an operation.\n\n";
		cout << "ID" << setw(12) << "OPERATION\n";
		cout << setw(2) << "1   " << "Addition\n";
		cout << setw(2) << "2   " << "Subtraction\n";
		cout << setw(2) << "3   " << "Multiplication\n";
		cout << setw(2) << "4   " << "Determinant(3x3 ONLY!)\n";
		cout << setw(2) << "5   " << "Inverse(3x3 ONLY!)\n";
		cout << setw(2) << "6   " << "Transpose\n";
		cout << setw(2) << "9   " << "QUIT\n";
		cout << "Enter the ID: ";								// Prompt the user to select an application 
		cin >> ID;
		switch (ID)																	// Switch network
		{
		case 1:
			insert(matrix1);							// Prompt the user to enter a matrix
			display(matrix1);								//display that matrix
			insert(matrix2);
			display(matrix2);
			Addition(matrix1, matrix2);
			break;
		case 2:
			insert(matrix1);
			display(matrix1);
			insert(matrix2);
			display(matrix2);
			Subtraction(matrix1, matrix2);
			break;
		case 3:
			insert(matrix1);
			display(matrix1);
			insert(matrix2);
			display(matrix2);
			Multiplication(matrix1, matrix2);
			break;
		case 4:
			insert(matrix1);
			display(matrix1);
			Determinant_3X3_only(matrix1);
			cout << "\n\n";
			break;
		case 5:
			insert(matrix1);
			int inv_check;
			inv_check = Determinant_3X3_only(matrix1);
			if (inv_check == 0)											// Inverse of a matrix with det=0 does not exist
			{
				cout << "Inverse does not exist";
			}
			else
			{
				cout << "Step1: Transpose\n";
				Transpose(matrix1);
				cout << "Step2: Cofactor and divison with determinant\n";
				Inverse(matrix1);
				cout << "\n\n";
			}
			break;
		case 6:
			insert(matrix1);
			display(matrix1);
			Transpose(matrix1);
			break;
		}
	} while (ID != 9);									// To continue the matrix calculator until the user enter quits the application
	cout << "\n" << "Thank you for using Matrix Calculator" << "\n";
	return 0;
}
//INSERT 
void insert(vector<vector<int>> &a)
{
	int row;
	int col;
	cout << "Enter the number of rows: ";
	cin >> row;
	cout << "Enter the number of columns: ";
	cin >> col;
	cout << "Enter you matrix: \n";
	for (int i = 0; i < row; i++)							// Pushing elements in the matrix using 2 for loops
	{
		vector<int> temp;
		for (int j = 0; j < col; j++)
		{
			int c;
			cin >> c;
			temp.push_back(c);
		}
		a.push_back(temp);
	}
}
void display(vector<vector<int>> &dis)						// Diplaying elements in the matrix using 2 for loops
{
	cout << "Matrix:\n";
	for (int i = 0; i < dis.size(); i++) {
		for (int j = 0; j < dis[i].size(); j++) {
			cout << setw(4) << dis[i][j];
		}
		cout << "\n";
	}
}
//ADDITION FUNCTION
void Addition(vector<vector<int>> &a, vector<vector<int>> &b)
{
	if (a.size() == b.size() && a[0].size() == b[0].size())									//To check for equal dimensions
	{
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < a[i].size(); j++) {
				a[i][j] = a[i][j] + b[i][j];
			}
		}
		cout << "The addition of matrices: \n";
		display(a);
	}
	else
	{
		cout << "\nERROR: Addition cannot be computed. Make sure the dimensions are same.\n";
	}
}
//SUBTRACTION FUNCTION
void Subtraction(vector<vector<int>> &a, vector<vector<int>> &b)
{
	if (a.size() == b.size() && a[0].size() == b[0].size())									//To check for equal dimensions
	{
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < a[i].size(); j++) {
				a[i][j] = a[i][j] - b[i][j];
			}
		}
		cout << "The subtraction of matrices: \n";
		display(a);
	}
	else
	{
		cout << "\nERROR: Subtraction cannot be computed. Make sure the dimensions are same.\n";
	}
}
//MULTIPLICATION FUNCTION
void Multiplication(vector<vector<int>> &a, vector<vector<int>> &b)
{
	if (a[0].size() == b.size())			// for multiplication, number of columns in first should be equal to number of rows in second
	{
		vector<vector<int>> temp(a.size(), vector<int>(b[0].size()));
		{

			for (int i = 0; i < a.size(); i++)     // I should be less than the row 1 
				for (int j = 0; j < b[0].size(); j++) //J should be less than the column 2
				{
					for (int p = 0; p < b.size(); p++)	 //K should be less than row 1
					{
						temp[i][j] += (a[i][p])*(b[p][j]);
					}

				}
		}
		cout << "The multiplication of matrices is: \n";
		display(temp);
	}
	else
	{
		cout << "\nERROR: Multiplication cannot be computed. Make sure the dimensions are same.\n";
	}
}
//DETERMINANT 3X3
int Determinant_3X3_only(vector<vector<int>> &a)
{
	int k1 = a.size();
	int k2 = a[0].size();
	if (k1 == 3 && k2 == 3) {
		vector<int> deter_temp;
		int row = 0;							//Loop counter for each element
		int col = 0;							//Loop counter for each element
		do
		{
			int k = 0;
			vector<int>x;		//temp array to calculate 2X2 det
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
				{
					if (i != row && j != col)
					{
						x.push_back(a[i][j]);
						k = k + 1;
					}
				}
			deter_temp.push_back(a[row][col] * determinant2X2(x));
			col = col + 1;
		} while (col < 3);
		int temp = determinant3X3(deter_temp);
		cout << "DETERMINANT: " << determinant3X3(deter_temp) << "\n\n";
		return temp;
	}
	else
	{
		cout << "The determinant does not exist. Please enter a 3X3 matrix next time.\n";
		return 0;
	}
}
//Determinant calculation_ supplement 1
int determinant2X2(vector<int> &a)
{
	int total = (a[0] * a[3]) - (a[1] * a[2]);
	return total;
}
//Determinant calculation2_supplement 2
int determinant3X3(vector<int> &a)
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
//INVERSE FUNCTION
void Inverse(vector<vector<int>> &a)
{
	int k1 = a.size();
	int k2 = a[0].size();
	if (k1 == 3 && k2 == 3) {
		vector<vector<int>> temp;  //vector to store the cofac			 
		int row = 0;
		int col = 0;
		vector<int> temp3;
		while (row < 3 && col < 3)
		{
			vector<int> temp2;		//temp vector to calculate 2X2 det
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{

					if (i != row && j != col)
					{
						temp2.push_back(a[i][j]);
					}
				}
			}
			temp3.push_back((pow(-1, (row + col)))*determinant2X2(temp2));
			if (col == 2)
			{
				col = 0;
				row = row + 1;
				temp.push_back(temp3);
				temp3.pop_back();
				temp3.pop_back();
				temp3.pop_back();
			}
			else
				col = col + 1;
		}
		display(temp);

		int temp_1 = Determinant_3X3_only(a);
		cout << "Inverse of the matrix: \n";
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << setw(6) << fixed << setprecision(2) << (static_cast<double>(temp[i][j])) / temp_1 << " ";						// Divide here by determinant to find the inverse
				if (j == 2)
					cout << "\n";
			}
		}
	}
	else
	{
		cout << "Inverse cannot be calculated. Enter a 3X3 matrix next time.\n";
	}
}
//TRANSPOSE FUNCTION
void Transpose(vector<vector<int>> &a)
{
	vector<vector<int>> temp;
	for (int i = 0; i < a[0].size(); i++)
	{
		vector<int> temp2;
		for (int j = 0; j < a.size(); j++)
		{
			temp2.push_back(a[j][i]);
		}
		temp.push_back(temp2);
	}
	cout << "Transpose:\n";
	display(temp);
}
