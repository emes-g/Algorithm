#include <iostream>
#include <algorithm>
using namespace std;
int num[8], input[8];

void BT(int level, int n, int m) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int prev = 0;
	for (int i = 0; i < n; i++) {
		if (prev != input[i]) {
			prev = num[level] = input[i];
			BT(level + 1, n, m);
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