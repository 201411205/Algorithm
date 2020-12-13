#include <iostream>
#include <vector>
using namespace std;
#define MAX 9
int n, m;
bool check[MAX];
vector<int> v;

void dfs(int k) { // k�� v�� ������ Ȯ���ϴ� ����
	if (k == m + 1) {
		for (auto i : v) {
			cout << i << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == true) continue;
		check[i] = true;
		v.push_back(i);
		dfs(k + 1);
		v.pop_back();
		check[i] = false;
	}
}

int main() {
	freopen("Text.txt", "r", stdin);
	cin >> n >> m;
	dfs(1);
	return 0;
}