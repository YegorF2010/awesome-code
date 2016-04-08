#include <iostream>

using namespace std;

class cStack{
	char ar[200];
	int top;
	int cnt;
public:
	cStack() :top(-1),cnt(0){}
	void push(char ch){ cnt++; ar[++top] = ch; }
	char pop(){ return ar[top--]; }
	int fun_cnt(){ return this->cnt; }
};
int main(){
	cStack s1;
	char c=' ';
	do{
		c = getchar();
		if (c == EOF) break;
		s1.push(c);
	} while (c != EOF);

	int k = 0;
	while (k != s1.fun_cnt()){
		cout << s1.pop();
		k++;
	}


	system("pause>void");
	return 0;
}


