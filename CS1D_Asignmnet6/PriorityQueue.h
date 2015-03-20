/*
 * PriorityQueue.h
 *
 *  Created on: Feb 26, 2015
 *      Author: MackO
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include <iostream>
using namespace std;

template <class type> struct node
{
	type info;
	int  pri;
	bool need;
	node* next;
	node* prev;
};

template <class type> class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();

	void PrintEntireQ();
	void Enqeue(type newItem,int priority,bool need = false);
	type Pop();
	type PopBack();

	bool IsEmpty() const;
	type Front()   const;
	int Size()     const;

private:
	node<type>* FindSpot(node<type>* temp, node<type>* spot);

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
void PriorityQueue<type>::Enqeue(type newItem,int priority,bool need){
	node<type>* temp = new node<type>;
	temp->info = newItem;
	temp->pri = priority;
	temp->need = need;
	if(IsEmpty())
	{
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
		tail = temp;
		size ++;
	}
	else if(need){
		head->prev = temp;
		temp->prev = NULL;
		temp->next = head;
		head = temp;
	}
	else
	{
		node<type>* spot = new node<type>;
		spot = FindSpot(temp,head);
		if(spot == head && head->pri < temp->pri){
			temp->next = spot;
			spot->prev = temp;
			temp->prev = NULL;
			head = temp;
		}else{
			temp->next = spot;
			spot->prev->next = temp;
			spot->prev = temp;
			temp->prev = spot->prev;
			if(temp->next == NULL)
				tail = temp;
		}
		size++;
	}
}

template <class type>
node<type>* PriorityQueue<type>::FindSpot(node<type>* temp,node<type>* spot){
	if(spot->next !=NULL && (spot->need || temp->pri <= spot->pri)){
		return FindSpot(temp,spot->next);
	}
	return spot;
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




#endif /* PRIORITYQUEUE_H_ */
