#include <iostream>
#include "MyVector.h"
using namespace NSMyVector;
bool testVal(MyVector& vIn, int testCase) {
	for (int i = 0;i < 10;i++) {
		if (vIn[i] != i) {
			std::cout << "test val ¹" << testCase << " Not proved" << std::endl;
			return false;
		}
	}
	return true;
}
bool testCount(MyVector& vIn, int countIn, int testCase) {
	if (countIn == vIn.size()) {
		return true;
	}
	else {
		std::cout << "test count ¹" << testCase << " Not proved" << std::endl;
		return false;
	}
}
void testCheck(MyVector& vIn, int countIn, int testCase) {
	if (!(testVal(vIn, testCase) && testCount(vIn, countIn, testCase))) {
		std::cout << "test Case ¹" << testCase << " Not proved" << std::endl;
	}
}
void testPrint(MyVector& vIn) {
	for (int i = 0;i < vIn.size();i++) {
		std::cout << vIn[i] << " ";
	}
	std::cout << std::endl;
}
void test(){
	MyVector a(10);
	testCount(a, 10, 1);
	for (int i = 0;i < 10;i++) {
		a[i] = i;
	}
	testCheck(a, 10, 2);
	testPrint(a);
	for (int i = 0;i < 10;i++) {
		a.popFront();
	}
	testCount(a, 0, 3);
	for (int i = 9;i >=0;i--) {
		a.pushFront(i);
	}
	testCheck(a, 10, 4);
	testPrint(a);
	for (int i = 0;i < 10;i++) {
		a.popBack();
	}
	testCount(a, 0, 5);
	for (int i = 0;i < 10;i++) {
		a.pushBack(i);
	}
	testCheck(a, 10, 6);
	testPrint(a);
	for (int i = 9;i >= 0;i--) {
		a.pushFront(i);
	}
	testCheck(a, 20, 7);
	testPrint(a);
	for (int i = 0;i < 10;i++) {
		a.popFront();
	}
	testCount(a, 10, 8);
	for (int i = 0;i < 10;i++) {
		a.pushBack(i);
	}
	testCheck(a, 20, 9);
	testPrint(a);
	for (int i = 0;i < 10;i++) {
		a.popBack();
	}
	testCount(a, 10, 10);
	testPrint(a);
}


void testCopy() {
	MyVector a(10);
	MyVector b=a;
	testCount(b, 10, 1);
	for (int i = 0;i < 10;i++) {
		a[i] = i;
	}
	b = a;
	testCheck(b, 10, 2);
	testPrint(b);
	for (int i = 0;i < 10;i++) {
		a.popFront();
	}
	b = a;
	testCount(b, 0, 3);
	for (int i = 9;i >= 0;i--) {
		a.pushFront(i);
	}
	b = a;
	testCheck(b, 10, 4);
	testPrint(b);
	for (int i = 0;i < 10;i++) {
		a.popBack();
	}
	b = a;
	testCount(b, 0, 5);
	for (int i = 0;i < 10;i++) {
		a.pushBack(i);
	}
	b = a;
	testCheck(b, 10, 6);
	testPrint(b);
	for (int i = 9;i >= 0;i--) {
		a.pushFront(i);
	}
	b = a;
	testCheck(b, 20, 7);
	testPrint(b);
	for (int i = 0;i < 10;i++) {
		a.popFront();
	}
	b = a;
	testCount(b, 10, 8);
	for (int i = 0;i < 10;i++) {
		a.pushBack(i);
	}
	b = a;
	testCheck(b, 20, 9);
	testPrint(b);
	for (int i = 0;i < 10;i++) {
		a.popBack();
	}
	b = a;
	testCount(b, 10, 10);
	testPrint(b);
}