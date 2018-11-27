//Rattan, Kartik 187001624
#pragma once
#ifndef LISTNODE_RATTAN_H
#define LISTNODE_RATTAN_H
#include<string>
using namespace std;
class ListNode
{
friend class List;					//List is a friend class
public:
	ListNode(const int &value, string s)
		:data(value), name(s), nxtptr(nullptr)
	{
	}
	int getData() const						//Becuase parameter of value is const, it will work with const 
	{
		return data;
	}
private:
	int data;
	string name;
	ListNode *nxtptr;
};
#endif // !LINKNODE_H
