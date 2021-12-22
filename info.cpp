#include "info.h"

info::info()
{
	name = "";
	password = "";
	f_name = "";
	last_message = "";
	last_message_number = NULL;
	phone_number = NULL;
	priority = NULL;
	friends = vector<long long>();
	//message = new Stack;
	//request = new Stack;
}

info::info(string Name, string F_name , string pass, long long Phone_number, int Priority)
{
	name = Name;
	f_name = F_name;
	password = pass;
	last_message = "";
	last_message_number = NULL;
	phone_number = Phone_number;
	priority = Priority;
	friends = vector<long long>();

}

info::info(string Name, string F_name,string pass , long long Phone_number, int Priority, vector<long long>list_f, request req_list) {
	name = Name;
	f_name = F_name;
	password = pass;
	last_message = "";
	last_message_number = NULL;
	phone_number = Phone_number;
	priority = Priority;
	freind_req = req_list;
	friends = vector<long long>(list_f);
	//last_message = "";
//	last_message_number = NULL;
}

info::info(string Name, string F_name, string pass, long long Phone_number, int Priority,  vector<long long> friends_, request freind_r, vector<pair <string, long long>> m,string last_t, long long last_n)// +messages_heap del_text,
{
	name = Name;  // name
	f_name = F_name; // family name
	password = pass;  // paasword
	last_message = "";
	last_message_number = NULL;
	phone_number = Phone_number;
	priority = Priority;
	messages = m;
	freind_req = freind_r;  //request list
	last_message = last_t;   // last message
	last_message_number = last_n;
}

