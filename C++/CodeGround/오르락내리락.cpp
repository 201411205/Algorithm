// �׸��� �˰��� => �ð��ʰ� ���� �ذ� 0.5��
// �׽�Ʈ���̽����� �ʱ�ȭ�� �ʿ� ���� => �̹� ����� ���� ����Ͽ� �ð� ����
// d[3] = d[4] + 1 => 3�� �˱����ؼ��� 4�� 1�� ����� Ƚ���� �˾ƾ� ��

#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

int d[MAX]; // �� �ε��� ������ 1�� ����� Ƚ��
int sum[MAX]; // �ε��� ���ڱ��� 1�� ����� Ƚ���� �� ��

int main(int argc, char** argv) {
	freopen("Text.txt", "r", stdin);
	int T, test_case;
	d[1] = 0; 
	sum[1] = 0; 
	int ix = 2; // �� �׽�Ʈ���̽� ���� �ε����� �����ϴ� ���� => �ð������� ����
	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		int n1, n2;
		cin >> n1 >> n2;
		if (d[n2] != 0) { // ���� �̹� ������ ����� ���� ���� �����ϸ� �ٷ� ���
			cout << "Case #" << test_case + 1 << "\n";
			cout << sum[n2] - sum[n1 - 1] << "\n";
			continue;
		}
		int end = 0; // for���� ���� ����
		int start = 0; // for���� �������� ����
		if (n2 % 2 != 0) { // ���� n2�� Ȧ���� ¦���� 1�� ���� ¦���� ���� => ������ �ش� Ȧ���� ���� ���Ϸ��� 1�� ���� ¦������ �ʿ�
			end = n2 + 1;
		}
		else {
			end = n2;
		}
		if (d[n1] != 0) { // ���� ������ n1�� ���� ���� ������ ���
			if (n1 % 2 != 0) { // n1�� Ȧ���̸� �������� n1 + 1���� ����
				start = n1 + 1;
			}
			else { // n1�� ¦���̸� �������� n1���� ����
				start = n1;
			}
		}
		else { // ������ ����� ���� �������� ������ ���� �׽�Ʈ���̽����� ����� ���� ���������� ����
			start = ix;
		}

		for (int i = start; i <= end; i += 2) {
			if (d[i] == 0) { // ���� ����Ѱ��� �������� ������
				d[i] = d[i / 2] + 1; // ¦�� ���
				if (i != 2) {
					d[i - 1] = d[i] + 1; // Ȧ�� ���
				}
				sum[i] = sum[i - 2] + d[i] + d[i - 1]; // ¦���� ���� �� ���
				sum[i - 1] = sum[i - 2] + d[i - 1]; // Ȧ���� ���� �� ���
			}
		}
		ix = end; // �׽�Ʈ���̽��� ������ �ε����� ������ => �ð� ����
		cout << "Case #" << test_case + 1 << "\n";
		cout << sum[n2] - sum[n1 - 1] << "\n";
	}
}


// �ð��ʰ� 1�ʸ� �ѱ�
/*#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

int Answer;
int d[MAX];

int main(int argc, char** argv)
{
	freopen("Text.txt", "r", stdin);
	int T, test_case;
	d[1] = 0;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		int n1, n2;
		cin >> n1 >> n2;
		if (d[n2] != 0) {
			for (int i = n1; i <= n2; i++) {
				Answer += d[i];
			}
			cout << "Case #" << test_case + 1 << "\n";
			cout << Answer << "\n";
			continue;
		}
		int end = 0;
		int start = 0;
		if (n2 % 2 != 0) {
			end = n2 + 1;
		}
		else {
			end = n2;
		}
		if (d[n1] != 0) {
			if (n1 % 2 != 0) {
				start = n1 + 1;
			}
			else {
				start = n1;
			}
		}
		else {
			start = 2;
		}

		for (int i = start; i <= end; i += 2) {
			if (d[i] == 0) {
				d[i] = d[i / 2] + 1;
				if (i != 2) d[i - 1] = d[i] + 1;
			}
		}
		for (int i = n1; i <= n2; i++) {
			Answer += d[i];
		}
		cout << "Case #" << test_case + 1 << "\n";
		cout << Answer << "\n";
	}
	return 0;
}*/
