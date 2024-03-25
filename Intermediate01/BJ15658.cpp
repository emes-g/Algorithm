#include <iostream>
using namespace std;
const int MAX = 1000000000;
const int MIN = -1000000000;
int n, num[11];
pair<int, int> ans = { MIN,MAX };

void go(int index, int res, int a, int s, int m, int d) {
	if (index == n) {
		ans.first = max(ans.first, res);
		ans.second = min(ans.second, res);
		return;
	}
	if (a) {
		go(index + 1, res + num[index], a - 1, s, m, d);
	}
	if (s) {
		go(index + 1, res - num[index], a, s - 1, m, d);
	}
	if (m) {
		go(index + 1, res * num[index], a, s, m - 1, d);
	}
	if (d) {
		go(index + 1, res / num[index], a, s, m, d - 1);
	}
}

int main() {
	// 1. input
	int op[4];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	// 2. solve
	go(1, num[0], op[0], op[1], op[2], op[3]);

	// 3. output
	cout << ans.first << '\n';
	cout << ans.second;
}