// priority_queue�� ����Ͽ� �ذ�
// 1. ���������� �������� ����
// 2. ���⼭ ť�� ������� �� ���� �������� �ǹ��� 
// => size�� 4��� 4���� ������ �������� 4�� ������ ������ �ذ� ����
// 3. ���������� > size �̸� ť�� ���� �߰�
// 4. ���������� <= size �̸� ť�� �ִ� ���� ���� ���� < ���� ���� ���� �� ��� ���� ����
// => pq.pop(), pq.push(�����������)

#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int n;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, w;
		cin >> d >> w;
		v.push_back(make_pair(d, w));
	}
	sort(v.begin(), v.end(), compare);
	sort(v.begin(), v.end(), [](pair<int,int> &a, pair<int,int> &b) {
		if (a.second != b.second) return a.second > b.second;
		return a.first < b.first;
	});
	priority_queue<int, vector<int>, greater<int>> pq; // ���� ���� �������� ����
	pq.push(v[0].second);
	for (int i = 1; i < n; i++) {
		if (pq.size() < v[i].first) {
			pq.push(v[i].second);
		}
		else {
			if (pq.top() < v[i].second) {
				pq.pop();
				pq.push(v[i].second);
			}
		}
	}
	int answer = 0;
	while (!pq.empty()) {
		answer += pq.top();
		pq.pop();
	}
	cout << answer;
}

/*#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int n;
vector<pair<int, int>> v; // first : ��������, second : ����������
int d[MAX];

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, w;
		cin >> d >> w;
		v.push_back(make_pair(w, d));
	}
	sort(v.begin(), v.end(), greater<pair<int, int>>());

	int idx = 0;
	for (int i = 0; i < n; i++) {
		idx = v[i].second;
		while (idx >= 1) {
			if (d[idx] == 0) {
				d[idx] = v[i].first;
				break;
			}
			else {
				--idx;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < MAX; i++) {
		answer += d[i];
	}
	cout << answer;
}*/

/*
7
4 60
4 40
1 20
2 50
3 30
4 10
6 5
*/