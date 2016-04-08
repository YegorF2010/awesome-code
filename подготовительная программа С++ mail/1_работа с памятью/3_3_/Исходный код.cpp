#include <iostream>

using namespace std;

int main(){
	int n = 2, m = 3;
	int ar[2][3] = { {1,2,3}, {4,5,6} };

	int t;
	for (int i = 0; i < 2; ++i){
		for (int j = 0; j < 3; ++j){
			t = ar[i][j];
			ar[i][j] = ar[j][i];
			ar[j][i] = t;
		}
	}
	for (int i = 0; i < 2; ++i){
		for (int j = 0; j < 3; ++j){
			cout << ar[i][j];
		}
		cout << endl;
	}

	system("pause>void");
	return 0;
}