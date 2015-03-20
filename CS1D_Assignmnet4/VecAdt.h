/*
 * VecAdt.h
 *
 *  Created on: Feb 11, 2015
 *      Author: MackO
 */

#ifndef VECADT_H_
#define VECADT_H_
#include <iterator>

template<class A_Type>
class VecAdt{
public:
	VecAdt();
	VecAdt(int newsize);
	~VecAdt();

	void insert(A_Type newitem,int here);
//	void replace(A_Type newitem,int here);
	void clear();

	void begin();

	A_Type operator[](int spot);
	A_Type at(int spot);
	A_Type front();
	A_Type back();

	int size();
	int max_size();
	bool empty();

private:
	void   moveit();
	void   setit();

	A_Type* theVec;
	int     theSize;
	int		maxSize;
//	A_Type<A_Type>::iterator it;
};

template<class A_Type>
VecAdt<A_Type>::VecAdt(){
	theVec = new A_Type[1];
	theSize = -1;
	maxSize = 1;
//	it = theVec;
}

template<class A_Type>
VecAdt<A_Type>::VecAdt(int newsize){
	theVec = new A_Type[newsize];
	maxSize = newsize;
	setit();
	theSize = -1;
//	it = theVec;
}

template<class A_Type>
VecAdt<A_Type>::~VecAdt(){
	delete [] theVec;

}

template<class A_Type>
A_Type VecAdt<A_Type>::operator [](int spot){
	return *(theVec + spot);
}

template<class A_Type>
A_Type VecAdt<A_Type>::at(int spot){
	return *(theVec + spot);
}

template<class A_Type>
void VecAdt<A_Type>::insert(A_Type newitem,int here){
	if(++theSize  < maxSize){
		*(theVec + here) = newitem;
		theSize++;
	}
	else{
		moveit();
		*(theVec + here) = newitem;
		theSize++;
	}
}

//template<class A_Type>
//void VecAdt<A_Type>::replace(A_Type newitem,int here){
//	if(++theSize  < maxSize){
//		*(theVec + here) = newitem;
//		theSize++;
//	}
//	else{
//		moveit();
//		*(theVec + here) = newitem;
//		theSize++;
//	}
//}

template<class A_Type>
void VecAdt<A_Type>::moveit(){
	A_Type* newVec = new A_Type[maxSize*2];
	maxSize *= 2;

	for(int i = 0; i <=theSize; i++){
		*(newVec+i) = *(theVec + i);
	}
	delete [] theVec;
	theVec = newVec;
}

template<class A_Type>
void VecAdt<A_Type>::clear(){
	delete [] theVec;
}

template<class A_Type>
int VecAdt<A_Type>::size(){
	return theSize;
}

template<class A_Type>
int VecAdt<A_Type>::max_size(){
	return maxSize;
}

template<class A_Type>
void VecAdt<A_Type>::setit(){
	for(int i = 0; i <=maxSize;i++){
		*(theVec + i) = 0;
	}
}

template<class A_Type>
A_Type VecAdt<A_Type>::front(){
	return *theVec;
}

template<class A_Type>
A_Type VecAdt<A_Type>::back(){
	return *(theVec+theSize);
}

template<class A_Type>
bool VecAdt<A_Type>::empty(){
	return theSize ==0;
}

#endif /* VECADT_H_ */
