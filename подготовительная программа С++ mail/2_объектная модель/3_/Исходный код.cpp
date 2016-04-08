#include <iostream>
#include <cmath>

using namespace std;

class A{
	//int a;
public:
	int a;
	friend int NOD(int a, int b);
	//friend void fun(A a1, A a2){
	//	if (a1.a / (NOD(a1.a, a2.a)) == a2.a / (NOD(a1.a, a2.a))) cout << "yes";
	//	else cout << "no";
	//}
};
int NOD(int a, int b){
	if (b == 0)
		return abs(a);
	return NOD(b, a%b);
}
int main(){
	double i = 3;
	printf_s("%f", i);
	A a1,a2;
	a1.a = 12; a2.a = 4;
	//fun(a1, a2);


	//int a = 12, b = 4;
	//cout << a / NOD(a, b) << ' ' << b / NOD(a, b);
	//cout << a1.a / NOD(a1.a, a2.a) << ' ' << a2.a / NOD(a1.a, a2.a);


	system("pause>void");
	return 0;
}
