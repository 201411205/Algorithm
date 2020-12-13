// ���ͽ�Ʈ�� �˰��� => �ִܰ��
#include <bits/stdc++.h>

#define INF 987654321
#define MAX 20001

using namespace std;
int v, e, start;
vector<pair<int, int>> a[MAX];
int d[MAX]; // �ִܰŸ�(���)*/

// *** priority_queue���� pair�� ������� ���� ��� ***
// ����ü�� �����Ͽ� ����ؾ� ��
typedef struct NODE {
	int end;
	int value;
};

void dijkstra() {
	d[start] = 0; // start = 1
	// *** ���� ť���� pair�� ����� ��� �׻� ����ġ�� first�� ��ġ�� ��!!! ****
	priority_queue<pair<int, int>> pq; // ����������� ó�� => O(ElogV)�� �ð����⵵�� ����
	pq.push(make_pair(0, start)); //	 second(��������)
	while (!pq.empty()) {
		int cur = pq.top().second; // ����	
		int dist = -pq.top().first; // �������� �Ÿ�, ª������ ���� ������ �� => �켱����ť�� ���� �����ͺ��� �������� ����
		pq.pop();
		if (d[cur] < dist) continue; // �ִܰŸ��� �ƴ� ��� ��ŵ
		for (int i = 0; i < a[cur].size(); i++) {
			int next = a[cur][i].first; // ���� ����, ���õ� ����� ���� ���
			int nextdist = dist + a[cur][i].second; // ���� �������� �Ÿ�, ������带 ���ļ� ���� ���
			if (nextdist < d[next]) { // ���� �Ÿ� ���� �� ������ ��ü
				d[next] = nextdist;
				pq.push(make_pair(-nextdist, next));
			}
		}
	}
}

void init() {
	cin >> v >> e >> start;
	for (int i = 1; i <= v; i++) {
		d[i] = INF; // INF�ʱ�ȭ => �������� ����ġ�� 10������ �ڿ����̹Ƿ�
	}
	for (int i = 0; i < e; i++) {
		int u, vv, w;
		cin >> u >> vv >> w;
		a[u].push_back(make_pair(vv, w));
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	init();
	dijkstra();
	
	// �� ���
	for (int i = 1; i <= v; i++) {
		if (d[i] == INF)
			cout << "INF" << "\n";
		else
			cout << d[i] << "\n";
	}
	return 0;
}