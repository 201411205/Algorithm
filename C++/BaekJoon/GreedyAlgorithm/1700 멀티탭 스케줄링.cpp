// �� ��ģ �׸��� �˰��� ���� ���� ���ذ�

#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int n, k;
int a[MAX];

int main() {
	freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}

	int answer = 0;
	set<int> st; // ��Ƽ��
	st.insert(a[0]);
	for (int i = 1; i < k; i++) {
		if (st.size() < n) { // �ڸ��� ����ִ� ���
			st.insert(a[i]);
		}
		else { // �ڸ��� �� �� �ִ� ���
			if (st.find(a[i]) != st.end()) { // �̹� �����ִ°��
				continue;
			}
			else { // ���ο� �� �Ⱦƾ��ϴ� ���
				multiset<int> ms;
				for (int j = i + 1; j < k; j++) { 
					ms.insert(a[j]);
				}
				int val = 0;	
				int min = 101;
				for (auto it = st.begin(); it != st.end(); it++) { 
					if (min > ms.count(*it)) { // i ���� �ڿ� �ִ� �͵� �߿��� ������ ���� ���� ���� �� ����
						min = ms.count(*it);
						val = *it;
					}
				}
				st.erase(val);
				st.insert(a[i]);
				answer++;
				unordered_set<int> us;

			}
		}
	}
	cout << answer;
}