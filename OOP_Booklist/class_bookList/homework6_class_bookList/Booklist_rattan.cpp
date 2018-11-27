// Class definition RATTAN, KARTIK- 187001624

#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;
#include "Booklist_rattan.h"					//Including header file

Booklist::Booklist()			//Constructor
{
	a[20] = {0};				// Initializing data members
	num_elements = 0;
}

void Booklist::insert()	// The insert function wont require any parameteres from this. A object generate will have attached array and size
{
	int *n;
	n = &num_elements;						// I want to modify the num elements in this and avoid writing num_elements again n again
	if (*n == 20)
	{
		cout << "Number of elements: " << *n << "\n";
		display();
		cout << "The list is full. Delete some elements and try again.\n\n";
	}
	else
	{
		int b;
		int dup_post;							// to move the list if duplicate is present
		cout << "Enter an ISBN: ";
		cin >> b;

		if (*n == 0)		//If the list is empty, just add the new element at the first position
		{
			*a = b;
			++*n;       // Increase the count of number of elements
		}
		else {
			int flag = 0;					// help to find duplicate value
			for (int i = 0; i < *n; i++)
			{
				if (b == a[i])
				{
					dup_post = i;
					flag = 1;
				}
			}
			if (flag == 0)						//duplicate value not present
			{
				*(a + *n) = b;
				++*n;
			}
			else if (flag == 1)					// Delete the first one and move everything up	
			{
				for (int i = dup_post; i < *n - 1; i++)
				{
					a[i] = a[i + 1];
				}
				a[*n - 1] = b;
			}
		}
		cout << "Number of elements: " << *n << "\n";
		display();
	}
	sort_check = 0;									// Whenever we enter a number, we may have to sort again
}

void Booklist::insert_at()
{
	int *n;
	n = &num_elements;
		if (*n == 0)		//If the list is empty, just add the new element at the first position
		{
			int b;
			int post;										// I could have used *n but for loop will change it. Therefore made a copy.	Also defined post here.											
			cout << "Enter an ISBN: ";						//Also I need num_ele to increase at the end therefore I did not use directly call by vlaue.
			cin >> b;
			cout << "Enter a position from 1 to 20: ";
			cin >> post;
			post = post - 1;					//I HAD TO MODIFY MY LIST TO BE FROM 1-20
			if (post == 0)
			{
				*a = b;
				*n = *n + 1;
				display();
			}
			else
			{
				cout << "The position is out of bounds for the current list.\n\n";
			}
		}
		else if (*n != 20)									// to check if the list is not full
		{
			int counter_at = *n;
			int b;
			int post, dup_post;								// I could have used *n but for loop will change it. Therefore made a copy.	Also defined post here.											
			cout << "Enter an ISBN: ";						//Also I need num_ele to increase at the end therefore I did not use directly call by vlaue.
			cin >> b;
			cout << "Enter a position from 1 to 20: ";
			cin >> post;
			post = post - 1;						//I HAD TO MODIFY MY LIST TO BE FROM 1-20
			if (post <= *n)
			{
				int flag = 0;					// help to find duplicate value
				for (int i = 0; i < *n; i++)
				{
					if (b == a[i])
					{
						dup_post = i;
						flag = 1;
					}
				}
				if (flag == 0)
				{
					for (int i = counter_at; i > post - 1; i--)			// shift all the elemnts till position to right
					{
						a[i] = a[i - 1];
					}
					a[post] = b;
					*n = *n + 1;
					display();
				}
				else if (flag == 1)
				{
					for (int i = dup_post; i < *n - 1; i++)
					{
						a[i] = a[i + 1];
					}
					a[*n - 1] = b;
					display();
				}
			}
			else
			{
				cout << "The position is out of bounds for the current list.\n\n";
			}
		}
		else
		{
			cout << "The list is full. Delete some elements first and try again.\n\n";
		}
		sort_check = 0;
	
}

//FIND_LINEAR SEARCH
void Booklist::find_linear()
{
	int b = num_elements;				//Dont want to change, therefore not a pointer
	if (b != 0)
	{
		int key;
		int flag = 0;						// to check if the key is found
		cout << "Enter the key to be found: ";
		cin >> key;
		for (int i = 0; i < b; i++)
		{
			if (key == a[i])
			{
				cout << "Found the key=" << key << " at position: " << i+1 << "\n";
				flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << "The key is not present. \n";
		}
	}
	else
	{
		cout << "The list is empty!\n\n";
	}
}


void Booklist::find_binary()
{
	int b = num_elements;
	if (b != 0)
	{
		if (sort_check == 0)				//make the list sorted before calling in the binary search
		{
			cout << "The list needs to be sorted first before binary search.\n";
			sort_bubble();
		}
		else
		{
			cout << "The binary search is loading.....";
		}
		int key;
		int key_flag = 0;
		cout << "Enter the key you need to find: ";
		cin >> key;
		int l = 0;
		int h = b - 1;
		while (h >= l)
		{
			int mid = (l + h) / 2;
			if (key == a[mid])
			{
				cout << "The key " << key << " is found at position " << mid + 1 << ".\n";		//MAde mid = mid+1 to make list from 1 to 20
				key_flag = 1;
				break;
			}
			else if (key > a[mid])
			{
				l = mid + 1;
			}
			else
			{
				h = mid - 1;
			}
		}
		if (key_flag == 0)
		{
			cout << "The key is not present.\n";
		}
	}
	else
	{
		cout << "The list is empty! \n\n";
	}
}

//DELETE_ITEM_POSITION
void Booklist::delete_item_position()
{
	int *b;
	b = &num_elements;			//I want to change the number of elements because I am removing elements 
	if (*b != 0)
	{
		display();
		int post;
		cout << "Enter the position(1-20) of the element to be deleted: ";
		cin >> post;
		post = post - 1;	// Since the list is now 1-20, I have to subtract 1 from post
		if (post > *b - 1)							// To check if it wants to delete a position which is still not filled
		{
			cout << "No element at that position. \n";
		}
		else
		{
			for (int i = post; i < *b - 1; i++)
			{
				a[i] = a[i + 1];
			}
			*b = *b - 1;
			cout << "After deleting the element: ";
			display();
		}
	}
	else
	{
		cout << "The list is still empty. Cannot delete from an empty list.\n\n";
	}
}

//DELETE_ITEM_ISBN
void Booklist::delete_item_ISBN()
{
	int *b;
	b = &num_elements;
	if (*b != 0)
	{
		display();
		int post = -1, key;
		cout << "Enter the ISBN of the element to be deleted: ";
		cin >> key;
		for (int i = 0; i < *b; i++)				//To find the key so that the code becomes simpler
		{
			if (key == *(a + i))
			{
				post = i;
				break;
			}
		}
		if (post == -1)							// To check if it wants to delete a position which is still not filled
		{
			cout << "No such element in the list. \n";
		}
		else
		{
			for (int i = post; i < *b - 1; i++)
			{
				a[i] = a[i + 1];
			}
			*b = *b - 1;
			cout << "After deleting the element: ";
			display();
		}
	}
	else
	{
		cout << "The list is still empty. Cannot delete from an empty list.\n\n";
	}
}

// SELECTION SORT
void Booklist::sort_selection()
{
	int b = num_elements;
	if (b != 0)
	{
		for (int i = 0; i < b - 1; i++)
		{
			int minimum = *(a + i);								// Display the value of the array using a pointer																		
			int k = i;
			for (int j = i + 1; j < b; j++)
			{
				if (*(a + j) < minimum)									// Display the value of the array using a pointer
				{
					minimum = *(a + j);
					k = j;
				}
			}
			swap(a, k, i);
		}
		display();
		sort_check = 1;
	}
	else
	{
		cout << "Nothing inside the list to sort!\n\n";
	}

}
//SWAP
void Booklist::swap(int swap_a[], int swap_k, int swap_i)
{
	int temp = *(swap_a + swap_i);
	*(swap_a + swap_i) = *(swap_a + swap_k);
	*(swap_a + swap_k) = temp;
}


//BUBBLE SORT
void Booklist::sort_bubble()
{
	int b = num_elements;
	if (b != 0)
	{
		int flag = 1;
		for (int i = 0; (i < b - 1) && flag == 1; i++)
		{
			flag = 0;
			for (int j = 0; j < b - 1 - i; j++)
			{
				if (*(a + j) > *(a + j + 1))
				{
					int temp = *(a + j + 1);
					*(a + j + 1) = *(a + j);
					*(a + j) = temp;
					flag = 1;
				}
			}
		}
		display();
		sort_check = 1;
	}
	else
	{
		cout << "Nothing inside the list to sort!\n\n";
	}
}

void Booklist::display()
{
	int n = num_elements;
	if ( n!= 0)
	{
		cout << "Your list is now: \n";
		for (int i = 0; i < n; i++)
		{
			cout << i+1 << ". " << *(a + i) << "\n";		// Display the value of the array using a pointer
		}
		cout << "\n\n";
	}
	else {
		cout << "The list is empty!\n\n";
	}
}