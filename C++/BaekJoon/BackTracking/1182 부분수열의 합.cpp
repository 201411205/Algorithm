// ��ǥ���� ��Ʈ��ŷ ����
// ��Ʈ��ŷ ������ �ٷ� �ذ�å�� �����ϱ�� ���� ����
// ���� DPó�� ���� ���ø� �־�� ��Ģ�� ã�ƾ� ��
// 5 0
// -7 - 3 - 2 5 8


#include <bits/stdc++.h>
using namespace std;

int n, s;
int a[21];
int cnt;

void dfs(int i, int sum) {
	if (i == n)
		return;
	sum += a[i];

	if (sum == s) {
		cnt++;
	}
	dfs(i + 1, sum); // -7-3 = -10 ���� ã��
	dfs(i + 1, sum - a[i]); // -7 => -3 ���� ã��

}

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dfs(0, 0);
	cout << cnt;
}