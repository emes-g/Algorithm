#include <iostream>
#include <vector>
using namespace std;

int main() {
	// 1. �Է� �� �ִ� ã��
	int n, cnt = 0, max = 0;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		if (max < num[i]) {
			max = num[i];
		}
	}

	// 2. �����佺�׳׽�
	bool check[1001];
	fill_n(check, 1001, true);
	for (int i = 2; i * i <= max; i++) {
		if (check[i]) {
			for (int j = i * i; j <= max; j += i) {
				check[j] = false;
			}
		}
	}

	// 3. �Ҽ� ���� ���
	for (int i = 0; i < n; i++) {
		if (num[i] < 2) {
			continue;
		}
		if (check[num[i]]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}