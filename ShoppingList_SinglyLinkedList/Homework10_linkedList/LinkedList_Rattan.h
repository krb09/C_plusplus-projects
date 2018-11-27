//Rattan, Kartik 187001624. I wanted to write the class without using the operator :: this time
//Shopping list using linked list
#pragma once
#ifndef LINKEDLIST_RATTAN_H
#define LINKEDLIST_RATTAN_H
#include "ListNode_Rattan.h";
#include<iostream>
#include <string>
#include<iomanip>
using namespace std;
class List
{
public:
	List()												//constructor
		:firstptr(nullptr), lastptr(nullptr)
	{
	}
	~List()												//destructor
	{
		if (!isEmpty())
		{
			ListNode *currentptr = firstptr;
			ListNode *tempptr = nullptr;
			while (currentptr != nullptr)			//used to iterate through all objects ******MOST IMPORTANT LINES: 20 AND 24 for LISTS******
			{
				tempptr = currentptr;
				cout << "Deleted the node with value:" << tempptr->data<<"\n";
				currentptr = currentptr->nxtptr;
				delete tempptr;							//tempptr has the address of currentptr, therefore deleted
			}
		}
	}
	void insertAtFront(const int &value,string s)			//You can declare and DEFINE the function over here as well
	{
		ListNode *newptr = getNewNode(value,s);
		if (isEmpty())
		{
			firstptr = lastptr = newptr;
		}
		else
		{
			newptr->nxtptr = firstptr;
			firstptr = newptr;
		}
		print();
	}
	bool isEmpty() const
	{
		return firstptr == nullptr;
	}
	void insertAtBack(const int &value,string s)
	{
		ListNode *newptr = getNewNode(value,s);
		if (isEmpty())
		{
			firstptr = lastptr = newptr;
		}
		else
		{
			lastptr->nxtptr = newptr;
			lastptr = newptr;
		}
		print();
	}
	bool removeFromFront()
	{
		int value;
		if (isEmpty())
		{
			print();
			return false;      //There wasnt anything, therefore delete unsuccessful
		}
		else
		{
			ListNode *tempptr = firstptr;				//FIRST IMP STEP
			if (firstptr == lastptr)
			{
				firstptr = lastptr = nullptr;   //just one element
			}
			else
				firstptr = firstptr->nxtptr;			//SECOND IMP STEP

			value = tempptr->data;
			delete tempptr;								//THIRD IMP STEP
			print();
			return true;
		}
	}
	bool removeFromLast()					//important is to fig the second last node
	{
		int value;
		if (isEmpty())
		{
			print();
			return false;
		}
		else
		{
			ListNode *tempptr = lastptr;
			if (firstptr == lastptr)
			{
				firstptr = lastptr = nullptr;
			}
			else
			{
				ListNode *currentptr = firstptr;
				while (currentptr->nxtptr != lastptr)
				{
					currentptr = currentptr->nxtptr;
				}

				lastptr = currentptr;
				currentptr->nxtptr = nullptr;
			}
			value = tempptr->data;
			delete tempptr;
			print();
			return true;
		}
	}
	bool remove_item_number(int a)
	{
		ListNode *tempptr = firstptr;
		ListNode *prevptr = firstptr;
		if (isEmpty())								//empty list
		{
			print();
			return false;	
		}
		else
		{
			if (firstptr == lastptr)				//just one item and it is removed
			{
				firstptr = lastptr = nullptr;
				print();
				return true;
			}
			else if (tempptr->data == a)			//The item is at first node
			{
				firstptr = tempptr->nxtptr;
				delete tempptr;
				print();
				return true;
			}
			else
			{
				while (tempptr->nxtptr != nullptr && tempptr->data != a)			//scan through
				{
					prevptr = tempptr;
					tempptr = tempptr->nxtptr;
				}
				if (tempptr->nxtptr == nullptr && tempptr->data != a)	//item not present		
				{
					cout << "Item not found.\n";
					print();
					delete tempptr;
					return false;
				}
				else if(prevptr==lastptr && tempptr->data==a)			//the value is at last node
				{
					prevptr->nxtptr = nullptr;
					lastptr = prevptr;
					print();
					delete tempptr;
					return true;
				}
				else                                 //the node is in between
				{
					prevptr->nxtptr = tempptr->nxtptr;
					print();
					delete tempptr;
					return true;
				}
			}
		}
	}
	bool remove_item_name(string a)
	{
		ListNode *tempptr = firstptr;
		ListNode *prevptr = firstptr;
		if (isEmpty())								//empty list
		{
			print();
			return false;
		}
		else
		{
			if (firstptr == lastptr)				//just one item and it is removed
			{
				firstptr = lastptr = nullptr;
				print();
				return true;
			}
			else if (tempptr->name == a)			//The item is at first node
			{
				firstptr = tempptr->nxtptr;
				delete tempptr;
				print();
				return true;
			}
			else
			{
				while (tempptr->nxtptr != nullptr && tempptr->name != a)			//scan through
				{
					prevptr = tempptr;
					tempptr = tempptr->nxtptr;
				}
				if (tempptr->nxtptr == nullptr && tempptr->name != a)	//item not present		
				{
					cout << "Item not found.\n";
					print();
					delete tempptr;
					return false;
				}
				else if (prevptr == lastptr && tempptr->name == a)			//the value is at last node
				{
					prevptr->nxtptr = nullptr;
					lastptr = prevptr;
					print();
					delete tempptr;
					return true;
				}
				else                                 //the node is in between
				{
					prevptr->nxtptr = tempptr->nxtptr;
					print();
					delete tempptr;
					return true;
				}
			}
		}
	}
	void print() const
	{
		if (isEmpty())
		{
			cout << "The list is empty.\n";
		}

		ListNode *currentptr = firstptr;
		cout << "The list is: \n";
		cout << "Item Number  " << "Item Name\n";
		while (currentptr != nullptr)
		{
			cout << setw(11)<<currentptr->data << "  "<<currentptr->name<<"\n";
			currentptr = currentptr->nxtptr;
		}
		cout << "\n\n";
	}

private:
	ListNode *firstptr;				//They are of the type ListNode, but they dont have any value. You can think of them as engines
	ListNode *lastptr;
	ListNode* getNewNode(const int value, string s)				//utility functions
	{
		return new ListNode(value,s);
	}
};
#endif

