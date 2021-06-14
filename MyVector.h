#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <exception>
namespace NSMyVector {
	class MyVectorIterator;
	class MyVector {
		int* firstLogic;
		int* firstHard;
		int* lastLogic;
		int* lastHard;
		int* arr;
		int count;
		int countHard;
	public:
		MyVector();
		MyVector(int countIn, int valIn);
		MyVector(int counIn);
		MyVector(const MyVector&);
		virtual ~MyVector();
		MyVectorIterator begin();
		MyVectorIterator end();
		void resize(int,int);
		void pushBack(int);
		void pushFront(int);
		void popBack();
		void popFront();
		int& operator[](int);
		MyVectorIterator find(int);
		int size() { return count; }
	private:
		void resizeCloud();
	};
	class MyVectorIterator {
		int* ptr;
	public:
		MyVectorIterator();
		MyVectorIterator(int*);
		int& operator*();
		int& operator ++();
		int& operator --();
		bool operator ==(int*);
		bool operator ==(const MyVectorIterator&);
		bool operator !=(int*);
		bool operator !=(const MyVectorIterator&);
		friend class LinkedList;
		friend bool operator ==(int*, const MyVectorIterator&);
		friend bool operator !=(int*, const MyVectorIterator&);
	};
	bool operator ==(int*, const MyVectorIterator&);
	bool operator !=(int*, const MyVectorIterator&);
	class MyVectorException : std::exception {
	public:
		virtual const char* what() const throw() { return "MyVectorException"; }
	};

}
#endif MYVECTOR_H

