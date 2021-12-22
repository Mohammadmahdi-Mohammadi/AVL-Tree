#pragma once
#include <iostream>
#include "avl_tree.h"
#include "node.h"
#include "message.h"
#include "info.h"
using namespace std;

class server {
	friend class node;
	friend class messages_heap;
	avl_tree * tree; // all person
	node * user;   // user
public:
	server();
	server(avl_tree*, node *);
	 bool check_s(long long, string); // 1- username   2- password
	 void send_req(long long); // number of the person who send request
	 void send_message(string, long long); // 1-message  2- to (number)
	 void edit_last_message(string); // new text
};