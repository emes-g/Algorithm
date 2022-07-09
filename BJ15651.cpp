#include <iostream>
using namespace std;
int num[8];

// 시간복잡도 : O(N^M)

void BT(int level, int n, int m) {
	if (level == m + 1) {
		for (int i = 1; i <= m; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		num[level] = i;
		BT(level + 1, n, m);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	BT(1, n, m);
	return 0;
}