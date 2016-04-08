#include <iostream>

using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int **ar = new int*[n];
	for (int i = 0; i < n; i++){
		ar[i] = new int[m];
	}
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> ar[i][j];
		}
	}
	int **ar2 = new int*[m];
	for (int i = 0; i < m; i++){
		ar2[i] = new int[n];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			ar2[j][i] = ar[i][j];
		}
	}
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout << ar2[i][j]<<' ';
		}
	}


	system("pause>void");
	return 0;
}