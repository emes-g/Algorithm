#include <iostream>
using namespace std;
int a[12], num[6];

// 시간복잡도 : O(2^k)

void BT(int level, int index, int k) {
	if (level == 6) {
		for (int i = 0; i < 6; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}
	else if (index >= k) {
		return;
	}
	num[level] = a[index];
	BT(level + 1, index + 1, k);
	num[level] = 0;
	BT(level, index + 1, k);
}

int main() {
	while (true) {
		int k;
		cin >> k;
		if (k == 0) {
			break;
		}
		for (int i = 0; i < k; i++) {
			cin >> a[i];
		}
		BT(0, 0, k);
		cout << '\n';
	}
	return 0;
}
