#include "node.h"

node::node()
{
	right = NULL;
	left = NULL;
	height = 0;
}

node::node(node &other)
{
	account = other.account;
	height = other.height;
	right = other.right;
	left = other.left;
}

node & node::operator=(node &other)
{
	account = other.account;
	height = other.height;
	right = other.right;
	left = other.left;
	return *this;
}

node::node(info temp)
{
	account = temp;
	right = NULL;
	left = NULL;
	
	height = 0;
}

bool node::check_pass(string pass)
{
	if (account.password == pass)
		return true;
	return false;
}

void node::send_req(node* n)
{
	long long num = n->account.phone_number;
	account.freind_req.insert(num);
}

string node::get_name()
{
	return this->account.name;
}

void node::edit_profile()
{
	int in;
	cout << "         1- change name?        2- change family name \n         3- change password\n         \n4- remove friend\n";
	cout << "         : ";
	cin >> in;
	string NEW;
	long long NUM;
	switch (in) 
	{
	case 1:
		system("cls");
		cout << "enter new name :";
		cin >> NEW;
		this->account.name = NEW;
		break;
	case 2:
		system("cls");
		cout << "enter new family name :";
		cin >> NEW;
		this->account.f_name = NEW;
		break;
	case 3:
		system("cls");
		cout << "enter new password :";
		cin >> NEW;
		this->account.password = NEW;
		break;

	default:
		system("cls");
		cout << "Please select the correct option!!  -_-\n";
		break;
	}

}

int node::notfication()
{
	return size_req(this->account.freind_req);
}

int node::size_req(request que)
{
	if(que.front<que.rear)
		return (que.rear - que.front);
	if (que.front > que.rear)
		return (15 - (que.front - que.rear));
	if (que.front == que.rear)
		return 0;
}

void node::send_message(string Text, node *usr)
{
	account.messages.push_back(std::make_pair(Text, usr->account.phone_number));
}

int node::notficatin_m()
{

	return this->account.messages.size();
}

void node::see_messages(node * user){
	cout << "#";

	for (int i = 0; i < user->account.messages.size(); i++) {
		cout << "@";
		cout <<"from: "<< user->account.messages[i].second << " : " << user->account.messages[i].first << endl;
	}
}
