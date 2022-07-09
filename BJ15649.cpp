#include <iostream>
using namespace std;
bool check[9];
int num[9];

// 시간복잡도 : O(N!) (순서 문제)

void BT(int level, int n, int m) {
	if (level == m + 1) {
		for (int i = 1; i <= m; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			check[i] = true;
			num[level] = i;
			BT(level + 1, n, m);
			check[i] = false;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	BT(1, n, m);
	return 0;
}
