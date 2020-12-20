#include <bits/stdc++.h>
using namespace std;

void map_base() {
	// map
	// key���� �ߺ�������� ����
	// [] �����ڸ� ����� �� ���� => ex) mp[1] = 2


	// map���� ������ key�� ī��Ʈ
	map<string, int> mp;
	mp["a"]++;

	// �ݺ���
	for (auto i : mp) {
		cout << i.first << " " << i.second << "\n";
	}

	// map value�� vector�� ���ִ� ���
	map<string, vector<pair<int, int>>> mpv;
	mpv["a"].push_back(make_pair(1, 2));
}

void multimap_base() {
	// multimap
	// map�� �ߺ����Ҹ� ����Ͽ� ��� => ���� key�� �ߺ��ؼ� ��밡��
	// [] �����ڸ� �������� ���� => ex) mm[1] = 2 (X)
	// �׻� ������ �Ǹ鼭 ����
	// pair��ü�� ����Ͽ� key, value�� ����

	// ����
	multimap<int, int> mm;

	// insert
	mm.insert(pair<int, int>(1, 2));
	mm.insert({ 1,3 });
	mm.insert(make_pair(2, 4));

	// count
	// �� Ű�� �ش��ϴ� value ������ ���� ��
	cout << mm.count(1) << "\n";

	// �������� �������� ���� ���� => �⺻������ ��������
	multimap<int, string, greater<int>> mmg; // => �������� ����

	// �ݺ���
	for (auto i : mm) { // foreach ���
		cout << i.first << " " << i.second << "\n";
	}
	for (auto it = mm.begin(); it != mm.end(); ++it) { // �ݺ��� ���
		cout << (*it).first << " " << (*it).second << "\n";
	}

	// multimap ����
	multimap<int, int> mm2(mm);

	// multimap �ݺ��� ����
	multimap<int, int>::iterator iter;

	
	// lower_bound(key) => key ���� �ش��ϴ� �� ù��°���Ҹ� ����Ű�� �ݺ��� ��ȯ, ������ "["
	// upper_bound(key) => key ���� �ش��ϴ� �� ������������ ������ ����Ű�� �ݺ��� ��ȯ, �󱸰� ")"
	// �ߺ� Ű ���� �����ϴ� Ű1 �� ���� ���
	for (auto it = mm.lower_bound(1); it != mm.upper_bound(1); it++) {
		cout << (*it).first << " " << (*it).second << "\n";
	}

	// equal_range(key)
	// key ���� �ش��ϴ� ������ ������ pair ��ü�� ��ȯ
	// first => lower_bound, second => upper_bound
	for (auto it = mm.equal_range(1).first; it != mm.equal_range(1).second; it++) {
		cout << it -> first << " " << it -> second << "\n";
	}

	// �ش� Ű�� ��ü ����
	mm.erase(1);

	// �ߺ��� Ű���� Ư����  value �� ����
	for (auto it = mm.equal_range(1).first; it != mm.equal_range(1).second; it++) {
		if (it->second == 3) { // key ���� 1�̸鼭 value�� 3�� �� ����
			mm.erase(it);
			break;
		}
	}

}

void unordered_map_base() {
	// unordered_map�� ������ ���� �ʰ� ��� �ٴ� ���� map�� �ٸ����̴�.
	// �����Ͱ� �۴ٸ� unordered_map�� �� ������ ����
	// �����Ͱ� ũ�ٸ� map�� �� ������ ���� => �ʿ信 ���� ����
	unordered_map<int, int> um;
}