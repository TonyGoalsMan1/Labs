#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cmath>
#include <conio.h>
#include "my_vector.h"
using namespace std;




void assert(bool balayka)
{
	if (!balayka) {
		cout << "Condition file mission failed";
		exit(1);
	}
	else
		cout << "Uspeh pazani";
}


void test_pushBack_emptyVector() 
{
	vector v = createVector(15);
	pushBack(&v, 10);
	assert(v.size == 1);
}
void test_pushBack_fullVector()
{
	vector k = createVector(3);
	
	for(int i = 0; i < 4; i++)
		pushBack(&k, i);
	assert(k.size == 4);
}
void test_popBack_notEmptyVector() 
{
	vector v = createVector(0);
	pushBack(&v, 10);

	assert(v.size == 1);
	
	popBack(&v);
	assert(v.size == 0);
	assert(v.capacity == 1);
	
}

void test_atVector_notEmptyVector()
{
	vector v = createVector(0);
	pushBack(&v, 1);
	pushBack(&v, 2);
	int* second = atVector(&v, 1);
	int value = *second;
	assert(value == 2);
}
void test_atVector_requestToLastElement1()
{
	vector v = createVector(0);
	pushBack(&v, 1);
	pushBack(&v, 2);
	int* second = atVector(&v, 1);
	int value = *second;
	assert(value == 2);
}
void testback()
{
	vector v = createVector(0);
	pushBack(&v, 1);
	pushBack(&v, 2);
	int* second = back(&v);
	int value = *second;
	assert(value == 2);
}
void testfront()
{
	vector v = createVector(0);
	pushBack(&v, 1);
	pushBack(&v, 2);
	int* second = front(&v);
	int value = *second;
	assert(value == 1);
}
void test() {
	 test_pushBack_emptyVector();
	 cout << endl;
	 test_pushBack_fullVector();
	 test_popBack_notEmptyVector();
	 test_atVector_notEmptyVector();
	 test_atVector_requestToLastElement1();
	 testback();
	 testfront();
}

void main()
{
	vector vec, vec1;
	
	vec = createVector(10);
	vec1 = createVector(9);
	test();
	

}

