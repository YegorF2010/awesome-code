#include <iostream>

using namespace std;

class Figure{
protected:
	double sq;
public:
	Figure() :sq(0){}
	virtual void sq2(){}
	virtual void show(){}
};
class Square :public Figure{
	int dS;
public:
	Square(int d):dS(d){}
	void sq2(){ sq = dS*dS; }
	void show(){ cout << sq<<", "; }
};
class Circle :public Figure{
	int dC;
public:
	Circle(int d) :dC(d){}
	void sq2(){ sq = 3.14*dC*dC; }
	void show(){ cout << sq << ", "; }
};
class Rectangle :public Figure{
	int hR;
	int wR;
public:
	Rectangle(int d1,int d2):hR(d1),wR(d2){}
	void sq2(){ sq = hR*wR; }
	void show(){ cout << sq << ", "; }
};
int main(){
	int side, radius, height, width;
	(scanf_s("s(%i), c(%i), r(%i,%i)", &side, &radius, &height, &width)); 
	{
		//char ch;
		//cin >> ch >>ch >> side >> ch >> ch >> ch >> 
		//	ch >> ch >> radius >> ch >> ch >> ch >> 
		//	ch >> ch >> height >>ch>> width>>ch;

		Figure* ar[3];
		ar[0] = new Square(side);
		ar[1] = new Circle(radius);
		ar[2] = new Rectangle(height, width);

		for (int i = 0; i < 3; i++){
			ar[i]->sq2();
		}
		for (int i = 0; i < 3; i++){
			ar[i]->show();
		}
		char ch = ' ';
		cout << "\b\b ";
	}
	

	system("pause>void");
	return 0;
}