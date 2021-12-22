#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>
//#include "message.h"
#include "request.h"
using namespace std;

class info {
	friend class server;
	friend class request;
	friend class node;
	friend class avl_tree;
	
private:
	string name , f_name , password,last_message;
	int  priority;
	long long phone_number,last_message_number;
	//messages_heap  text;
	vector<long long> friends;  // list of friends
	vector<pair <string, long long>> messages; // 
	request freind_req;  // friend request list

public:
	info();
	info(string , string,string,long long,int);
	info(string, string, string, long long ,int, vector<long long>, request);// name , family name ,password , phone number , piority , friend list , request list
	info(string, string, string, long long, int,  vector<long long>, request, vector<pair <string, long long>>, string,long long);//  + messages_heap
};

/*
struct message
{
	//int priority;
	string text;
	long long from;
};*/