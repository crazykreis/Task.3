// queue.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

/// \fn class queue
class queue 
{
public:
	queue() : next(nullptr), data("") {};
	~queue() {if (next!=nullptr) delete next;}
	void add(string inputdata);
	void del();
	void get();
private:
	queue* next;
	string data;
} Queue;

/// \fn add element
void queue::add(string inputdata) 
{
	if (next == nullptr)
		if (data != "")
		{
			next = new queue();
		}
		else 
		{
			data = inputdata;
			return;
		}
		next->add(data);
		data = inputdata;
}

/// \fn delete element
void queue::del() {
	if (next == nullptr) 
	{
		data = "";
		return;
	}
	else
		next->del();
}

/// \fn get element
void queue::get() 
{
	if (next == nullptr) 
	{
		cout << data << endl;
		return;
	}
	next->get();
}

/// \fn Main function of application
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
			Queue.add(inputdata);
		}
		else if (namefunction == "get")
		{
			Queue.get();
		}
		else if (namefunction == "del")
		{
			Queue.del();
		}
		else
			return 1;
	}
	return 0;
}

