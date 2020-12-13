// �������� dfs ���� 
// dfs�� ����Ͽ� �ִ��� ���� ���� ������

#include <bits/stdc++.h>
using namespace std;

int t;
int a[4][4];

int ax[] = { -1,1,0,0 };
int ay[] = { 0,0,-1,1 };

set<int> st; // �ϰ��ڸ����� ��� �ڷᱸ��, set�� �ߺ��� ������� �ʰ� �ڵ����� ���ĵ�

void dfs(int i, int j, int depth, int n) {
	if (depth == 7) {
		st.insert(n);
		return;
	}
	n = n * 10;
	n += a[i][j]; // ���ο� ���ڸ� �����ڸ����� �������

	if (i - 1 >= 0) // dfs�� � ��ǥ���� 4���� �������� �̵��ϴ� ���
		dfs(i - 1, j, depth + 1, n);
	if (i + 1 < 4)
		dfs(i + 1, j, depth + 1, n);
	if (j - 1 >= 0)
		dfs(i, j - 1, depth + 1, n);
	if (j + 1 < 4)
		dfs(i, j + 1, depth + 1, n);
}

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for(int k = 1; k <= t; k++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> a[i][j];
			}
		}
		st.clear();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				dfs(i, j, 0, 0);
			}
		}
		cout << "#" << k << " " << st.size() << "\n";

	}
	return 0;
}