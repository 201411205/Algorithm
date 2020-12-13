// �������� �ùķ��̼� ����
// �ùķ��̼� ������ �ϳ��ϳ� ������ ���󰡸鼭 ������Ű���

#include <bits/stdc++.h>
#define MAX 51
using namespace std;

typedef struct robot {
	int r;
	int c;
	int d;
};

int n, m;
robot rb;
int a[MAX][MAX];
queue<pair<int, int>> q;

int ax[] = { 0, -1, 0, 1 }; // ���ʹ������ ���� ������
int ay[] = { -1, 0, 1, 0 };
int dx[] = { 3, 0, 1, 2}; // �κ��� �����ִ� ���⿡�� ���ʿ� ��ġ�� ���� �ε����� ����

// �κ��� ������ ���
int rx[] = { 1, 0, -1, 0 };
int ry[] = { 0, -1, 0, 1 };

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> rb.r >> rb.c >> rb.d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int count = 0; // û���� ���� ����
	q.push({ rb.r, rb.c });
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		a[curx][cury] = 2; // û���� ���� ǥ��
		count++;
		q.pop();
		int ct = 0; // ȸ��Ƚ�� ���
		while (1) {
			if (ct == 4) { // ������ �ؾ� �Ǵ� ���
				curx = curx + rx[rb.d];
				cury = cury + ry[rb.d];
				if (a[curx][cury] == 1) { // �����ؾ��ϴ� ������ ���� ���� ��� ����
					cout << count;
					return 0;
				}
				else {
					ct = 0;
				}
			}
			int nx = curx + ax[rb.d]; // �κ��� �����ִ� ������ ���� Ž��
			int ny = cury + ay[rb.d];
			if (a[nx][ny] == 0) { // ���ʹ��⿡ û������ ���� ������ �����ϸ�
				rb = { nx, ny, dx[rb.d] }; // �� �������� �̵�
				q.push({ rb.r, rb.c });
				break;
			}
			else { // ���ʹ��⿡ û���� ������ ���ٸ�
				rb.d = dx[rb.d];
				ct++;
			}
		}
	}
}