#include <bits/stdc++.h>
using namespace std;

struct customOrder { // Ŀ���� ������ �ϱ����� ����ü ����
	bool operator() (const pair<int, int> &left, const pair<int, int> &right) const {
		if (left.first == right.first) { // first�� ������ second �������� ����
			return left.second < right.second;
		}
		return left.first > right.first; // first �������� ����
	}
};

void set_base() {
	// set�� ��� ����� ���� ����Ʈ���� ����
	// key�� �Ҹ��� ���ҵ��� ����
	// key���� �ߺ��� ������ ����
	// insert�� ���� ���� ���ԵǸ� �ڵ����� ���ĵ�(�⺻������ ��������)

	set<int> st;
	set<int, greater<int>> stt; // �������� ����
	set<pair<int, int>, customOrder> stc; // Ŀ���� ����

	// insert
	st.insert(1);
	st.insert(2);

	// count
	st.count(1); // ���� 1�� ������ ���� ��� => �׳� set�̹Ƿ� �׻� 0 �ƴϸ� 1�� ���

	// erase
	for (auto it = st.begin(); it != st.end(); it++) {
		st.erase(it);
	}
	
	// find
	set<int>::iterator it = st.find(1);
	if (it != st.end()) { // set�ȿ� 1�� ����ִٸ�
	}

	// set �ݺ���
	// 1. for-each
	for (auto &i : st) {
		cout << i << "\n";
	}
	// 2. iterator ���
	for (auto it = st.begin(); it != st.end(); it++) {
		cout << *it << "\n";
	}
}

void multiset_base() {
	// set�� ��������� key�� �ߺ��� ���ȴٴ� ���� ū ������
	// insert�� ����Ͽ� ���� �����ϸ� �ڵ����� ����
	multiset<int> mt;
}

void unordered_set_base() {
	// set�� ��������� �ڵ����� ������ ���� ����
	// �ؽ����̺��� ���
	// ������ ����/������ ��������� O(1)�� �ð����� ����������
	// �־��� ��� O(N)���� ����Ǵ� ��찡 �־�
	// �����Ͱ� ������� ����ϸ� ������ set���� ����
	unordered_set<int> us;
}