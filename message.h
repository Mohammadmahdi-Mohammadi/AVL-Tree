













/*#pragma once
#include <iostream>
#include <vector> 
#include <string>
using namespace std;

//#include "message.h" 

struct message
{
	int priority;
	string text;
	long long from;
};
class messages_heap {
private:
	vector<message> messages;
public:
	messages_heap();
	//	messages_heap(int);
	void Max_Heapify(int);
	void Insert(message&);
};
	//void Increase_Key(int, int); 	
	 	
/*	message& Extract_Max(); 	
	int Parent(int); 	
	int Right_Child(int); 	
	int Left_Child(int); 	
	bool isEmpty(); 	
	int Size(); 	
	void write(ofstream&); };*/
