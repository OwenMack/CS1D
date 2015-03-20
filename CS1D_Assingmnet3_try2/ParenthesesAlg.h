/*
 * ParenthesesAlg.h
 *
 *  Created on: Feb 10, 2015
 *      Author: MackO
 */

#ifndef PARENTHESESALG_H_
#define PARENTHESESALG_H_

#include <string>
#include <iostream>
#include "LinkedStack.h"
using namespace std;

class ParenthesesAlg{
public:
	ParenthesesAlg();
	ParenthesesAlg(string newString);
	~ParenthesesAlg();
	void readIn(string newString);
	bool solving();
	bool solving(string newString);
private:
	string theString;
};

ParenthesesAlg::ParenthesesAlg(){
}
ParenthesesAlg::ParenthesesAlg(string newString){
	theString = newString;
}

ParenthesesAlg::~ParenthesesAlg(){
}

void ParenthesesAlg::readIn(string newString){
	theString = newString;
}
bool ParenthesesAlg::solving(){
	LinkedStack<char> stack;
	for(int i = 0; i < theString.length(); i++){
		if((theString[i] == '(') || (theString[i] == '{') || (theString[i] == '['))
			stack.push(theString[i]);
		else if(theString[i] == ')' ||theString[i] == '}' ||theString[i] == ']'){
			if(stack.isEmpty())
				return false;
			if(stack.peek() == (theString[i]+1) || stack.peek() == (theString[i] +2))
				return false;
			stack.pop();
		}//END of ELSE IF
	}//END of FOR

	if(stack.isEmpty())
		return true;
	else
		return false;
}

bool ParenthesesAlg::solving(string newString){
	theString = newString;
	LinkedStack<char> stack;
	for(int i = 0; i < theString.length(); i++){
		if((theString[i] == '(') || (theString[i] == '{') || (theString[i] == '['))
			stack.push(theString[i]);
		else if(theString[i] == ')' ||theString[i] == '}' ||theString[i] == ']'){
			if(stack.isEmpty())
				return false;
			if(stack.peek() == (theString[i]+1) || stack.peek() == (theString[i] +2))
				return false;
			stack.pop();
		}//END of ELSE IF
	}//END of FOR

	if(stack.isEmpty())
		return true;
	else
		return false;
}
#endif /* PARENTHESESALG_H_ */
