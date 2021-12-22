#include "message.h"




/*

messages_heap::messages_heap()
{
	messages = vector<message>();
}

//messages_heap::messages_heap(int s) //s = size
//{
//	text = new message[s];
//}

void messages_heap::Max_Heapify(int i)
{
		int largest = i;
		int left = (i * 2) + 1;
		int right = (i * 2) + 2;

		if (left < messages.size() && messages[i].priority < messages[left].priority)
			largest = left;
		else
			largest = i;
		if (right < messages.size() && messages[largest].priority < messages[right].priority)
			largest = right;
		if (largest != i) {
			swap(messages[i].priority, messages[largest].priority);
			Max_Heapify(largest);
		}
}

void messages_heap::Insert(message & text)
{
	messages.push_back(text);
//	int k = text.priority;
	Max_Heapify(messages.size());
}
 */