#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	answer.push_back(0);
	answer.push_back(0);
	vector<string> str;
	vector<string>::iterator it;
	int count = 1;
	int a[11] = { 0 };
	char c = words[0][words[0].size() - 1];
	str.push_back(words[0]);
	a[count] = 1;
	for (int i = 1; i <= words.size(); i++) {
		count++;
		if (count > n)
			count = 1;
		a[count]++;
		if (c == words[i][0]) { // �����ձ� ����
			it = find(str.begin(), str.end(), words[i]);
			if (it == str.end()) { // ���� �ܾ� �� ã��
				c = words[i][words[i].size() - 1];
				str.push_back(words[i]);
			}
			else { // ���� �ܾ� ã��
				answer.clear();
				answer.push_back(count);
				answer.push_back(a[count]);
				return answer;
			}
		}
		else { // �����ձ� �Ұ���
			answer.clear();
			answer.push_back(count);
			answer.push_back(a[count]);
			return answer;
		}
	}
	return answer;
}

/*int main() {
int n = 3;
vector<string> v;
v.push_back("hello");
v.push_back("one");
v.push_back("even");
v.push_back("never");
v.push_back("now");
v.push_back("world");
v.push_back("draw");
vector<int> a;
a = solution(n, v);
for (int i = 0; i < a.size(); i++)
cout << a[i] << endl;
return 0;
}*/