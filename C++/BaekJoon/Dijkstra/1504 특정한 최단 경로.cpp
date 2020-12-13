// ���⼺�� ���� �׷����� ���, Ư���� ������ �׻� �����ľ��ϴ� ����
// �׺���̼� ������ �߰��� �� �˰��� v1, v2�� ��������
#include <bits/stdc++.h>

#define E_MAX 200001
#define N_MAX 801
#define INF 987654321

using namespace std;

int n, e;
vector<pair<int, int>> v[E_MAX];
int d[N_MAX];
int v1, v2;

void dijkstra(int start) {
	d[start] = 0; // �ڱ��ڽ�
	priority_queue<pair<int, int>> pq; // first �Ÿ� second ��������
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int cur = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		if (d[cur] < dist) continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nextdist = dist + v[cur][i].second;
			if (nextdist < d[next]) {
				d[next] = nextdist;
				pq.push(make_pair(-nextdist, next));
			}
		}
	}
}

void input() {
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c)); // ����� �׷��� �̹Ƿ�
	}
	cin >> v1 >> v2;
}

void init() {
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	init();
	dijkstra(1); // ������ 1���� �� ������ �ִܰŸ� ���
	
	bool flag1, flag2; // �������� �� �� �ִ��� �Ǵ�
	flag1 = flag2 = true;

	// route1 => ���������κ��� v1�� ���� ������ v2�� ���� �������� ���� ��Ʈ
	// route2 => ���������κ��� v2�� ���� ������ v1�� ���� �������� ���� ��Ʈ

	int route1 = d[v1]; // ������ 1���� v1������ �ִܰŸ�
	int route2 = d[v2]; // ������ 1���� v2������ �ִܰŸ�
	if (route1 == INF)
		flag1 = false;
	if (route2 == INF)
		flag2 = false;
	
	init(); // �ִܰŸ� �ʱ�ȭ
	dijkstra(v1); // ������ v1���κ��� v2������ �ִܰŸ� ����� ���� => �����׷����̹Ƿ� ������ v2�� ���X
	if (flag1 == true)
		route1 = route1 + d[v2];
	if (flag2 == true)
		route2 = route2 + d[v2];

	init();
	dijkstra(v2); // v2���� ������(N)������ �ִܰŸ� ���
	if (flag1 == true)
		route1 = route1 + d[n];

	init();
	dijkstra(v1); // v1���� ������(N)������ �ִܰŸ� ���
	if (flag2 == true)
		route2 = route2 + d[n];

	if (flag1 == false && flag2 == false)
		cout << -1;
	else {
		if (min(route1, route2) == INF)
			cout << -1;
		else
			cout << min(route1, route2);
	}
}