// ��������Ʈ�� ���� ������ �ϴ� bfs����

#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int c, n;
vector<int> v[MAX];
bool check[MAX];

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n;
	for (int i = 0; i < n; i++) { // ��������Ʈ ���� => ���⼺�� ���� �׷���
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	check[1] = true;
	int answer = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
				answer++;
			}
		}
	}
	cout << answer;
}