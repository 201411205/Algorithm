// ���α׷��ӽ� ü���� ������ ������ ����

// 5 2 2
// 2 3
// 1 2
// �� ������ ��� 2�� ���� ���� ī���� �����ϹǷ� 3������ ��� �� �� �� ���� ��

#include <bits/stdc++.h>
#define MAX 11
using namespace std;

int n, s, r;
vector<int> a; // ī���� �ջ�� ��
vector<int> b; // ������ ī���� ������ ��

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s >> r;
	int answer = s;
	a.resize(s);
	b.resize(r);
	for (int i = 0; i < s; i++) 
		cin >> a[i];
	for (int i = 0; i < r; i++) 
		cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < a.size(); i++) { // ī���� �ջ�� ���� ������ ī���� ������ ���� ���
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) {
				a[i] = -1;
				b[j] = -1;
				answer--;
				break;
			}
		}
	}
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j] - 1 || a[i] == b[j] + 1) {
				a[i] = -1;
				b[j] = -1;
				answer--;
				break;
			}
		}
	}
	cout << answer;
}
