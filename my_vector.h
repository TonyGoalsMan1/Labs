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
	vek.data = (int*)calloc(sizeof(int), n);
	return vek;
	cout << "ok0\n";
}

void reserve(vector* v, size_t Newcapacity)
{
	if (Newcapacity == 0)
		v->data = 0;
	if (Newcapacity < v->size) {
		v->size = Newcapacity;
		v->data = (int*)calloc(sizeof(int), Newcapacity);
		if (!v->data)
		{
			cout << " пацаны к успеху";
			exit(1);
		}
	}
	v->capacity = Newcapacity;
	//Если ОС не смогла выделить необходимый фрагмент памяти, вывести
	//сообщение в поток ошибок и прервать выполнение программы.

}
void clear(vector* v)
{
	v->size = 0;
	cout << "ok2\n";
}
void shrinkToFit(vector* v)
{
	if (v->size < v->capacity)
		v->capacity = v->size;
	cout << "ok3\n";
}
void deleteVector(vector* v)
{
	v->capacity = 0;
	v->size = 0;
	free(v->data);
}
bool isEmpty(vector* v)
{
	cout << "ok5\n";
	return v->capacity == 0 ? 1 : 0;

}
bool isFull(vector* v)
{
	cout << "ok6\n";
	return v->size == v->capacity ? 1 : 0;

}

int getVectorValue(vector* v, size_t i)
{
	cout << "ok7\n";
	return v->data[i];
}

void pushBack(vector* v, int x)
{
	
	if (v->capacity == v->size)
	{
		if(v->capacity==0)
			reserve(v, 1);
		else 
			reserve(v, v->capacity * 2);
	}


	v->data[v->size] = x;
	cout << v->data[0];
	v->size++;
	cout << v->size;
}


void popBack(vector* v)
{
	v->data[v->size] = 0;
	v->size = v->size - 1;

}