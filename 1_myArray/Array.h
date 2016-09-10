#pragma once


class Array{
	int size_;
	int *ptr;
public:
	Array();
	explicit Array(int);
	Array(const Array&);
	Array& operator=(const Array&);
	virtual ~Array();
	
	void Swap(Array&);
	int& operator[](int );
	int& operator[](int)const;
};

