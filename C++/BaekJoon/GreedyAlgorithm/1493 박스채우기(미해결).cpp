// l, w, h�� Ȧ���� ��쿡 ���� ó���� �ʿ���

#include <bits/stdc++.h>
using namespace std;

int l, w, h, n;
vector<pair<int, int>> v;

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> w >> h >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b)); // first ���� second ����
	}
	sort(v.begin(), v.end(), greater<pair<int, int>>()); // ������ �������� ����
	int count = 0;
	pair<int, int> p(-1, -1); // first ���� second ��������
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == 0) continue;
		int k = pow(2, v[i].first);
		if (k <= l && k <= w && k <= h) {
			if (p.first == -1) { // ������ ���
				int cal = (l / k) * (w / k) * (h / k); // �ʿ��� ť�갳��
				if (cal > v[i].second) { // ����
					count += v[i].second; // ����� ť�갳�� ����
					cal -= v[i].second;
					p.first = v[i].first;
					p.second = cal;
				}
				else { // ������ �� ����
					count += cal;
					cout << count;
					return 0;
				}
			}
			else {
				int po = pow(2, p.first);
				int cal = pow(po / k, 3) * p.second; // �ʿ��� ť�갳��
				if (cal > v[i].second) { // ����
					count += v[i].second; // ����� ť�갳�� ����
					cal -= v[i].second;
					p.first = v[i].first;
					p.second = cal;
				}
				else { // ������ �� ����
					count += cal;
					cout << count;
					return 0;
				}
			}
		}
	}
	cout << -1;
	return 0;
}