// Header file RATTAN, KARTIK 187001624
// Book_list

#pragma once
#ifndef BOOKLIST_RATTAN_H					// If the class is not already defined, define now
#define BOOKLIST_RATTAN_H
class Booklist
{
public:						//Public members
	Booklist();				
	void insert();		
	void insert_at();
	void display();			
	void find_linear();		
	void find_binary();
	void delete_item_position();
	void delete_item_ISBN();
	void sort_selection();
	void swap(int[], int, int);
	void sort_bubble();
private:
	int a[20];						//DATA MEMBERS- PRIVATE
	int num_elements;
	int sort_check = 0;
};

#endif
