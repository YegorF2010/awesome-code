#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Vector{
	int *ar;
	int MX;
public:
	Vector(){ MX = 3; ar = new int[3]; }
	Vector(const Vector& v){
		for (int i = 0; i < MX; i++){
			this->ar[i] = v.ar[i];
		}
	}
	void const_mult(int var){
		for (int i = 0; i < MX; i++){
			this->ar[i] *= var;
		}
	}
	friend void coll(const Vector& v1, const Vector& v2){
		double var = v2.ar[0] / v1.ar[0];
		if (v2.ar[1] / v1.ar[1] == var && v2.ar[2] / v1.ar[2] == var)
			cout << "yes";
	}
	friend int gcd(int a, int b);
	friend void check(const Vector& v1, const Vector& v2){
		bool flag = 1;
		for (int i = 0; i < v1.MX; i++){
			if (!(v1.ar[i] / gcd(v1.ar[i], v2.ar[i]) == v2.ar[i] / gcd(v1.ar[i], v2.ar[i]))){
				cout << "no";
				flag = 0;
				break;
			}
		}
		if (flag)cout << "yes";
	}
	void get(){
		char ch=' ';
		int k = 0;
		string s;
		do{
			do{
				cin.get(ch);
				if (ch >= '0' &&ch <= '9')s += ch;
				if (ch == ')') break;
			}while (ch != ',');
			this->ar[k++] = stoi(s);
			s = "";
		} while (ch != ')');
		cin.get(ch);
	}
	void show(){
		cout << "(";
		for (int i = 0; i < MX; i++){
			cout << ar[i] << ',';
		}
		cout << '\b' << ')'<<endl;
	}
};
int gcd(int a, int b){
	if (b == 0)
		return abs(a);
	return gcd(b, a%b);
}
int main(){
	Vector v1,v2;
	v1.get();
	v2.get();
	//v1.show();
	//v2.show();
	//check(v1, v2);
	coll(v1, v2);

	system("pause>void");
	return 0;
}