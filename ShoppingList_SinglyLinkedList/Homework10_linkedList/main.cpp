//Rattan, Kartik 187001624
#include"pch.h"
#include"LinkedList_Rattan.h"    //include the header file for list		
#include<iostream>
#include<string>
using namespace std;
int main()
{
	List shoppinglist;				//create a object of the type list
	int choice;						
	int number;
	string s;
	do {
		cout << "Welcome to the shopping list program" << "\n" << "What would you like to do?\n";			//prompt user
		cout <<"1. add an element to the front of list\n"
			<< "2. add an element to the end of list\n"
			<< "3. remove the item from front of the list\n"
			<< "4. remove the item from end of the list\n"
			<< "5. remove the item from the list by entering the name\n"
			<< "6. remove the item from the list by entering the number\n"
			<< "7. print the list\n"
			<< "0. exit\n";
		cout << "Your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the item number:";
			cin >> number;
			cout << "Enter the item name:";
			cin >> s;
			shoppinglist.insertAtFront(number, s);
			break;
		case 2:
			cout << "Enter the item number:";
			cin >> number;
			cout << "Enter the item name:";
			cin >> s;
			shoppinglist.insertAtBack(number, s);
			break;
		case 3:
			shoppinglist.removeFromFront();
			break;
		case 4:
			shoppinglist.removeFromLast();
			break;
		case 5:
			if (shoppinglist.isEmpty())
			{
				shoppinglist.print();					//if the list is empty
			}
			else
			{
				cout << "Enter the item name:";					
				cin >> s;
				shoppinglist.remove_item_name(s);
			}
			break;
		case 6:
			if (shoppinglist.isEmpty())
			{
				shoppinglist.print();			//if the list is empty
			}
			else
			{
				cout << "Enter the item number:";
				cin >> number;
				shoppinglist.remove_item_number(number);
			}
			break;
		case 7:
			shoppinglist.print();
			break;
		case 0:
			break;
		}
	}while (choice != 0);
	return 0;
}