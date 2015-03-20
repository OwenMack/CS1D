/*
 * isPalindrome.cpp
 *
 *  Created on: Jan 22, 2015
 *      Author: MackO
 */

#include "MyQueue.h"
#include <string>

//This checks if it is a palindrome
bool isPalindrome(string theString)
{
	int size = theString.size();
	int i = 0;
	bool palindrome = true;
	char firstLet;
	char lastLet;
	ArrayQueue<char> theQueue;

	for(i = 0; i <= size;i++)
	{
		if((theString[i] >=97 &&theString[i] <=122) ||
		   (theString[i] >= 65 && theString[i] <=90))
		{
			theString[i] = tolower(theString[i]);
			theQueue.Enqeue(theString[i]);
		}
	}

	i = 0;
	size = theQueue.Size() / 2;

	while(i < size && palindrome)
	{
		firstLet = theQueue.Pop();
		lastLet = theQueue.PopBack();

		if(firstLet != lastLet)
		{
			palindrome = false;
		}

		i++;
	}

	return palindrome;
}


