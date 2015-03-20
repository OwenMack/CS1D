/*
 * main.cpp
 *
 *  Created on: Jan 22, 2015
 *      Author: MackO
 */

#include <iostream>
using namespace std;
bool isPalindrome(string theString);
int main()
{
	string theWords[10];
	theWords[0] = "dad";
	theWords[1] = "radar";
	theWords[2] = "Otto";
	theWords[3] = "mom";
	theWords[4] = "tigers";
	theWords[5] = "A man, a plan, a canal, Panama";
	theWords[6] = "Isn't this class cool";
	theWords[7] = "Was it a car or a cat I saw?";
	theWords[8] = "Sit on a potato pan, Otis";
	theWords[9] = "Saddleback is a great place to learn";

	for(int i = 0; i < 10;i++)
	{
		cout << theWords[i] << " - ";
		cout << ((isPalindrome(theWords[i]) == true) ? "True":"False");
		cout << endl;
	}
	return 0;
}


