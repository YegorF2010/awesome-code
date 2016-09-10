#include <iostream>
#include "Array.h"
#define FOR(MX) for (size_t i=0;i<MX;++i)

using namespace std;

int main() {	
	const int size = 10;
	Array arr1(size);

	FOR(size) {
		arr1[i] = i*i;
		//cin >> arr[i];
	}

	FOR(size) cout << arr1[i] << ' ';


	Array arr2(arr1);
	FOR(size) cout << arr2[i] << ' ';

	Array arr3;
	arr3 = arr1;
	FOR(size) cout << arr3[i] << ' '; 

	Array arr4;
	arr3 = arr3;
	FOR(size) cout << arr3[i] << ' '; 

	_getwch();
	return 0;
}