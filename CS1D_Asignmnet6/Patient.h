/*
 * Patient.h
 *
 *  Created on: Mar 2, 2015
 *      Author: duncan
 */

#ifndef PATIENT_H_
#define PATIENT_H_

#include <string>
#include <iostream>
using namespace std;

template <class type>
class Patient
{
public:
	Patient();
	Patient(type newName, int newTime);
	~Patient();

	// Operators
	bool operator == (const Patient<type> &P2) const;
	bool operator != (const Patient<type> &P2) const;
	bool operator <= (const Patient<type> &P2) const;
	bool operator >= (const Patient<type> &P2) const;
	bool operator >  (const Patient<type> &P2) const;
	bool operator <  (const Patient<type> &P2) const;

	// Setters
	void SetName(type newName);
	void SetTime(int    newTime);

	// Getters
	type GetName() const;
	int    GetTime();

private:
	type name;
	int    waitTime;
};

template <class type>
Patient<type>::Patient()
{
	name     = "";
	waitTime = 0;
}
template <class type>
Patient<type>::Patient(type newName, int newTime)
{
	name     = newName;
	waitTime = newTime;
}
template <class type>
Patient<type>::~Patient()
{
}

template <class type>
void Patient<type>::SetName(type newName)
{
	name = newName;
}

template <class type>
void Patient<type>::SetTime(int newTime)
{
	waitTime = newTime;
}

template <class type>
type Patient<type>::GetName() const
{
	return name;
}

template <class type>
int Patient<type>::GetTime()
{
	return waitTime;
}

template <class type>
bool Patient<type>::operator ==(const Patient<type> &P2) const
{
	bool returnVal;
	if(this->waitTime == P2.waitTime)
	{
		returnVal = true;
	}
	else
	{
		returnVal = false;
	}
	return returnVal;
}

template <class type>
bool Patient<type>::operator !=(const Patient<type> &P2) const
{
	bool returnVal;
	if(this->waitTime == P2.waitTime)
	{
		returnVal = false;
	}
	else
	{
		returnVal = true;
	}
	return returnVal;
}

template <class type>
bool Patient<type>::operator <=(const Patient<type> &P2) const
{
	bool returnVal;
	if(this->waitTime <= P2.waitTime)
	{
		returnVal = true;
	}
	else
	{
		returnVal = false;
	}
	return returnVal;
}

template <class type>
bool Patient<type>::operator >=(const Patient<type> &P2) const
{
	bool returnVal;
	if(this->waitTime >= P2.waitTime)
	{
		returnVal = true;
	}
	else
	{
		returnVal = false;
	}
	return returnVal;
}

template <class type>
bool Patient<type>::operator <(const Patient<type> &P2) const
{
	bool returnVal;
	if(this->waitTime < P2.waitTime)
	{
		returnVal = true;
	}
	else
	{
		returnVal = false;
	}
	return returnVal;
}

template <class type>
bool Patient<type>::operator >(const Patient<type> &P2) const
{
	bool returnVal;
	if(this->waitTime > P2.waitTime)
	{
		returnVal = true;
	}
	else
	{
		returnVal = false;
	}
	return returnVal;
}

#endif /* PATIENT_H_ */
