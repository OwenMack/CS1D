/*
 * hasing.h
 *
 *  Created on: Mar 17, 2015
 *      Author: MackO
 */

#ifndef HASING_H_
#define HASING_H_

#include <string>
#include <vector>
#include <iterator>
using namespace std;

struct node{
	int key;
	string info;
};

class hashing{
public:
	hashing(int newSize);
	~hashing();
	void insert(string newInfo,int newKey);
	void remove(string newInfo,int newKey);
	void printAll();
private:
	int firstHash(int theKey);
	int secondHash(int theKey);
	int size;
	vector<node>* theAr;
};

int hashing::firstHash(int theKey){
	return theKey % 19;
}

int hashing::secondHash(int theKey){
	return 17 - theKey %17;
}
hashing::hashing(int newSize){
	size = newSize;
	theAr = new vector<node> [newSize];
}

hashing::~hashing(){
	delete [] theAr;
}

void hashing::insert(string newInfo,int newKey){
	node temp;
	temp.key = newKey;
	temp.info = newInfo;
	int place = newKey % size;

	if(theAr[place].empty()){
		theAr[place].push_back(temp);
	}
	else{
		place = 17 - place % 17;
		theAr[place].push_back(temp);
	}
}

void hashing::remove(string newInfo,int newKey){
	vector<node>::iterator it;
	bool found = false;
	int i = 0;
	node temp;
	it = theAr[firstHash(newKey)].begin();
	while(i<theAr[firstHash(newKey)].size() && !found){
		temp = theAr[firstHash(newKey)][i];
		if(temp.info  == newInfo){
			found = true;
			it +=i;
			(theAr[firstHash(newKey)]).erase(it);
		}
		else
			i++;
	}

	if(!found){
		i = 0;
		it = theAr[secondHash(newKey)].begin();
		while(i<theAr[secondHash(newKey)].size() && !found){
			temp = theAr[secondHash(newKey)][i];
			if(temp.info  == newInfo){
				found = true;
				it+=i;
				theAr[secondHash(newKey)].erase(it);
			}
			else
				i++;
		}
	}
}

void hashing::printAll(){
	node temp;
	for(int i = 0;i<size;i++){
		cout << i << ":";
		for(int j = 0;j<theAr[i].size();j++){
			temp = theAr[i][j];
			cout <<"  "<< temp.info << " - ";
		}
		cout << endl;
	}
}
#endif /* HASING_H_ */
