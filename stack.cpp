// stack.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

/// \fn class stack
class stack 
{
public:
	stack(): next(nullptr), data("") {};
	~stack() {if (next!=nullptr) delete next;}
	void add(string namefunction);
	string del();
	void get();
private:
	stack* next;
	string data;
} Stack;

/// \fn add element
void stack::add(string namefunction) 
{
	if (next == nullptr)
		if (data != "") 
		{
			next = new stack();
		}
		else 
		{
			data = namefunction;
			return;
		}
		next->add(data);
		data = namefunction;
}

/// \fn delete element
string stack::del() 
{
	string temp = data;
	if (next != nullptr) 
	{
		data = next->del();
	}
	else 
	{
		data = "";
	}
	return temp;
}

/// \fn get element
void stack::get() 
{
	cout << data << endl;
}

/// \fn main function
int main() {
	size_t size;     
	string namefunction;
	string inputdata;
	cin >> size;
	for (size_t i = 0; i < size; i++)
	{
		cin >> namefunction;
		if (namefunction == "add")
		{
			cin >> inputdata;
			Stack.add(inputdata);
		}
		else if (namefunction == "get")
		{
			Stack.get();
		}
		else if (namefunction == "del")
		{
			Stack.del();
		}
		else
			return 1;
	}
	return 0;
}