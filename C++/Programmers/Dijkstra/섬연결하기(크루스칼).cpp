// ũ�罺Į �˰����� ����Ͽ� Ǯ��
// ũ�罺Į �˰��� : ���� ���� ������� ��� ��带 ����
// �ּ� ��� ���� Ʈ���� ����� ���� ��ǥ���� �˰���
// �������� ���ø� ���η� ������ �� ����� �ּ������� �ϰ��� �� �� ���
// ��ǥ�� �ִ��� ���� ������� ��带 ���Ḹ ��Ű�� ��
// ����� ���� ��ŭ�� ����� �θ� ��� �迭�� �ʿ� => ó���� �� ���� �ʱ�ȭ
// �־��� ��� ���� ������ ������������ ����
// ������ �������� �׷��� ���� => �ּ� ��� ���� Ʈ���� �������
// ���Խ�Ű�� ������ ����Ŭ�� Ȯ�� => ����Ŭ�� �����ϴ� ��� ������ �������� ����

#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;
vector<vector<int>> a(5, vector<int>(3, 0));

// �θ��带 ������ ��
int getParent(int x) {
	if (v[x] == x) return x;
	return v[x] = getParent(v[x]);
}

// ���� �θ� �������� Ȯ��
int find(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return 1; // ����Ŭ�� �����Ѵ�.
	else return 0;
}

// �θ� ��带 ����
void unionParent(int a, int b) { 
	a = getParent(a);
	b = getParent(b);
	if (a < b) v[b] = a;
	else v[a] = b;
}

bool compare(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	// ������ ������� �������� ����
	sort(costs.begin(), costs.end(), compare);

	// �� ������ ���Ե� �׷����� ������� ����, �� ����� �θ��带 ����
	for (int i = 0; i < n; i++) {
		v.push_back(i);
	}
	for (int i = 0; i < costs.size(); i++) {
		// ������ �θ� ������ �ʴ� ��� => ��, ����Ŭ�� �߻����� ������ ����
		if (!find(costs[i][0], costs[i][1])) {
			answer += costs[i][2];
			unionParent(costs[i][0], costs[i][1]);
		}
	}
	return answer;
}

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	cout << solution(n, a);
}