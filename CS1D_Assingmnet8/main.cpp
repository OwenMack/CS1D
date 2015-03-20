/*
 * main.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: MackO
 */


#include <iostream>
#include "hasing.h"
using namespace std;

int main(){
	hashing hash(19);
	int key;
	string name;


	key = 18;
	name  = "Laguna Niguel";
	hash.insert(name, key);

	key = 41;
	name  = "Mission Viejo";
	hash.insert(name, key);

	key = 22;
	name = "Lake Forest";
	hash.insert(name, key);

	key = 44;
	name = "Irvine";
	hash.insert(name, key);

	key = 59;
	name  = "San Clemente";
	hash.insert(name, key);

	key = 32;
	name  = "San Diego";
	hash.insert(name, key);

	key = 49;
	name  = "Anaheim";
	hash.insert(name, key);

	key = 73;
	name = "Los Angeles";
	hash.insert(name, key);

	key = 17;
	name = "Orange";
	hash.insert(name, key);

	key = 77;
	name = "Palm Springs";
	hash.insert(name, key);

	key = 26;
	name  = "Riverside";
	hash.insert(name, key);

	key = 19;
	name = "Brea";
	hash.insert(name, key);

	key = 60;
	name = "Santa Ana";
	hash.insert(name, key);

	key = 35;
	name  = "Tustin";
	hash.insert(name, key);

	key = 52;
	name = "Oceanside";
	hash.insert(name, key);

	key = 11;
	name = "La Jolla";
	hash.insert(name, key);

	key = 18;
	name  = "Del Mar";
	hash.insert(name, key);

	key = 22;
	name = "Aliso Viejo";
	hash.insert(name, key);

	key = 49;
	name = "Laguna Beach";
	hash.insert(name, key);

	hash.printAll();

	hash.remove("Anaheim",49);
	hash.remove("Laguna Niguel",18);
	hash.remove("Lake Forest",22);
	cout << endl;

	hash.printAll();

	return 0;
}

