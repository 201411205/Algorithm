#include <bits/stdc++.h>
using namespace std;

typedef struct people {
	int age;
	string name;
	people(int _age, string _name) : age(_age), name(_name) {};
} P;

bool compare1(P p1, P p2) { // ��ü ����
	if (p1.age == p2.age) return p1.name > p2.name; // ���������� ����(��������)
	else return p1.age > p2.age; // ���̼����� ����(��������)
}

bool compare2(int a1, int a2) { // �������� ����
	return a1 > a2;
}

int main() {
	int n[] = { 21, 15, 66, 66, 100 };

	sort(n, n + 5, compare2);
	cout << "�������� ���� compare �Լ� ����" << "\n";
	for (int i : n) {
		cout << i << " ";
	}
	cout << "\n";

	sort(n, n + 5);
	cout << "�������� ����" << "\n";
	for (int i : n) {
		cout << i << " ";
	}
	cout << "\n";

	sort(n, n + 5, greater<int>());
	cout << "�������� ���� greater ���" << "\n";
	for (int i : n) {
		cout << i << " ";
	}
	cout << "\n";

	string str[] = { "abc", "bca", "cab", "cba", "acb" };
	int a[] = { 10, 20, 30, 30, 40 };
	
	vector<P> v;
	for (int i = 0; i < 5; i++) {
		P p(a[i], str[i]);
		v.push_back(p);
	}
	cout << "��ü ���� ��" << "\n";
	for (P p : v) {
		cout << "age : " << p.age << " name : " << p.name << " , ";
	}
	cout << "\n";
	sort(v.begin(), v.end(), compare1);
	cout << "��ü ���� ��" << "\n";
	for (P p : v) {
		cout << "age : " << p.age << " name : " << p.name << " , ";
	}
	cout << "\n";
}