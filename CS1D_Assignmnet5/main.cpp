/*
 * main.cpp
 *
 *  Created on: Feb 20, 2015
 *      Author: MackO
 */

#include "btree.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
	bstree<char> bt;
	node<char>*  n;


		bt.insert('D');
		bt.insert('B');
		bt.insert('H');
		bt.insert('F');
		bt.insert('C');
		bt.insert('G');
		bt.insert('A');
		bt.insert('E');

		bstree<char> bt2(bt);


		cout << "nodes:        ";

	for(int i = 65; i<= 72; i++){
		n = bt.search(i);
		cout << n->key << "  ";
	}
//	bt.remove('A');
//	bt.remove('C');

	cout << endl << "lvl of nodes: ";
	for(int i = 65; i<=72; i++){
		cout << bt.nodelvl(i) << "  ";
	}

	cout << endl << endl;

	cout << "nodes:        ";
	for(int i = 65; i<= 72; i++){
		n = bt2.search(i);
		cout << n->key << "  ";
	}
//	bt.remove('A');
//	bt.remove('C');

	cout << endl << "lvl of nodes: ";
	for(int i = 65; i<=72; i++){
		cout << bt2.nodelvl(i) << "  ";
	}

	cout << endl;
	return 0;
}

