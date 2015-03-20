/*
 * main.cpp
 *
 *  Created on: Feb 5, 2015
 *      Author: MackO
 */

#include <iostream>
#include "MyQueue.h"
#include "LinkedStack.h"
#include "ParenthesesAlg.h"
#include <vector>
using namespace std;

int main(){
	vector<int> vec1;
	vector<double> vec2;
	vector<string> vec3;

	LinkedStack<int> link1;
	LinkedStack<double> link2;
	LinkedStack<string> link3;

	LinkedQueue<int> deque1;
	LinkedQueue<double> deque2;
	LinkedQueue<string> deque3;

	string sArray[6] = {"Paula","JoAnn","Jack","Mark","Paul","Eric"};
	double dArray[5] = {2788.123, 243.76, 8445.5612, 19833.121, 12.4};
	int    iArray[8] = {98, 88, 88, 123, 8445, 9833, 12, 354};

	for(int i = 0; i <6;i++){
		vec3.push_back(sArray[i]);
		link3.push(sArray[i]);
		deque3.Enqeue(sArray[i]);
	}

	for(int i = 0; i <5;i++){
		vec2.push_back(dArray[i]);
		link2.push(dArray[i]);
		deque2.Enqeue(dArray[i]);
	}

	for(int i = 0; i <8;i++){
		vec1.push_back(iArray[i]);
		link1.push(iArray[i]);
		deque1.Enqeue(iArray[i]);
	}
	string theString = "{(8x+5) - 5x[9x+3]})";
	ParenthesesAlg solve (theString);
	bool test = solve.solving();
	cout <<test << endl;

	return 0;
}


