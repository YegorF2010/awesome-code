#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class MultiSet{
	int x, y, z, w;
public:
	MultiSet() :x(0), y(0), z(0), w(0){}
	MultiSet(int x, int y, int z, int w) :x(x), y(y), z(z), w(w){}
	MultiSet f(MultiSet* m1, MultiSet* m2){
		set<int> s1;
		set<int> set1 = { m1->x, m1->y, m1->z, m1->w };
		set<int> set2 = { m2->x, m2->y, m2->z, m2->w };

		//set_symmetric_difference(set1.begin(), set1.end(),set2.begin(), set2.end(),inserter(s1, s1.begin()));

		int temp[4]; int k = 0;
		for (auto el : s1){
			temp[k++] = el;
		}

		return MultiSet(temp[0], temp[1], temp[2], temp[3]);
	}
	void show(){
		printf_s("(%i,%i,%i,%i)", x, y, z, w);
	}
};

int main(){
	int x1, y1, z1, w1, x2, y2, z2, w2;
	(scanf_s("(%i,%i,%i,%i),(%i,%i,%i,%i)", &x1, &y1, &z1, &w1, &x2, &y2, &z2, &w2));
	MultiSet* m1[2];
	m1[0] = new MultiSet(x1, y1, z1, w1);
	m1[1] = new MultiSet(x2, y2, z2, w2);

	MultiSet m;
	m=m.f(m1[0], m1[1]);
	m.show();

	system("pause>void");
	return 0;
}