// string�� cin���� �׳� �Է� ������ ���鹮�ڴ� �Է� ���� �� ����
// ���鹮�ڸ� �����Ͽ� string�� �Է¹����� getline(cin, str)�� ����Ͽ� �޾ƾ���

#include <bits/stdc++.h>
using namespace std;

string t, f;

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	getline(cin, t); // ���鹮�ڸ� �����Ͽ� �Է¹ޱ� ����
	getline(cin, f);

	string str = "";
	int answer = 0;
	for (int i = 0; i < t.size(); i++) {
		if (str.size() == f.size()) {
			if (str == f) {
				str.clear();
				answer++;
				str += t[i];
			}
			else {
				str = str.substr(1, str.size());
				str += t[i];
			}
		}
		else {
			str += t[i];
		}
	}
	if (str == f)
		answer++;
	cout << answer;
}