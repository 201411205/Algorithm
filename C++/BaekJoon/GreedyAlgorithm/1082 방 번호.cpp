// 1. �ִ��� ���� ���ڸ� �̾Ƴ��� ��
// 2. �� ���ڵ��� �ִ��� ū ���ڿ��� ��

// �׸��� �˰����� ���
#include <bits/stdc++.h>
using namespace std;

int n, money;
int num[11];
vector<int> v; // ������ ����� ��� ����
vector<int> answer; // ���ڸ� ��� ����

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int ma = 51, mb = 51;
	int ax = 0, bx = 0;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		if (i >= 1) { // ���� 0�� ������ �ٸ� ������ ���� �� ���� ���ڸ� ���ϱ� ����
			if (ma >= num[i]) { 
				ma = num[i]; // ma�� ���� 0�� ������ �ٸ� ������ ���� �� ���� ����
				ax = i; // ma�� �ε���
			}
		}
		if (mb >= num[i]) { // ���� 0���� ������ �߿��� ���� �� ���� ���ڸ� ����
			mb = num[i]; // mb�� ���� 0���� ������ �߿��� ���� �� ���� ����
			bx = i; // mb�� �ε���
		}
	}
	cin >> money;
	int tmp = money;
	if (tmp < ma) { // ma ���� ������ �ִ� ���� ������ 0�ۿ� ����� ����
		cout << 0;
		return 0;
	}
	v.push_back(ma);
	answer.push_back(ax);
	tmp -= ma;
	int rm = 0; // v�� �ִ��� �ְ� ���� ��
	while (1) { // v�� mb�� �ִ��� ����
		if ((tmp - mb) < 0) {
			rm = tmp;
			break;
		}
		v.push_back(mb);
		answer.push_back(bx);
		tmp -= mb;
	}
	int ix = 0;
	int nx = n - 1;
	while (rm != 0) {
		if (ix == v.size() || nx < 0) {
			break;
		}
		if (answer[ix] == nx) { // answer�� num�� ������ �ε����� �ѱ�
			ix++;
			continue;
		}
		if ((num[nx] - v[ix]) <= rm) { // ���������� 
			rm -= (num[nx] - v[ix]);
			answer[ix] = nx;
			v[ix] = num[nx];
			ix++;
			nx = n - 1;
		}
		else {
			nx--;
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}
}