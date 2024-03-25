#include <iostream>
using namespace std;
int num[8];

// 시간복잡도 O(2^N) (추정)

void BT(int level, int index, int n, int m) {
	if (level == m + 1) {
		for (int i = 1; i <= m; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}
	else if (index > n) {
		return;
	}
	num[level] = index;
	BT(level + 1, index, n, m);
	num[level] = 0;
	BT(level, index + 1, n, m);
}

int main() {
	int n, m;
	cin >> n >> m;
	BT(1, 1, n, m);
	return 0;
}