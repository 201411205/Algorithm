// ���� �׸��� �˰��� ����

#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int n, m;
int a[MAX];

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vector<int> v;
	while (n--) {
		int p, l;
		cin >> p >> l;
		memset(a, 0, sizeof(p));
		for (int i = 0; i < p; i++) {	
			cin >> a[i];
		}
		sort(a, a + p, greater<int>()); // �������� ����
		if (p >= l)
			v.push_back(a[l - 1]);
		else
			v.push_back(1); // �����ο����� ��û�ѻ���� ���� ��� ���ϸ����� 1�� �ִ°��� �ּ��� ���
	}
	sort(v.begin(), v.end());
	int answer = 0;
	for (int i = 0; i < v.size(); i++) {
		if (m - v[i] < 0) {
			break;
		}
		m -= v[i];
		answer++;
	}
	cout << answer;
}