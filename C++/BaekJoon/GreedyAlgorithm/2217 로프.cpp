#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int n;
int rope[MAX];

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}
	sort(rope, rope + n); // ���� �߷����� �������� ����

	// ������ ������ ������ ��� ����ص� ��
	// ���� �տ������� �ִ��߷��� ���Ͽ� ���� ū ���� ����ϸ� ��
	int max = 0;
	for (int i = 0; i < n; i++) { 
		if (max < rope[i] * (n - i)) {
			max = rope[i] * (n - i);
		}
	}
	cout << max;
}

// 5
// 10 20 30 40 50
// �� 90