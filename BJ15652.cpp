#include <iostream>
using namespace std;
int num[8];

// 시간복잡도 : O(N^N)

void BT(int level, int start, int n, int m) {
	if (level == m + 1) {
		for (int i = 1; i <= m; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; i++) {
		num[level] = i;
		BT(level + 1, i, n, m);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	BT(1, 1, n, m);
	return 0;
}