// list.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

/// \fn class list
class list 
{
public:
	list(): next(nullptr), data("") {};
	~list() {if (next!=nullptr) delete next;}
	void add(int index, string namefunctiondata);
	void del(int index);
	void get(int index);
private:
	list* next;
	string data;
} List;

/// \fn add element
void list::add(int index, string namefunctiondata) 
{
	if (next == nullptr)
	{
		next = new list();
	}
	if (index == 0) 
	{
		data = namefunctiondata;
		return;
	}
	next->add(index - 1, namefunctiondata);
}

/// \fn delete element
void list::del(int index) 
{
	add(index, "");
}

/// \fn get element
void list::get(int index) 
{
	if (next == nullptr)
	{
		next = new list();
	}
	if (index == 0) 
	{
		cout << data << endl;
		return;
	}
	next->get(index - 1);
}

/// \fn main function
int main() {
	size_t size;
	int index;
	string namefunction;
	string inputdata;
	cin >> size;
	for (size_t i = 0; i < size; i++)
	{
		cin >> namefunction;
		if (namefunction == "add")
		{
			cin >> index >> inputdata;
			List.add(index, inputdata);
		}
		else if (namefunction == "del")
		{
			cin >> index;
			List.del(index);
		}
		else if (namefunction == "get")
		{
			cin >> index;
			List.get(index);
		}
		else
			return 1;
	}
	return 0;
}