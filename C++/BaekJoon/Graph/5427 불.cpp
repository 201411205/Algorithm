// ��, ����� ���ÿ� �̵��ϴµ� ���� ���� �ڸ��� ����� �̵��� �� ����
// ���� ���� �� �ε����� ���� �ٴ� �ð��� bfs�� �̿��Ͽ� �迭�� ����
// �׸����� ����� bfs�� �̿��Ͽ� �̵��ϸ� �ð��� ��
// � �ε����� ����� �̵��� �ð��� ���� ���� �ð����� ������ ��� ����� �� �ε����� �̵��� �� ����
// �̷��� �̵��ϸ� ������ �̵��Ҷ� ���� ���
// ���� ���� ������ �̵��� ���� �ּ� �ð��� �ҿ��� ���̹Ƿ� �׶��� ���� ����
// bfs�� �� �� ����Ͽ� Ǫ�� ����
// ****

#include <bits/stdc++.h>
#define MAX 1001
#define INF 987654321
using namespace std;

int t, w, h;
char m[MAX][MAX]; // ����
bool check[MAX][MAX]; // ����� �� �ε����� �̵��ߴ��� Ȯ��
int fire[MAX][MAX]; // ���� �ٴ� �ð�

int ax[] = { -1,1,0,0 };
int ay[] = { 0,0,-1,1 };

typedef struct person{
	int x;
	int y;
	int time; // ����� �̵��� �ð�
};

void init(int w, int h) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			fire[i][j] = INF;
		}
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> w >> h;
		pair<int, int> start; // ������
		queue<pair<int, int>> q; // ���� ��ġ
		memset(check, false, sizeof(check));
		init(w, h); 
		int answer = -1; // �ʱ�ȭ

		for (int i = 0; i < h; i++) { // input
			for (int j = 0; j < w; j++) {
				cin >> m[i][j];
				if (m[i][j] == '@') { // ����� �������� ��
					start.first = i;
					start.second = j;
				}
				if (m[i][j] == '*') { // �� ���� ó�� �������� ��
					q.push(make_pair(i, j)); 
					fire[i][j] = 0;
				}
			}
		}
		
		while (!q.empty()) { // bfs
			int curx = q.front().first;
			int cury = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = curx + ax[i];
				int ny = cury + ay[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (m[nx][ny] != '#') {
					if (fire[nx][ny] > fire[curx][cury] + 1) {
						fire[nx][ny] = fire[curx][cury] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}

		check[start.first][start.second] = true; // �������� �ʱ�ȭ
		queue<person> pq;
		pq.push({ start.first, start.second, 0 });
		while (!pq.empty()) { // bfs
			int cx = pq.front().x;
			int cy = pq.front().y;
			int ct = pq.front().time;
			pq.pop();

			if (cx == 0 || cy == 0 || cx == h - 1 || cy == w - 1) { // ������ �ε����� �������� ��� 
				answer = ct + 1;
				break;
			}	

			for (int i = 0; i < 4; i++) {
				int nx = cx + ax[i];
				int ny = cy + ay[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (m[nx][ny] == '.' && check[nx][ny] == false) {
					if (fire[nx][ny] > ct + 1) { // ����� �Һ��� �� ��ġ�� �� ���� �������� �� => �̵�����
						check[nx][ny] = true;
						pq.push({ nx, ny, ct + 1 });
					}
				}	
			}
		}
		if (answer == -1)
			cout << "IMPOSSIBLE" << "\n";
		else
			cout << answer << "\n";
	}
}