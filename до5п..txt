#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cmath>
#include <conio.h>

using namespace std;


typedef struct vector 
	{
		 int* data; // указатель на элементы вектора
		 size_t size; // размер вектора
		 size_t capacity; // вместимость вектора
	} vector;

vector createVector(size_t n)
{
	vector vek;
	vek.capacity = n;
	vek.size = 0;
	return vek;
}

void reserve(vector *v, size_t Newcapacity)
{
	if (Newcapacity == 0)
		v->data = 0;
	if (Newcapacity < v->size)
		v->size = Newcapacity;

	v->capacity = Newcapacity;
	//доделать
}
void clear(vector* v)
{
	v->size = 0;
}
void shrinkToFit(vector* v)
{
	if (v->size < v->capacity)
		v->capacity = v->size;
}
void deleteVector(vector* v)
{//
	v->capacity = 0;
	v->size = 0;
}
bool isEmpty(vector* v)
{
	return v->capacity == 0 ? 1 : 0;
}
bool isFull(vector* v)
{
	return v->size == v->capacity ? 1 : 0;
}

int getVectorValue(vector* v, size_t i)
{
	return v->data[i];
}

void pushBack(vector* v, int x)
{
	if(v->capacity == v->size)
	{
		reserve(v, v->capacity * 2);
	}
	v->data[v->size] = x;
	v->size++;
}
void main()
{
	
	vector vec, vec1;
	
	vec = createVector(10);
	vec1 = createVector(9);
	//reserve(&vec, 15);
	reserve(&vec, 7000);
	cout << vec.capacity;
}

