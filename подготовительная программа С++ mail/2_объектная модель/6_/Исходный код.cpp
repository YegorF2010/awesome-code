#include <iostream>
#include <set>
#include <list>

using namespace std;
void show(list< int*> l);
int main(){
	int x1, y1, z1, w1;
	scanf_s("(%i,%i,%i,%i)", &x1, &y1, &z1, &w1);

	list< int*> l1 = {&x1,&y1,&z1,&w1};

	for (auto iter = l1.rbegin(); iter != l1.rend(); iter++){
		list< int*>::reverse_iterator it_temp = iter;
		it_temp++;
		if (it_temp.base() != l1.begin()){
			if ((**it_temp < 0)) {
				**iter = (-1)*(**iter);
			}
		}
		//cout << *iter << ' ';
	}


	show(l1);
	system("pause>void");
	return 0;
}
void show(list< int*> l){
	cout << "(";
	list< int*>::iterator it = l.end();
	it--;
	for (auto iter = l.begin(); iter != it; iter++){
		cout << **iter<<',';
	}
	cout <<*( l.back())<<")";
}