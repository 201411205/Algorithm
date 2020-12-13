#include <bits/stdc++.h>
using namespace std;

bool compare2(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

bool compare1(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> mp; // �� �帣 �� ���Ƚ�� ������ ����ϱ� ����
	vector<pair<int, int>> p; // first : ���Ƚ��, second : ������ȣ
	for (int i = 0; i < genres.size(); i++) {
		mp[genres[i]] += plays[i];
		p.push_back(make_pair(plays[i], i));
	}
	vector<pair<string, int>> v; // first : �帣, second : ���Ƚ��
	for (auto i : mp) {
		v.push_back(make_pair(i.first, i.second));
	}
	sort(v.begin(), v.end(), compare1);
	sort(p.begin(), p.end(), compare2);
	for (int i = 0; i < v.size(); i++) {
		int count = 0; // �� �帣�� �뷡�� �� ���� �̱� ����
		for (int j = 0; j < p.size(); j++) {
			if (count == 2) break;
			if (v[i].first == genres[p[j].second]) {
				answer.push_back(p[j].second);
				count++;
			}
		}
	}
	return answer;
}