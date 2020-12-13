#include <bits/stdc++.h>

#define MAX 1001
#define BUSMAX 100001
#define INF 987654321

using namespace std;

typedef struct Node { // ���� ���� ����, ��� ����
	int end;
	int cost;
};

int n, m;
int d[MAX]; // �ּҺ��
vector<Node> bus[BUSMAX]; // ��������
int start, dest;

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bus[a].push_back(Node{ b, c });
	}

	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}

	cin >> start >> dest;

	d[start] = 0; // �ڱ��ڽ����� ���� ���
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int cur = pq.top().second;
		int fee = -pq.top().first;
		pq.pop();
		if (d[cur] < fee) continue; // ����� �ּ� ��뺸�� ��Ҷ�
		for (int i = 0; i < bus[cur].size(); i++) {
			int next = bus[cur][i].end;
			int nextfee = fee + bus[cur][i].cost;
			if (nextfee < d[next]) {
				d[next] = nextfee;
				pq.push(make_pair(-nextfee, next));
			}
		}
	}

	cout << d[dest];

	return 0;
}