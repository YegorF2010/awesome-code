#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>

using namespace std;

class Student{
	string FIO_date;
	string address_phone;
	string faculty;
	string course;
public:
	Student() :FIO_date(""), address_phone(""), faculty(""), course(""){}
	Student(const Student& s);
	//~Student();
	//void set(string f, string n, string p, int d, string ad, string ph, string fc, string cr){
	//	family = f; name = n; patronymic = p; address = ad; phone = ph; faculty = fc; course = cr;
	//}
	void set(string s, int ix, int* ar){
		s = s.substr(ar[ix], ar[ix + 1] - ar[ix]);

		int k = 0;
		int i_beg = 0;
		for (i_beg = 0; i_beg < s.size(); i_beg++){
			if (s.at(i_beg) == ' ' && i_beg == 0) continue;
			if (s.at(i_beg) == ' ') k++;
			if (k>3) break;
			FIO_date += s.at(i_beg);
		}

		for (int i_end = s.size() - 1; s.at(i_end) != ' '; i_end--){
			if (s.at(i_end) == '.') continue;
			course += s.at(i_end);
		}
		reverse(course.begin(), course.end());

		int i = s.rfind(' ');
		for (i = i - 1; s.at(i) != ' '; i--){
			if (s.at(i) == ',') continue;
			faculty += s.at(i);
		}
		reverse(faculty.begin(), faculty.end());

		for (--i; i > i_beg; i--){
			address_phone += s.at(i);
		}
		reverse(address_phone.begin(), address_phone.end());
	}
	void show(){
		cout << FIO_date << ' ' << address_phone << ' ' << faculty << ", " << course;
	}
	string retF(){
		return faculty;
	}
	string retC(){
		return course;
	}
	string retY(){
		string t;
		int i = FIO_date.size() - 2;
		int k = 0;
		while (k < 4){
			t += FIO_date.at(i - k++);
		}
		reverse(t.begin(), t.end());
		return t;
	}
};

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str;
	char ch = ' ';
	while (ch != '\n'){
		cin.get(ch);
		if (ch == '\n') break;
		str += ch;
	}

	int cntSnt = 0;
	int *ar = new int;
	ar[0] = 0;
	for (int i = 0; i < str.size(); i++){
		if (str.at(i) == '.') {
			ar[++cntSnt] = i + 1;
		}
	}

	Student *stu = new Student[cntSnt];
	for (int ix = 0; ix < cntSnt; ix++){
		stu[ix].set(str, ix, ar);
	}
	//for (int ix = 0; ix < cntSnt; ix++){
	//	stu[ix].show();
	//	cout << ". ";
	//}
	cout << endl << endl;
	int j = ar[cntSnt];
	string f, c, y;
	for (++j; str.at(j) != ' '; j++){
		if (str.at(j) == ',')continue;
		f += str.at(j);
	}
	for (++j; str.at(j) != ' '; j++){
		if (str.at(j) == ',')continue;
		c += str.at(j);
	}
	for (++j; j < str.size(); j++){
		if (str.at(j) == ',')continue;
		y += str.at(j);
	}
	int spec = 0;
	for (int i = 0; i < cntSnt; i++){
		if (stu[i].retF() == f) spec++; 
	}
	for (int i = 0; i < cntSnt; i++){
		if (stu[i].retF() == f && spec>1) { stu[i].show(); cout << "; "; }
		else  if (stu[i].retF() == f && spec==1) { stu[i].show(); cout << ". "; }
	}
	cout << "\b\b" << ". ";

	spec = 0;
	for (int i = 0; i < cntSnt; i++){
		if (stu[i].retC() == c) spec++;
	}
	for (int i = 0; i < cntSnt; i++){
		if (stu[i].retC() == c && spec>1) { stu[i].show(); cout << "; "; }
		else if (stu[i].retC() == c && spec==1) { stu[i].show(); cout << ". "; }
	}
	cout << "\b\b" << ". ";

	spec = 0;
	for (int i = 0; i < cntSnt; i++){
		if (stoi(stu[i].retY()) >= stoi(y)) spec++;
	}
	for (int i = 0; i < cntSnt; i++){
		if (stoi(stu[i].retY()) >= stoi(y) && spec>1) { stu[i].show(); cout << "; "; }
		else if (stoi(stu[i].retY()) >= stoi(y) && spec==1) { stu[i].show(); cout << ". "; }
	}
	cout << "\b\b" << ". ";


	system("pause>void");
	return 0;
}