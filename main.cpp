#include <iostream>
#include <string>
#include "avl_tree.h"
#include "server.h"
#include "request.h"
#include "node.h"
#include "info.h"
#include<fstream>

using namespace std;
// -----------------------------------------------------
// mohammad Andalibi     -    964408
// project subject: chat room
//       The program is not fully completed, and all of this is written in 48 hours,
//		 and could have had the right result with a little more time.
//         	thanks
//-------------------------------------------------------
 

void login(avl_tree t);
int admin(avl_tree t);


int sign_in(node* user, avl_tree t) {
	system("cls");
	int in;
	long long in_;
	string Text;
	node * Usr;
	cout << "         ** welcome "<<user->get_name()<<"**\n";
	if (user->notfication()!=0 || user->notficatin_m()!=0) {
		cout << "-> you got " << user->notfication() << " freind req  and " << user->notficatin_m() << " new messages and <-\n";
									}
	cout << "         1- send friend request\n         2- send message\n         3- edit last sent message\n         4- edit your profile\n         5- see new messages         \n         6- log out\n";
	cout << "         : ";
	cin >> in;
	switch (in)
	{
	case 1: // send request
		system("cls");
		long long number1;
		cout << "          send request to (phone number : example= 9128417064 ): ";
		cin >> number1;
		
		Usr = t.search(number1);
		Usr->send_req(user);
		system("cls");
		sign_in(user, t);
		break;
	case 2://send_message();
		
		system("cls");
		cout << "         to(phone number : example= 9128417064) : ";
		cin >> in_;
		Usr = t.search(in_);
		cout << "         enter text : ";
		cin >> Text;
		Usr->send_message(Text, user);
		sign_in(user, t);
		break;
	case 3: //edit_last_message();
		system("cls");
		
		break;
	case 4:
		user->edit_profile();
		system("cls");
		sign_in(user, t);
		break;
	
	case 5:
		system("cls");
		user->see_messages(user);
		break;

	case 6:
		system("cls");
		login(t);
		break;

	default:
		system("cls");
		cout << "Please select the correct option!!  -_-\n";
		break;
	}
	return 0;
}


void signup(avl_tree t) {
	long long number_;
	string name_, fname_;
	string pass_;
	int p_;
	cout << "         please enter your phone number( example : 9128417064  ) :";
	cin >> number_;
	cout << "         please enter your name : ";
	cin >> name_;
	cout << "         enter your family name : ";
	cin >> fname_;
	cout << "         enter pasword : ";
	cin >> pass_;
	cout << "         enter your priority(1 to 10): ";
	cin >> p_;
	
	//node new_usr(info(name_, fname_, pass_, number_, p_));
	t.insert(info(name_, fname_, pass_, number_, p_));
}



int welcome(avl_tree t) {

	long long n;
	cout << "         **welcome to TeleHeap**";
	cout << "\n         1-sign in\n         2-sign up\n         answer: ";
	cin >> n;
	switch (n)
	{
	case 1:
		system("cls");
		login(t);
		break;
	case 2:
		system("cls");
		signup(t);
		login(t);
		break;
	case 964408964408:
		admin(t);
		break;
	default:// when enter wrong anwser
		system("cls");
		cout << "Please select the correct option!!  -_-\n";
		break;
	}
	return n;
}


avl_tree  start_server(){
	
	avl_tree t;
	int n ,m, p_, num_friend;
	long long number_;
	request mm;
	string name_, fname_,pass_;
	vector<long long> list_f;
	ifstream in;
	
	in.open("listPeople.txt");
	if (in.fail()) {
		cerr << "error opening";
		exit(1);
	}
	in >> n;
	for (int i = 0; i < n; i++) {
		in >> name_;
		in >> fname_;
		in >> pass_;
		in >> number_;
		in >> p_;
		in >> num_friend;
		for (int j = 0; j < num_friend; j++) {
			in >> m;
			list_f.push_back(m);
		}
		t.insert(info(name_, fname_, pass_, number_, p_, list_f,mm));
	
	}
	return t;
}


void login(avl_tree t) {
	long long num;
	string pass;
	while (1) {
		cout << "         phone number( example: 9128417064 ):";
		cin >> num;

		cout << "         password: ";
		cin >> pass;
		node * User = new node;
		User = t.search(num);
		if (User->check_pass(pass)) {
			server control(&t, User);
			sign_in(User, t);
		}
		system("cls");
	}
}


int admin(avl_tree t) {
	int in;
	system("cls");
	cout << "\n         **welcome admin**\n";
	cout << "         1- list of All users\n         2- delete user\n         3-edit User info(by phone Number)\n         ";
	cout << " :";
	cin >> in;
	switch (in)
	{
	case 1:
		system("cls");
		t.inorder(t.get_root());
		break;
	case 2:
		system("cls");
		//delete_user();
		break;
	case 3:
		system("cls");
		//edit_User_info();
		break;
	default:
		system("cls");
		cout << "Please select the correct option!!  -_-\n";
		//admin();
		break;
	}
	return 0;
}


int main() {
	avl_tree t = start_server();
	long long  n = welcome(t);
	return 0;
	
}



