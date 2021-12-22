#pragma once
#include <iostream>
#include "info.h"
using namespace std;
class node {
	friend class request;
	friend class server;
	friend class avl_tree;
private:
	info account;
	int height;
	node * right;
	node * left;
public:
	node();
	node(node&);
	node& operator = (node&);
	node(info);
	bool check_pass(string);
	void send_req(node*);
	string get_name();
	void edit_profile();
	int notfication();
	int size_req(request);
	void send_message(string, node*);
	int notficatin_m();
	void see_messages(node*);

};
