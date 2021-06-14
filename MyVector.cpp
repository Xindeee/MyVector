#include <iostream>
#include <algorithm>
#include "MyVector.h"
namespace NSMyVector {
	MyVector::MyVector() {
		arr = new int[100];
		countHard = 100;
		firstHard = arr;
		lastHard = arr + 100;
		firstLogic = arr + 50;
		lastLogic = firstLogic;
		
		count = 0;
	}
	MyVector::MyVector(int countIn, int valIn) {
		resize(countIn, valIn);
	}
	MyVector::MyVector(int countIn) {
		resize(countIn, 0);
	}
	MyVector::MyVector(const MyVector& myVIn) {
		countHard = myVIn.countHard;
		delete[] arr;
		arr = new int[countHard];
		firstHard = arr;
		lastHard = arr + countHard;
		firstLogic = arr + (myVIn.firstLogic-myVIn.firstHard);
		count = myVIn.count;
		lastLogic = firstLogic+count;
		std::copy(myVIn.firstLogic, myVIn.lastLogic, firstLogic);
	}
	MyVector::~MyVector() {
		delete[] arr;
	}
	MyVectorIterator MyVector::begin() {
		MyVectorIterator iter(firstLogic);
		return iter;
	}
	MyVectorIterator MyVector::end() {
		MyVectorIterator iter(lastLogic);
		return iter;
	}
	void MyVector::resize(int countIn, int valIn=0) {
		countHard = countIn;
		delete[] arr;
		arr = new int[countHard];
		count = countIn;
		firstHard = arr;
		lastHard = arr + countHard;
		firstLogic = arr;
		lastLogic = lastHard;
		std::fill_n(firstLogic, count, valIn);
	}
	void MyVector::resizeCloud() {
		int* newarr;
		int newcountHard = count * 3;
		newarr = new int[newcountHard];
		firstHard = newarr;
		lastHard = newarr + newcountHard;
		int* newfirstLogic = firstHard + count;
		int* newlastLogic = newfirstLogic + count;
		std::copy(firstLogic, lastLogic, newfirstLogic);
		delete[] arr;
		arr = newarr;
		firstLogic = newfirstLogic;
		lastLogic = newlastLogic;
		countHard = newcountHard;
	}
	void MyVector::pushBack(int valIn) {
		if (lastLogic != lastHard) {
			*lastLogic = valIn;
			lastLogic++;
			count++;
		}
		else {
			resizeCloud();
			*lastLogic = valIn;
			lastLogic++;
			count++;
		}
	}
	void MyVector::pushFront(int valIn) {
		if (firstLogic != firstHard) {
			firstLogic--;
			*firstLogic = valIn;
			count++;
		}
		else {
			resizeCloud();
			firstLogic--;
			*firstLogic = valIn;
			count++;
		}
	}
	void MyVector::popBack() {
		if (lastLogic != firstLogic) {
			lastLogic--;
			count--;
		}
		else {
			throw MyVectorException();
		}
	}
	void MyVector::popFront() {
		if (firstLogic != lastLogic) {
			firstLogic++;
			count--;
		}
		else {
			throw MyVectorException();
		}
	}
	int& MyVector::operator[](int indexIn) {
		if (indexIn >= 0 && indexIn<count) {
			return firstLogic[indexIn];
		}
		else {
			throw MyVectorException();
		}
	}
	MyVectorIterator MyVector::find(int valIn) {
		for (int* it = firstLogic;it != lastLogic;it++) {
			if (*it == valIn) {
				return MyVectorIterator(it);
			}
		}
		return MyVectorIterator();
	}
	MyVectorIterator::MyVectorIterator() {
		ptr = nullptr;
	}
	MyVectorIterator::MyVectorIterator(int* ptrIn) {
		ptr = ptrIn;
	}
	int& MyVectorIterator::operator*() {
		if (ptr != nullptr) {
			return *ptr;
		}
		else {
			throw MyVectorException();
		}
	 }
	int& MyVectorIterator::operator++() {
		if (ptr != nullptr) {
			ptr++;
			return *ptr;
		}
		else {
			throw MyVectorException();
		}
	}
	int& MyVectorIterator::operator--() {
		if (ptr != nullptr) {
			ptr--;
			return *ptr;
		}
		else {
			throw MyVectorException();
		}
	}
	bool MyVectorIterator::operator==(int* valIn) {
		if (valIn==ptr) {
			return true;
		}
		else {
			return false;
		}
	}
	bool MyVectorIterator::operator==(const MyVectorIterator& iterIn) {
		if (iterIn.ptr == ptr) {
			return true;
		}
		else {
			return false;
		}
	}
	bool MyVectorIterator::operator!=(int* valIn) {
		if (ptr == valIn) {
			return false;
		}
		else {
			return true;
		}
	}
	bool MyVectorIterator::operator!=(const MyVectorIterator& iterIn) {
		if (iterIn.ptr == ptr) {
			return false;
		}
		else {
			return true;
		}
	}
	bool operator==(int* valIn, const MyVectorIterator& iterIn) {
		if (iterIn.ptr == valIn) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator!=(int* valIn, const MyVectorIterator& iterIn) {
		if (iterIn.ptr == valIn) {
			return false;
		}
		else {
			return true;
		}
	}
	
}



