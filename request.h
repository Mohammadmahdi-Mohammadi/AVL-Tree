#pragma once

#include <iostream>
using namespace std;

class request
{
	friend class info;
	friend class node;
	long long req[15];
	int rear, front;
public:
	request();
	void insert(int x);
	void delet();
	void display();	
	//bool isEmpty(node *);
};
