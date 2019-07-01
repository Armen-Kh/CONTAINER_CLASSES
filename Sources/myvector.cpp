#include "myvector.hpp"
#include <cassert>
#include <cmath>


MyVector::MyVector(unsigned int s)	
{
	assert(size >= 0 && "Size is not acceptable!\n");

	if(s == 0){
		size = 0;
		capacity = 0;
		data = nullptr;		
	} 
	else {
		size = s;
		capacity = s < 16 ? 16 : std::pow(2, std::log2(s) + 1);
		data = new int[capacity];
	}
}

MyVector::~MyVector()
{
	if(size > 0) {
		delete[] data;
		data = nullptr;
	}
}


void MyVector::insert(unsigned int p, int v)
{
	assert(p >=0 && p <= size && "The position is not in the valid range.");

	if(size == 0){
		capacity = 16;
		data = new int[capacity];
		data[p] = v;
		return;
	}

	if(size == capacity) {
		capacity *= 2;

		int * temp = new int[capacity];
	        for(int i = 0; i < p; ++i) {
        	        temp[i] = data[i];
        	}

        	temp[p] = v;
       		for(int i = p + 1; i < size + 1; ++i) {
                	temp[i] = data[i - 1];
       		}

       		delete[] data;
		data = temp;
		temp = nullptr;
		return;
	}

	for(int i = size; i > p; --i) {
		data[i] = data [i - 1];
	}
	data[p] = v;

	++size;
}


void MyVector::remove(const unsigned int p)
{
	assert(p >=0 && p < size && "The index is not in the valid range.");
	
	for (int i = p; i < size - 1; ++i) {
		data[i] = data[i + 1];
	}

	--size;
	if((size <= capacity / 4) && (capacity > 16)) {
		capacity /= 2;
	}
}
	

int& MyVector::operator[] (const unsigned int i)
{
	assert(i >=0 && i < size && "The index is not in the valid range.");
	return data[i];
}

int& MyVector::operator[] (const unsigned int i) const
{
	assert(i >=0 && i < size && "The index is not in the valid range.");
	return data[i];
}

//return the first appropriate index or size if the value does not exist
unsigned int MyVector::find(int value) const
{
	for(int i = 0; i < size; ++i) {
		if(data[i] == value) {
			return i;
		}
	}
	return size;
}

unsigned int MyVector::get_size() const
{
	return size;
}

