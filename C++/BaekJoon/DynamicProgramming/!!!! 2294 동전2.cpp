// �������� DP����
// �� ����� ���� ���� �ּ� ����� ���� ������ ����
// d[n] : ���� n�� ����� ����� �� 
// ���� d[k]
// ���� d[n]�� INF�� �ʱ�ȭ�� �� min�� ����Ͽ� ����� ���� ��
// �� ������ ����Ͽ� ������ ����� ���� ��� ���

#include <bits/stdc++.h>
#define INF 10001
using namespace std;

int n, k;
int coin[101];
int d[INF];

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		d[i] = INF;
	}
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
		for (int j = coin[i]; j <= k; j++) {
			d[j] = min(d[j], d[j - coin[i]] + 1);
		}
	}
	if (d[k] == INF)
		cout << -1;
	else
		cout << d[k];
}