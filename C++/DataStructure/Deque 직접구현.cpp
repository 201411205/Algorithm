#include <bits/stdc++.h>
using namespace std;

// ���� ť�� �޸� ���ʿ��� ��� ���� ������ �ֱ� ������
// head�� tail�� �ʱⰪ�� MX�� �ΰ� �迭�� ũ�⸦ MX*2 + 1�� �д�
// ���� �������� Ȯ���� �� �ְ� �Ѵ�
// *** ���� �ε����� ������ �����ϴ� ***

const int MX = 1000005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x) {
	dat[--head] = x;
}

void push_back(int x) {
	dat[tail++] = x;
}

void pop_front() {
	head++;
}

void pop_back() {
	tail--;
}

int front() {
	return dat[head];
}

int back() {
	return dat[tail - 1];
}