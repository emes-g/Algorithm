#include <iostream>
#include <algorithm>
using namespace std;
bool check[9];
int num[9], input[9];

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
	num[level] = input[index];
	BT(level + 1, index + 1, n, m);
	num[level] = 0;
	BT(level, index + 1, n, m);
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}
	sort(input + 1, input + n + 1);
	BT(1, 1, n, m);
	return 0;
}