#include "Array.h"
#include <new>			//exception
#include <algorithm>	//swap
#include <stdexcept>

Array::Array(): size_(0), ptr(nullptr) {}

Array::Array(int size) throw(std::bad_alloc):size_(size), ptr(new int[size]) {}

Array::Array(const Array& a): size_(a.size_), ptr(new int[size_]) {
	for (int i = 0; i < a.size_; i++) {
		*(ptr + i) = *(a.ptr + i);
	}
}

Array& Array::operator=(const Array& a) {
	if (this != &a) {
		delete[] ptr;
		size_ = a.size_;
		ptr = new int[a.size_];	
		for (int i = 0; i < a.size_; i++) {
			*(ptr + i) = *(a.ptr + i);
		}
	}
	return *this;
}

Array::~Array() {delete[] ptr;}

void Array::Swap(Array& other) {
	std::swap(ptr, other.ptr);
	std::swap(size_, other.size_);
}

int& Array::operator[](int d){
	if (d >= 0 && d < size_) { return *(ptr + d); }
	else throw std::out_of_range("Index out of range!");
}

int& Array::operator[](int d) const{
	if (d >= 0 && d < size_) { return *(ptr + d); }
	else throw std::out_of_range("Index out of range!");
}
