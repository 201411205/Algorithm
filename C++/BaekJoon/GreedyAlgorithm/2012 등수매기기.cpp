// �Է°� ������ �ִ� ���� => int�����δ� ��� �Է��� ������ ���� ���� long long �� ����ؾ���

#include <bits/stdc++.h>
#define MAX 500001
using namespace std;

int n;
int a[MAX];

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long answer = 0; // ����� 500000 ������ �ڿ����� �̷���� �־� int���� ��� ���� �� ����
	for (int i = 0; i < n; i++) {
		answer += abs(a[i] - (i + 1));
	}
	cout << answer;
}