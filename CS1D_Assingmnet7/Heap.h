/*
 * Heap.h
 *
 *  Created on: Mar 8, 2015
 *      Author: MackO
 */

#ifndef HEAP_H_
#define HEAP_H_

#include <vector>
#include <iterator>
using namespace std;

template<class type>
struct node
{
	type key;
};


template<class type>
class heap{
public:
	heap();
	~heap();
	void destroyTree();
	void insert(type newKey);
	int size();

private:
	void destroyTree(node<type> *leaf);

	vector<node<type> > theHeap;
};

template<class type>
heap<type>::heap(){
}

template<class type>
heap<type>::~heap(){
	destroyTree();
}

template<class type>
int heap<type>::size(){
	return theHeap.size();
}

template<class type>
void heap<type>::insert(type newKey){
	node<type>* newNode = new node<type>;
	newNode->key = newKey;
	theHeap.insert_back(newNode);
}

#endif /* HEAP_H_ */
