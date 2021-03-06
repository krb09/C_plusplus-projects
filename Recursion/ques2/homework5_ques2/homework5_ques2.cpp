// Submitted by Rattan, Kartik 187001624 on 11/10/2018
// Peg Puzzle- Most difficult question until now !! 

#include "pch.h"
#include <iostream>
using namespace std;

bool puzzle_peg(int[], int, int);
void insert(int[], int *);
void display(int[], int);

int a;
int main()
{
	int size=0;
	int a[100];
	insert(a, &size);
	int peg = 0;
	bool k = puzzle_peg(a, peg, size);				
	if (k)				// if function return a true value
	{
		cout << "There is a solution.\n\n";
	}
	else
	{
		cout << "No solution\n\n";
	}
	return 0;
}
bool puzzle_peg(int x[], int k, int max)
{
	if (x[k] == 0)				// k is at value 0 position. This is our base case. Also our solution in first case
	{
		return true;
	}

	int left_limit = k - x[k];				// Move the peg left
	int right_limit = k + x[k];				// Move the peg right

	if(right_limit< max && puzzle_peg(x,right_limit,max))		//recursive call  // If you move the peg right, it is less than size and you find a solution
	{
	return true;
	}

	if (left_limit > 0 && puzzle_peg(x, left_limit, max))		//recursive call  // If you move the peg left, it is greater than 0 and there is a solution
	{
		return true;
	}
	return false;										// Else no solution, return false
}

void insert(int x[],int *b)
{
	cout << "Enter the elements of the puzzle: \n";
	do
	{
		cin >> x[*b];
		*b = *b + 1;
	} while (x[*b-1] != 0);
	display(x, *b);
	return;
}

void display(int x[], int b)
{
	cout << "Your puzzle is: \n";
	for (int i = 0; i < b; i++)
	{
		cout << x[i] << " ";
	}
	cout << "\n";
}