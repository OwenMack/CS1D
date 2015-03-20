/*
 * main.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: MackO
 */
#include "DlinkedList.h"
#include "VecAdt.h"
#include <iostream>

using namespace std;

int main()
{
	Qwrapper q1;
	Qwrapper q2;
	Qwrapper q3;
	Qwrapper q4;
	q1.enqueue("A man, a plan, a canal, Panama");
	q2.enqueue("Was it a car or a cat I saw?");
	q3.enqueue("Sit on a potato pan, Otis");
	q4.enqueue("Isn't this class cool?");

	cout << q1.front() << endl << q2.front() << endl << q3.front() << endl <<
		    q4.front() << endl;

	VecAdt<int> vec1(10);
	VecAdt<int> vec2(10);

	for (int i = 0; i < 10; i ++){
		vec1.insert(i,i);
		vec2.insert(i*10,i);
	}

	for(int i = 0; i< 10; i ++){
		cout << vec1[i] << endl;
		cout << vec2[i] << endl;
	}

	return 0;
}



