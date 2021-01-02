#include <iostream>
#include <string>
using namespace std;

int main() {
	// getline �Լ��� �� ������ ����

	// 1. istream ���̺귯���� ���� cin.getline()
	// ���ڹ迭�̸� n - 1���� ���� ������ŭ �о�� str�� ����
	// ����° ������ delim�� ������ �Է��� ������ '\n'���� �ν�
	// delim�� �������ָ� �� delim ���� �������� �о str�� ����

	// cin.getline(char* str, streamsize n);
	// cin.getline(char* str, streamsize n, char delim);

	char a[10], b[10];
	cin.getline(a, 10);
	cin.getline(b, 10, ',');

	// 2. string ���̺귯���� getline()
	// �ִ� ���ڼ��� �Է����� ����
	// ���ϴ� ������(delim)�� ���� �� ���� ��� ���ڿ��� �Է¹޾� string ��ü�� ����

	//getline(istream& is, string str);
	//getline(istream& is, string str, char delim);

	int n;
	string str;
	cin >> n;
	cin.ignore(); // => n�� �Է¹��� �� ���� '\n'�� �״�� getline�� ���� ������ �ذ��ϱ� ����
	getline(cin, str);
}