/*
 * main.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: MackO
 */

#include <iostream>
#include "PriorityQueue.h"
#include <queue>
#include "Patient.h"
using namespace std;
int main(){

	cout << "My Priority Queue:\n";
	PriorityQueue<string> PQ;

	PQ.Enqeue("Irene Ill", 1);
	PQ.Enqeue("Alice Ailment", 3);
	PQ.Enqeue("Sid Sicky", 4);
	PQ.Enqeue("Cathy Coughing", 5);
	PQ.Enqeue("Bob Bleeding", 2);
	PQ.Enqeue("Frank Feelingbad", 7);
	PQ.Enqeue("Sam Sneezing", 5);


	float index = 12.0;
	while(!PQ.IsEmpty())
	{
		cout << PQ.Front() << " is being treated at " << index << endl;

		PQ.Pop();
		index += 0.5;
		if(index >= 14.1 && index <= 14.5)
		{
			PQ.Enqeue("Tom Temperature", 1,true);
		}
		else if(index == 13.5)
		{
			PQ.Enqeue("Paula Pain", 1,true);
		}
	}

	cout << endl << endl<< "\nPriority Queue STL:\n";;
	priority_queue<Patient<string> > PQ2;
	Patient<string> tempp;

	Patient<string>* newPatient = new Patient<string>("Alice Ailment", 3);
	PQ2.push(*newPatient);
	newPatient = new Patient<string>("Irene Ill", 1);
	PQ2.push(*newPatient);
	newPatient = new Patient<string>("Sid Sicky", 4);
	PQ2.push(*newPatient);
	newPatient = new Patient<string>("Cathy Coughing", 5);
	PQ2.push(*newPatient);
	newPatient = new Patient<string>("Bob Bleeding", 2);
	PQ2.push(*newPatient);
	newPatient = new Patient<string>("Frank Feelingbad", 7);
	PQ2.push(*newPatient);
	newPatient = new Patient<string>("Same Sneezing", 5);
	PQ2.push(*newPatient);

	index = 12.0;
	while(!PQ2.empty())
	{
		cout << PQ2.top().GetName() << " is being treated at " << index << endl;

		PQ2.pop();
		index += 0.5;
		if(index >= 14.1 && index <= 14.5)
		{
			newPatient = new Patient<string>("Tom Temperature", 911);
			PQ2.push(*newPatient);
		}
		else if(index == 13.5)
		{
			newPatient = new Patient<string>("Paula Pain", 911);
			PQ2.push(*newPatient);
		}
	}


	return 0;
}


