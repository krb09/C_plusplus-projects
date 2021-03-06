// homework6_class_bookList.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Rattan, Kartik- 187001624

#include "pch.h"
#include <iostream>
#include "Booklist_rattan.h"			//Including header file
using namespace std;

int main()
{
	Booklist b1;						//declare an object of class Booklist
	int choice;
	do {
		cout << "Welcome to the book list program" << "\n" << "What would you like to do?\n";
		cout << "1. add an element to end of list\n"
			<< "2. add an element at a location\n"
			<< "3. find an element by ISBN number(linear search)\n"
			<< "4. find an element by ISBN number(binary search)\n"
			<< "5. delete an element at position\n"
			<< "6. delete an element by ISBN number\n"
			<< "7. sort the list(using selection sort)\n"
			<< "8. sort the list(using bubble sort)\n"
			<< "9. print the list\n"
			<< "0. exit\n";
		cout << "Your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			b1.insert();
			break;
		case 2:
			b1.insert_at();
			break;
		case 3:
			b1.find_linear();
			break;
		case 4:
			b1.find_binary();
			break;
		case 5:
			b1.delete_item_position();
			break;
		case 6:
			b1.delete_item_ISBN();
			break;
		case 7:
			b1.sort_selection();
			break;
		case 8:
			b1.sort_bubble();
			break;
		case 9:
			b1.display();
			break;
		case 0:
			break;
		}
	} while (choice != 0);
	return 0;
}

