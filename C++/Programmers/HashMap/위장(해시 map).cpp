// map Ȱ�� ����

#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> mp;
	for (int i = 0; i < clothes.size(); i++) { // �� key������ ī��Ʈ
		mp[clothes[i][1]]++;
	}
	for (auto i : mp) { // �ش� �� ������ �� �Դ� ��츦 �߰�
		answer *= (i.second + 1);
	}
	return answer - 1; // ��� �� ������ �� �Դ� ��츦 �� => ��� �� ���� �ϳ��� �Ծ�� �ϹǷ�
}
