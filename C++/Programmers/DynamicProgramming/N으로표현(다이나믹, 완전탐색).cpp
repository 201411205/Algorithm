// ����Ž�� Ǯ��

#include <bits/stdc++.h>
#define MAX 32001
using namespace std;

int d[MAX]; // d[n] : n�� ǥ���ϱ� ���� N���Ƚ���� �ּڰ�
vector<unordered_set<int>> vs(9); // Ƚ���� N�� ����Ͽ� ��Ÿ���� �ִ� ���� set���� ���� => unordered_set�� ����Ͽ� �ӵ� ���

class op { // ����� ���� Ŭ����
private:
	int x;
	int y;

public:
	op(int _x, int _y) {
		x = _x;
		y = _y;
	}

	int plus() {
		return x + y;
	}

	int sub() {
		return x - y;
	}

	int mul() {
		return x * y;
	}

	int div() {
		return x / y;
	}

	int backsub() {
		return y - x;
	}

	int backdiv() {
		return y / x;
	}
};

int sol(int n, int num) {
	memset(d, -1, sizeof(d));
	d[0] = 2;
	d[n] = 1;
	vs[1].insert(n);
	for (int k = 2; k <= 8; k++) {
		for (int i = 1; i <= vs.size(); i++) {
			if (i > k - i) break;
			for (auto &j : vs[i]) {
				for (auto &t : vs[k - i]) {
					op o = op(j, t);
					int plus = o.plus(), mul = o.mul(), sub = o.sub(), div = o.div();
					if (sub <= 0) sub = o.backsub();
					if (div < 1) div = o.backdiv();

					if (d[plus] == -1) d[plus] = k;
					else d[plus] = min(d[plus], k);
					if (d[sub] == -1) d[sub] = k;
					else d[sub] = min(d[sub], k);
					if (mul < MAX) {
						if (d[mul] == -1) d[mul] = k;
						else d[mul] = min(d[mul], k);
						vs[k].insert(mul);
					}		
					if (d[div] == -1) d[div] = k;
					else d[div] = min(d[div], k);

					if (d[num] != -1) {
						return d[num];
					}

					vs[k].insert(plus);		
					vs[k].insert(div);
					if (sub != 0)
						vs[k].insert(sub);
				}
			}
		}
		if (k == 5 && n > 2 || k > 5) continue;
		int c = 0;
		for (int i = 1; i <= k; i++) { // 55, 555, 5555 �� ����� �ϱ� ����
			c += (int)pow(10, i - 1) * n;
		}
		d[c] = k;
		vs[k].insert(c);
	}
	return d[num];
}

int main() {
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << sol(5, 31168);
}

// ���, dp �޸������̼��� ����� �ڵ�

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int N;
unordered_set<int> cache[10]; // Ƚ���� N�� ����Ͽ� ��Ÿ���� �ִ� ���� set���� ����
unordered_set<int> solve(int n) {
	if (!cache[n].empty()) return cache[n]; // �޸������̼� => �̹� ���� �κ��� ��ŵ
	int num = 0;
	for (int i = 0; i < n; i++) num = 10 * num + N;
	unordered_set<int> res;
	res.insert(num);
	for (int i = 1; i < n; i++) {
		int j = n - i;
		auto s1 = solve(i);
		auto s2 = solve(j);
		for (int n1 : s1) {
			for (int n2 : s2) {
				res.insert(n1 + n2);
				res.insert(n1 - n2);
				res.insert(n1 * n2);
				if (n2 != 0) res.insert(n1 / n2);
			}
		}
	}
	return cache[n] = res;
}

int solution(int _N, int number) {
	N = _N;
	for (int i = 1; i <= 8; i++) {
		solve(i);
		if (cache[i].find(number) != cache[i].end()) return i;
	}
	return -1;
}