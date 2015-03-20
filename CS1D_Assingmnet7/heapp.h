/*
 * heapp.h
 *
 *  Created on: Mar 8, 2015
 *      Author: MackO
 */

#ifndef HEAPP_H_
#define HEAPP_H_

#include <iostream>
using namespace std;

class BinaryMinHeap {
private:
      int *data;
      int heapSize;
      int arraySize;

      int getLeftChildIndex(int nodeIndex) {return 2 * nodeIndex + 1;}

      int getRightChildIndex(int nodeIndex) { return 2 * nodeIndex + 2;}

      int getParentIndex(int nodeIndex) {return (nodeIndex - 1) / 2;}

      void siftUp(int nodeIndex);

      void siftDown(int nodeIndex);

public:

      int getHeight();

      void insert(int value);

      void print();

      BinaryMinHeap(int size) {
            data = new int[size];
            heapSize = 0;
            arraySize = size;
      }

      int getMinimum() {
            if (isEmpty())
            	try{
                  throw string("Heap is empty");}
            catch(string &s ){ cout << s << endl;return NULL;}
            else
                  return data[0];
      }

      bool isEmpty() {
            return (heapSize == 0);
      }


      ~BinaryMinHeap() {
            delete[] data;
      }

      void removeMin();
};

void BinaryMinHeap::siftDown(int nodeIndex) {
      int leftChildIndex, rightChildIndex, minIndex, tmp;
      leftChildIndex = getLeftChildIndex(nodeIndex);
      rightChildIndex = getRightChildIndex(nodeIndex);
      if (rightChildIndex >= heapSize) {
            if (leftChildIndex >= heapSize)
                  return;
            else
                  minIndex = leftChildIndex;
      } else {
            if (data[leftChildIndex] <= data[rightChildIndex])
                  minIndex = leftChildIndex;
            else
                  minIndex = rightChildIndex;
      }
      if (data[nodeIndex] > data[minIndex]) {
            tmp = data[minIndex];
            data[minIndex] = data[nodeIndex];
            data[nodeIndex] = tmp;
            siftDown(minIndex);
      }
}

void BinaryMinHeap::removeMin() {
      if (isEmpty())
    	  try{
            throw string("Heap is empty");}
      catch(string & s){cout << s;}
      else {
            data[0] = data[heapSize - 1];
            heapSize--;
            if (heapSize > 0)
                  siftDown(0);
      }
}

int BinaryMinHeap::getHeight(){
	if(!isEmpty()){
		float i = heapSize;
		int count = 1;
		while(i>1.0){
			count++;
			i /= 2;
		}
		return count;
	}
	else{
		return 0;
	}
}
void BinaryMinHeap::insert(int value) {
      if (heapSize == arraySize)
    	  try{
            throw string("Heap's underlying storage is overflow");}
      catch(string &s){cout << s << endl;}
      else {
            heapSize++;
            data[heapSize - 1] = value;
            siftUp(heapSize - 1);
      }
}

void BinaryMinHeap::siftUp(int nodeIndex) {
      int parentIndex, tmp;
      if (nodeIndex != 0) {
            parentIndex = getParentIndex(nodeIndex);
            if (data[parentIndex] > data[nodeIndex]) {
                  tmp = data[parentIndex];
                  data[parentIndex] = data[nodeIndex];
                  data[nodeIndex] = tmp;
                  siftUp(parentIndex);
            }
      }
}

void BinaryMinHeap::print(){
	cout << getMinimum() << endl;
	if(!isEmpty()){
		int h = 1;
		for(int i = 1; i<=getHeight();i ++){
			for(int j = h;j<= h*2 && j <heapSize; j++){
				cout<< data[j] << " ";
			}
			h = getLeftChildIndex(h);
			cout << endl;
		}
	}
}

#endif /* HEAPP_H_ */
