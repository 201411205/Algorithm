// bfs�����ε� ��������Ʈ�� ������� �ʰ� ť�� ���簪�� ���ϰų� �� ���� �־� ���� ã�� ���

#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int f, s, g, u, d;
bool check[MAX];

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> f >> s >> g >> u >> d;

	queue<pair<int, int>> q; // first ���� �� second ��ư�� ���� ��
	check[s] = true;
	q.push(make_pair(s, 0));
	while (!q.empty()) {
		int cur = q.front().first;
		int count = q.front().second;
		q.pop();
		if (cur == g) {
			cout << count;
			return 0;
		}
		else {
			int nextup = cur + u;
			int nextdown = cur - d;
			if (nextup <= f && check[nextup] == false) {
				q.push(make_pair(nextup, count + 1));
				check[nextup] = true;
			}
			if (nextdown >= 1 && check[nextdown] == false) {
				q.push(make_pair(nextdown, count + 1));
				check[nextdown] = true;
			}

		}
	}
	cout << "use the stairs";
	return 0;
}