#include <iostream>
#include "MyVector.h"
#include "tests.h"
int main() {
	/*NSMyVector::MyVector v(10);
	for (int i = 0;i < v.size();i++) {
		v[i] = i;
	}
	for (int i = 0;i < v.size();i++) {
		std::cout << v[i] << std::endl;
	}
	std::cout << std::endl;
	for (auto iter = v.begin();iter != v.end();++iter) {
		std::cout << *iter << std::endl;
	}*/
	try{
		test();
		std::cout << "-------------------------------------------------------------" << std::endl;
		testCopy();
	}
	catch (NSMyVector::MyVectorException& e) {
		std::cout << e.what(); 
	}
}