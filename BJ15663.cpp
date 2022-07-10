#include <iostream>
#include <algorithm>
using namespace std;
bool check[8];
int num[8], input[8];

// [반례]
// 1.
// 3 3
// 3 4 3
// 2.
// 5 3
// 1 1 1 2 3

void BT(int level, int n, int m) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!check[i] && num[level] != input[i]) {
			check[i] = true;
			num[level] = input[i];
			BT(level + 1, n, m);
			check[i] = false;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);
	BT(0, n, m);
	return 0;
}