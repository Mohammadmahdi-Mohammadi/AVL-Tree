#include "request.h"
request::request()
{
	rear = -1;
	front = -1;
}

void request::insert(int x)
{
	if (rear >  15)
	{
		cout << "queue over flow";
		front = rear = -1;
		return;
	}
	req[++rear] = x;
	cout << "inserted" << x;
}

void request::delet()
{
	if (front == rear)
	{
		cout << "queue under flow";
		return;
	}
	cout << "deleted" << req[++front];
}

void request::display()
{
	if (rear == front)
	{
		cout << " queue empty";
		return;
	}
	for (int i = front + 1; i <= rear; i++)
		cout << req[i] << " ";
}


