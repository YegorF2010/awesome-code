// 2_myPointer.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const int MAX = 10;
float fmemory[MAX];    
int pmemory[MAX];
int fmem_top = 0;
int pmem_top = 0;

class Float {
	int addr;
public:
	Float(float n) {
		fmemory[fmem_top] = n;
		addr = fmem_top;
		fmem_top++;
	}
	int operator&() {
		return addr;
	}
};

class ptrFloat {
	int addr;
public:
	ptrFloat(int n) {
		pmemory[pmem_top] = n;
		addr = pmem_top;
		pmem_top++;
	}
	float& operator*() {
		return fmemory[pmemory[addr]];
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Float var1 = 1.234;  
	Float var2 = 5.678; 
	ptrFloat ptr1 = &var1;  
	ptrFloat ptr2 = &var2;  
	cout << " *ptr1 =" << *ptr1; 
	cout << " *ptr2 = " << *ptr2; 
	*ptr1 = 7.123;  
	*ptr2 = 8.456;  
	cout << " *ptr1 =" << *ptr1; 
	cout << " *ptr2 = " << *ptr2;

	system("pause>void");
    return 0;
}

