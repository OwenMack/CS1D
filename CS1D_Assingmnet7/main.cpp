/*
 * main.cpp
 *
 *  Created on: Mar 8, 2015
 *      Author: MackO
 */

#include <iostream>
#include "heapp.h"

using namespace std;

int main(){

	//67 88 77 52 44 11 66 93

	BinaryMinHeap h(8);

	cout << "The tree will be printed with the left \n"
			"most node on the left for each level" << endl << endl;


	h.insert(67);
	cout << "Adding 67:" << endl;
	h.print();
	h.insert(88);
	cout << "Adding 88:" << endl;
	h.print();
	h.insert(77);
	cout << "Adding 77:" << endl;
	h.print();
	h.insert(52);
	cout << "Adding 52:" << endl;
	h.print();
	h.insert(44);
	cout << "Adding 44:" << endl;
	h.print();
	h.insert(11);
	cout << "Adding 11:" << endl;
	h.print();
	h.insert(66);
	cout << "Adding 66:" << endl;
	h.print();
	h.insert(93);
	cout << "Adding 93:" << endl;
	h.print();

	h.removeMin();
	cout << "removing root:" << endl;
	h.print();
	h.removeMin();
	cout << "removing root:" << endl;
	h.print();
	h.removeMin();
	cout << "removing root:" << endl;
	h.print();
	h.removeMin();
	cout << "removing root:" << endl;
	h.print();
	h.removeMin();
	cout << "removing root:" << endl;
	h.print();
	h.removeMin();
	cout << "removing root:" << endl;
	h.print();
	h.removeMin();
	cout << "removing root:" << endl;
	h.print();
	h.removeMin();
	cout << "removing root:" << endl;
	h.print();

	return 0;
}


