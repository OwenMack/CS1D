#ifndef MYQUEUE_H_
#define MYQUEUE_H_

#include <iostream>
using namespace std;

template <class type> struct node
{
	type info;
	node* next;
	node* prev;
};

template <class type> class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();

	void PrintEntireQ();
	void Enqeue(type newItem);
	type Pop();
	type PopBack();

	bool IsEmpty() const;
	type Front()   const;
	int Size()     const;

private:
	int size;
	node<type>* head;
	node<type>* tail;
};

template  <class type>
PriorityQueue<type>::PriorityQueue()
{
	size = 0;
	tail = NULL;
	head = NULL;

}

template  <class type>
PriorityQueue<type>::~PriorityQueue()
{
}
template <class type>
void PriorityQueue<type>::PrintEntireQ()
{
	if(!IsEmpty())
	{
		node<type>* temp = head;
		while(temp != NULL)
		{
			cout << temp->info << endl;
			temp = temp->next;
		}
	}
	else
	{
		cout << "The queue is empty, cannot output the entire list" << endl;
	}
}

template <class type>
void PriorityQueue<type>::Enqeue(type newItem)
{
	node<type>* temp = new node<type>;
	temp->info = newItem;
	if(IsEmpty())
	{
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
		tail = temp;
		size ++;
	}
	else
	{
		tail->next = temp;
		temp->prev = tail;
		temp->next = NULL;
		tail = temp;
		size++;
	}
}

template <class type>
type PriorityQueue<type>::PopBack()
{
	type tempType;

	node<type>* temp = tail;
	tempType = temp->info;
	tail = tail->prev;
	delete temp;
	size--;

	return tempType;
}
template <class type>
type PriorityQueue<type>::Pop()
{
	type tempType;

	node<type>* temp = head;
	tempType = temp->info;
	head = head->next;
	delete temp;
	size --;

	return tempType;
}

template <class type>
bool PriorityQueue<type>::IsEmpty() const
{
	return head == NULL;
}

template <class type>
type PriorityQueue<type>::Front() const
{
	return head->info;
}

template <class type>
int PriorityQueue<type>::Size() const
{
	return size;
}

#endif /* MYQUEUE_H_ */
