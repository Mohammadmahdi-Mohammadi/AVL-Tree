#include "server.h"

server::server()
{
	tree = NULL;
	user = NULL;

}

server::server(avl_tree *avl_tree, node *node_user)
{
	tree = avl_tree;
	user = node_user;
}

bool server::check_s(long long number, string pass)
{
	node* result;
	result = tree->search(number);
	if (result->account.password == pass) 
		return true;
	else
		return false;
}

void server::send_req(long long number)
{
	node* result;
	result = tree->search(number);
	result->account.freind_req.insert(user->account.phone_number);
}

void server::send_message(string mes, long long number)
{
	node* result;
	result = tree->search(number);
	result->account.last_message = mes;
	result->account.last_message_number = number;
	//result->account.text.Insert()
}

void server::edit_last_message(string edit_text)
{
	send_message("edited last meesage :", user->account.last_message_number);
	send_message(edit_text, user->account.last_message_number);
	

}
