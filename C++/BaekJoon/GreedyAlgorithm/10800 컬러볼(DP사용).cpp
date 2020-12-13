// �׸��� �˰��� ���� n�������� Ǯ���� ��� �ð��ʰ� �߻�
// ���̳��� ���α׷��ֱ���� ����ؾ߸� Ǯ �� ����
// ***

#include <bits/stdc++.h>
#define MAX 200001
using namespace std;
int n;

typedef struct ball{
	int num; // ó�� ���� ��ġ
	int color;
	int size;
};

ball b[MAX];
int d[MAX]; // ���� ������ ���� ������ ũ�� ���� ����

bool compare(ball b1, ball b2) {
	if (b1.size == b2.size)
		return b1.color < b2.color;
	return b1.size < b2.size;
}

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> b[i].color >> b[i].size;
		b[i].num = i;
	}

	sort(b, b + n, compare); // �� ũ�� ������ �������� ����, ũ�Ⱑ ������ �÷� ������ �������� ����
	
	vector<int> a(n); // ���� �� ��ġ������ ũ�� ���� ����
	int sum = 0; // �� ũ���� �� ��
	int j = 0; // �ٸ� �������� ���� ũ�⸦ ���� ���� ������ ���� ��� ó���� ����
	for (int i = 0; i < n; i++) {
		while (b[j].size < b[i].size) { // �ݺ����� ���鼭 ���� �� ũ�⺸�� ���� ������ ���
			sum += b[j].size;
			d[b[j].color] += b[j].size;
			j++;
		}
		a[b[i].num] = sum - d[b[i].color];
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << "\n";
	}
}

/*typedef struct ball {
	int color;
	int size;
	int num;
	int sum;
};

ball b[MAX];
int n;

bool compare1(ball b1, ball b2) {
	return b1.size > b2.size;
}

bool compare2(ball b1, ball b2) {
	return b1.num < b2.num;
}

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b[i].color >> b[i].size;
		b[i].num = i + 1;
	}
	sort(b, b + n, compare1);
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = i + 1; j < n; j++) {
			if (b[i].color == b[j].color) {
				continue;
			}
			count += b[j].size;
		}
		b[i].sum = count;
	}
	sort(b, b + n, compare2);
	for (int i = 0; i < n; i++) {
		cout << b[i].sum << "\n";
	}
}*/

/*pair<int, int> p[MAX];

bool compare(pair<int, int> p1, pair<int, int> p2) {
	return p1.second > p2.second;
}

int main() { // n�������� Ǯ���� ��� �ð��ʰ�
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		p[i] = make_pair(a, b);
	}
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (p[i].first == p[j].first) {
				continue;
			}
			if (p[i].second > p[j].second) {
				count += p[j].second;
			}
		}
		cout << count << "\n";
	}
}*/