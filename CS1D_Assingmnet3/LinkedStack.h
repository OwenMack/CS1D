/*
 * LinkedStack.h
 *
 *  Created on: Feb 10, 2015
 *      Author: MackO
 */

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_

#include <iostream>

template<class A_Type> struct node1{
	A_Type item;
	node1<A_Type>* next;
};

template<class A_Type> class LinkedStack{
public:
	LinkedStack();
	~LinkedStack();
	void push(A_Type newItem);
	void pop();
	A_Type peek();
private:
	node1<A_Type>* head;
};

template<class A_Type>
LinkedStack<A_Type>::LinkedStack(){
	head = NULL;
}

template<class A_Type>
LinkedStack<A_Type>::~LinkedStack(){

}

template<class A_Type>
void LinkedStack<A_Type>::push(A_Type newItem){
	node1<A_Type>* temp = new node1<A_Type>;
	temp->item = newItem;
	temp->next = head;
	head = temp;
}

template<class A_Type>
void LinkedStack<A_Type>::pop(){
	node1<A_Type>* temp = head;
	head = head->next;
	delete temp;
}

template<class A_Type>
A_Type LinkedStack<A_Type>::peek(){
	return head->info;
}



#endif /* LINKEDSTACK_H_ */
