// ��Ʈ������ ���� 2��������(1, 2, 4, 8 ...)�� ���س�

#include <bits/stdc++.h>
using namespace std;

int k;

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;

	int size = 1;
	while (size < k) { // �ݺ����� ���� k���� ū ���� ���� 2���������� ���س�, k�� 6�̸� 8�� ��
		size <<= 1;
	}

	int count = 0;
	//int val = 0;
	int temp = size;
	while (k > 0) {
		if (k >= temp) {
			k -= temp;
		}
		else {
			temp /= 2;
			count++;
		}
	}
	cout << size << " " << count;
}